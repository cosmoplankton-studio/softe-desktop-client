/*
* ---------------------------------------------------------
* Copyright 2018 - present(c) Automatos Studios.All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			uiManager.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#include <array>

#include "uiNkEngine.h"
#include "uiManager.h"


namespace ui
{
    
    UiManager::UiManager(::ux::IUxManager* mgr)
        : p_mgr(mgr)
    {
        p_uiEngine = std::make_unique<NkEngine>();
    }


    UiManager::~UiManager()
    {}

    
    int UiManager::getGraphicsStageDescription(gc::StageDescription &uiStageDescription)
    {
        using namespace graphics_compute;

        uiStageDescription.setType(StageType::eUI);

        auto &uiVertexDescriptions = uiStageDescription.getDescriptions<device::DataDescription::eVertex>();
        auto &uiIndexDescriptions = uiStageDescription.getDescriptions<device::DataDescription::eIndex>();
        auto &uiUniformDescriptions = uiStageDescription.getDescriptions<device::DataDescription::eUniform>();
        auto &uiTextureDescriptions = uiStageDescription.getDescriptions<device::DataDescription::eTexture>();
        auto &uiRenderTargetDescriptions = uiStageDescription.getDescriptions<device::DataDescription::eRenderTarget>();
        auto &uiDrawDescriptions = uiStageDescription.getDescriptions<device::DataDescription::eDraw>();

        auto position = device::DataAttribute().setType(device::DataAttributeType::eVertexPosition).setFormat(device::DataFormat::eR32G32Float);
        auto uv = device::DataAttribute().setType(device::DataAttributeType::eVertexUV).setFormat(device::DataFormat::eR32G32Float);
        auto color = device::DataAttribute().setType(device::DataAttributeType::eVertexColor).setFormat(device::DataFormat::eR32G32B32A32Float);
        auto uiVertexDataDescription = StageBufferDataDescription()
            .setTag("ui_vertex")
            .setDataAccessQualifier(device::DataAccessQualifier::eHostToDevice)
            .setMaxCount(10000)
            .setDataUpdateScheme(DataUpdateScheme::eFrameDynamic)
            .setDataAttributes({ position, uv, color });
        uiVertexDescriptions["ui_vertex"] = uiVertexDataDescription;

        auto index = device::DataAttribute().setType(device::DataAttributeType::eVertexIndex).setFormat(device::DataFormat::eUint16);
        auto uiIndexDataDescription = StageBufferDataDescription()
            .setTag("ui_index")
            .setDataAccessQualifier(device::DataAccessQualifier::eHostToDevice)
            .setMaxCount(10000)
            .setDataUpdateScheme(DataUpdateScheme::eFrameDynamic)
            .setDataAttributes({ index });
        uiIndexDescriptions["ui_index"] = uiIndexDataDescription;

        auto ortho = device::DataAttribute().setType(device::DataAttributeType::eTransformMatrix).setFormat(device::DataFormat::eMAT4Float);
        auto uiProjMatrixDataDescription = StageBufferDataDescription()
            .setTag("ui_orthoprojection")
            .setDataAccessQualifier(device::DataAccessQualifier::eHostToDevice)
            .setMaxCount(1)
            .setDataUpdateScheme(DataUpdateScheme::eFrameDynamic)
            .setDataAttributes({ ortho });
        uiUniformDescriptions["ui_orthoprojection"] = uiProjMatrixDataDescription;

        auto uiFontTextureDescription = StageImageDataDescription()
            .setTag("ui_fonttexture")
            .setDataAccessQualifier(device::DataAccessQualifier::eHostToDevice)
            .setDataFormat(device::DataFormat::eA8)
            .setWidth(p_uiEngine->getFontInfo().texWidth)
            .setHeight(p_uiEngine->getFontInfo().texHeight);
        uiTextureDescriptions["ui_fonttexture"] = uiFontTextureDescription;

        auto uiRenderTargetDescription = StageRenderTargetDescription()
            .setTag("present")
            .setTargetType(RenderTargetType::ePresent)
            .setBindingIdx(0);
        uiRenderTargetDescriptions["present"] = uiRenderTargetDescription;

        auto uiShaderStages = StageShaderDescription()
            .setRawTextShadersFlag(false)
            .setShader(ShaderStage::eVertex, "D:/Development/GitHub/automatos-studios.github.io/softe-desktop-client/source/data/shaders/ui-vert.spv")
            .setShader(ShaderStage::eFragment, "D:/Development/GitHub/automatos-studios.github.io/softe-desktop-client/source/data/shaders/ui-frag.spv");/* #todo - appAssetManager */
        auto uiLayoutBinding_0 = StageLayoutBindingDescription()
            .setShaderStage(ShaderStage::eFragment)
            .setDataDescription(device::DataDescription::eTexture)
            .setDataTags({ uiFontTextureDescription.getTag() });
        auto uiLayoutBinding_1 = StageLayoutBindingDescription()
            .setShaderStage(ShaderStage::eVertex)
            .setDataDescription(device::DataDescription::eUniform)
            .setDataTags({ uiProjMatrixDataDescription.getTag() });

        auto &uiDrawDescription = uiDrawDescriptions["draw_primary"];
        uiDrawDescription.setTag("draw_primary")
            .setVertexTag(uiVertexDataDescription.getTag())
            .setIndexTag(uiIndexDataDescription.getTag())
            .setRenderTargetTags({ uiRenderTargetDescription.getTag() })
            .setShaderDescription(uiShaderStages)
            .setLayoutBindingDescription(0, uiLayoutBinding_0)
            .setLayoutBindingDescription(1, uiLayoutBinding_1);

        return 0;
    }


    void UiManager::processEvents(::ux::UxEventInfo eventInfo)
    {
        p_uiEngine->processEvents(eventInfo);
    }


    void UiManager::addComponentsToCanvas()
    {
        for (auto &pModeBar : p_modeBars)
        {
            p_uiEngine->addModeBarToCanvas(pModeBar.second);
        }

        for (auto &pToolBar : p_toolBars)
        {
            p_uiEngine->addToolBarToCanvas(pToolBar.second);
        }
    }

    
    void UiManager::writeToDeviceFrameVertexData()
    {
        void *vertData = nullptr, *indexData = nullptr;
        uint32_t vertSize = 0, indexSize = 0, projSize = 0, indexCount = 0, vertexCount = 0;
        DataHandle projData;
        
        getOrthoProjMatrix(projData, projSize);
        p_uiEngine->getVertexData(&vertData, vertSize, &indexData, indexSize, indexCount);
        {
            auto &uiStageIO = getUxManager()->getAppGraphicsPipeline()->stageIO(gc::StageType::eUI);
            auto &inputSlotVertex = uiStageIO.slotinput<device::DataDescription::eVertex>("ui_vertex");
            auto &inputSlotIndex = uiStageIO.slotinput<device::DataDescription::eIndex>("ui_index");
            auto &inputSlotUniform = uiStageIO.slotinput<device::DataDescription::eUniform>("ui_orthoprojection");
            auto &inputSlotDraw = uiStageIO.slotinput<device::DataDescription::eDraw>("draw_primary");

            std::array< uint32_t, 3 > drawInfo;
            drawInfo[0] = indexCount; // indexCount
            drawInfo[1] = 0; // indexFirst
            drawInfo[2] = 0; // indexVertexOffset
            inputSlotUniform->writeData(projData.get(), projSize);
            inputSlotVertex->writeData(vertData, vertSize);
            inputSlotIndex->writeData(indexData, indexSize);
            inputSlotDraw->writeData(drawInfo.data(), drawInfo.size() * sizeof(uint32_t));
        }
        p_uiEngine->freeVertexData();

    }


    void UiManager::writeToDeviceInitData()
    {
        auto inputSlotTexture = getUxManager()->getAppGraphicsPipeline()->stageIO(gc::StageType::eUI).slotinput<device::DataDescription::eTexture>("ui_fonttexture");
        inputSlotTexture->writeData(p_uiEngine->getFontInfo().fontTexPtr, 0);
    }

    
    void UiManager::getOrthoProjMatrix(DataHandle &projData, unsigned int &projSize)
    {
        projSize = 16 * sizeof(float);
        projData.reset(new float[16]);

        int appWidth = getUxManager()->getAppWidth();
        int appHeight = getUxManager()->getAppHeight();

        /* #todo - get this from a library */
        float ortho[4][4] = {
            { 2.0f, 0.0f, 0.0f, 0.0f },
            { 0.0f, 2.0f, 0.0f, 0.0f },
            { 0.0f, 0.0f,-1.0f, 0.0f },
            { -1.0f,-1.0f, 0.0f, 1.0f },
        };

        ortho[0][0] /= (float)appWidth;
        ortho[1][1] /= (float)appHeight;

        memcpy(projData.get(), &ortho[0][0], projSize);
    }


} // namespace ui