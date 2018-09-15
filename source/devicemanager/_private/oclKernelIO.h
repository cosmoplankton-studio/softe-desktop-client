/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclKernelIO.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef OPENCL_KERNELIO
#define OPENCL_KERNELIO

#include "oclDefines.h"


namespace opencl
{

	class ArgSlot
		: public compute::IArgSlot
	{
	public:
		ArgSlot(size_t idx, size_t nodeKey)
			: p_argIdx(idx)
			, p_execNodeKEY(nodeKey)
		{}

		friend class ExecutionManager;

		static Manager* getManager()
		{
			return s_MGR;
		}

		static inline void setGLock(bool lock)
		{
			s_globalLOCK = lock;
		}

		inline size_t getIdx()
		{
			return p_argIdx;
		}

		virtual int argSet(compute::ArgPayload const& payload) override;
		virtual int argBindBuffer(std::string const& bufferTag) override;
		virtual int argBindImage(std::string const& imageTag) override;

	protected:
		size_t p_argIdx;
		size_t p_execNodeKEY;

	private:
		static Manager* s_MGR;
		static bool s_globalLOCK;
	};


	class KernelSlot
		: public compute::IKernelSlot
	{
	public:
		virtual compute::ArgIO* getArgSlot(size_t argIdx) const override
		{
			return p_argIOs.at(argIdx).get();
		}

		virtual compute::ArgIO* getArgSlot(std::string const& argName) const override
		{
			return p_argIOs.at(p_argNameToIdx.at(argName)).get();
		}

		void addArgIO(std::string const& argName, compute::ArgIOHandle argio)
		{
			size_t idx = (reinterpret_cast<ArgSlot*>(argio->getImpl()))->getIdx();
			p_argIOs[idx] = argio;
			p_argNameToIdx[argName] = idx;
		}

	protected:
		std::map<size_t, compute::ArgIOHandle> p_argIOs;
		std::map<std::string, size_t> p_argNameToIdx;
	};


	class DispatchSlot
		: public compute::IDispatchSlot
	{
	public:

		virtual compute::KernelIO* getKernelIO(std::string const& kernelName, std::string const& kernelNamespace = "global") const override
		{
			size_t kernelKEY = GET_KERNELKEY(kernelName, kernelNamespace);
			return m_kernelIOs.at(kernelKEY).get();
		}

		void addKernelIO(size_t key, compute::KernelIOHandle handle)
		{
			m_kernelIOs[key] = handle;
		}

	protected:
		std::map<size_t, compute::KernelIOHandle> m_kernelIOs;
	};

}

#endif // !OPENCL_KERNELIO
