﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2021 Ryo Suzuki
//	Copyright (c) 2016-2021 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# include <Siv3D/EngineOptions.hpp>
# include <Siv3D/Shader/Null/CShader_Null.hpp>
# include <Siv3D/Shader/GL4/CShader_GL4.hpp>

namespace s3d
{
	ISiv3DShader* ISiv3DShader::Create()
	{
		if (g_engineOptions.renderer == EngineOption::Renderer::Headless)
		{
			return new CShader_Null;
		}
		else if (g_engineOptions.renderer == EngineOption::Renderer::PlatformDefault
			|| g_engineOptions.renderer == EngineOption::Renderer::OpenGL)
		{
			return new CShader_GL4;
		}
		else
		{
			return new CShader_Null;
		}
	}
}
