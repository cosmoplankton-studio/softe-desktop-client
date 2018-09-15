/*
UI Fragment shader
*/

#version 420
#extension GL_ARB_separate_shader_objects : enable
#extension GL_ARB_shading_language_420pack : enable


layout (location = 0) in vec4 in_texcolor;
layout (location = 1) in vec2 in_uv;

layout (location = 0) out vec4 out_color;

layout (binding = 0) uniform usampler2D Texture;

void main()
{
	out_color = vec4(in_texcolor.xyz, texture(Texture, in_uv.xy).r);
}




