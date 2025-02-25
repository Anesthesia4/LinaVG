/*
This file is a part of: LinaVG
https://github.com/inanevin/LinaVG

Author: Inan Evin
http://www.inanevin.com

The 2-Clause BSD License

Copyright (c) [2022-] Inan Evin

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice, this
	  list of conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright notice,
	  this list of conditions and the following disclaimer in the documentation
	  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#pragma once

// Headers here.
#include "LinaVG/LinaVG.hpp"

namespace LinaVG::Examples
{
	class ShaderData
	{
	public:
		BackendHandle							 m_handle = 0;
		LINAVG_MAP<LINAVG_STRING, BackendHandle> m_uniformMap;
	};

	struct BackendData
	{
		BackendHandle m_vbo = 0;
		BackendHandle m_vao = 0;
		BackendHandle m_ebo = 0;
		ShaderData	  m_defaultShaderData;
		ShaderData	  m_gradientShaderData;
		ShaderData	  m_texturedShaderData;
		ShaderData	  m_sdfTextShaderData;
		ShaderData	  m_simpleTextShaderData;
		float		  m_proj[4][4]				  = {0};
		const char*	  m_defaultVtxShader		  = nullptr;
		const char*	  m_defaultFragShader		  = nullptr;
		const char*	  m_roundedGradientFragShader = nullptr;
		const char*	  m_texturedFragShader		  = nullptr;
		const char*	  m_sdfTextFragShader		  = nullptr;
		const char*	  m_simpleTextFragShader	  = nullptr;
		bool		  m_skipDraw				  = false;
	};

	class GLBackend
	{
	public:
		GLBackend();
		virtual ~GLBackend() = default;

		struct GLState
		{
			bool m_blendEnabled		  = false;
			bool m_cullFaceEnabled	  = false;
			bool m_stencilTestEnabled = false;
			bool m_depthTestEnabled	  = false;
			bool m_scissorTestEnabled = false;
			bool m_depthMaskEnabled	  = false;
			int	 m_blendEq			  = 0;
			int	 m_blendSrcAlpha	  = 0;
			int	 m_blendSrcRGB		  = 0;
			int	 m_blendDestAlpha	  = 0;
			int	 m_blendDestRGB		  = 0;
			int	 m_unpackAlignment	  = 0;
		};

		void		  StartFrame();
		void		  DrawGradient(GradientDrawBuffer* buf);
		void		  DrawTextured(TextureDrawBuffer* buf);
		void		  DrawDefault(DrawBuffer* buf);
		void		  DrawSimpleText(SimpleTextDrawBuffer* buf);
		void		  DrawSDFText(SDFTextDrawBuffer* buf);
		void		  EndFrame();
		void		  SaveAPIState();
		void		  RestoreAPIState();
        void OnAtlasUpdate(Atlas* atlas);

		static unsigned int s_displayPosX;
		static unsigned int s_displayPosY;
		static unsigned int s_displayWidth;
		static unsigned int s_displayHeight;

	private:
		void SetScissors(BackendHandle x, BackendHandle y, BackendHandle width, BackendHandle height);
		void AddShaderUniforms(ShaderData& data);
		void CreateShader(ShaderData& data, const char* vert, const char* frag);
        void CreateFontTexture(unsigned int width, unsigned int height);
        
	private:
		GLState		m_glState;
		BackendData m_backendData;
        uint32_t m_fontTexture = 0;
        bool m_fontTextureCreated = false;
	};

} // namespace LinaVG::Examples
