﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2020 Ryo Suzuki
//	Copyright (c) 2016-2020 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# include "GL4SamplerState.hpp"

namespace s3d
{
	namespace detail
	{
		static constexpr GLint minmipTable[4] =
		{
			GL_NEAREST_MIPMAP_NEAREST,
			GL_NEAREST_MIPMAP_LINEAR,
			GL_LINEAR_MIPMAP_NEAREST,
			GL_LINEAR_MIPMAP_LINEAR
		};
	}

	static const SamplerState NullSamplerState(TextureAddressMode::Repeat,
		TextureAddressMode::Repeat,
		TextureAddressMode::Repeat,
		TextureFilter::Linear,
		TextureFilter::Linear,
		TextureFilter::Linear,
		0,
		-1,
		Float4(FLT_MIN, FLT_MIN, FLT_MIN, FLT_MIN));

	GL4SamplerState::GL4SamplerState()
	{
		m_currentStates.fill(NullSamplerState);
	}

	void GL4SamplerState::setPS(const uint32 slot, const SamplerState& state)
	{
		assert(slot < SamplerState::MaxSamplerCount);

		if (state == m_currentStates[slot])
		{
			return;
		}

		auto it = m_states.find(state);

		if (it == m_states.end())
		{
			it = create(state);

			if (it == m_states.end())
			{
				return;
			}
		}

		::glBindSampler(slot, it->second->m_sampler);

		m_currentStates[slot] = state;
	}

	void GL4SamplerState::setPS(const uint32 slot, None_t)
	{
		assert(slot < SamplerState::MaxSamplerCount);

		::glBindSampler(slot, 0);

		m_currentStates[slot] = NullSamplerState;
	}

	GL4SamplerState::SamplerStateList::iterator GL4SamplerState::create(const SamplerState& state)
	{
		std::unique_ptr<SamplerState_GL> samplerState = std::make_unique<SamplerState_GL>();

		const GLuint sampler = samplerState->m_sampler;
		static const GLfloat border[] = { state.borderColor.x, state.borderColor.y, state.borderColor.z, state.borderColor.w };
		static const GLuint wraps[] = { GL_REPEAT, GL_MIRRORED_REPEAT, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER };

		::glSamplerParameteri(sampler, GL_TEXTURE_MIN_FILTER,
			detail::minmipTable[(static_cast<int32>(state.min) << 1) | (static_cast<int32>(state.mip))]);
		::glSamplerParameteri(sampler, GL_TEXTURE_MAG_FILTER, static_cast<bool>(state.mag) ? GL_LINEAR : GL_NEAREST);
		::glSamplerParameteri(sampler, GL_TEXTURE_WRAP_S, wraps[static_cast<int32>(state.addressU)]);
		::glSamplerParameteri(sampler, GL_TEXTURE_WRAP_T, wraps[static_cast<int32>(state.addressV)]);
		::glSamplerParameteri(sampler, GL_TEXTURE_WRAP_R, wraps[static_cast<int32>(state.addressW)]);
		::glSamplerParameterf(sampler, GL_TEXTURE_LOD_BIAS, state.lodBias);
		::glSamplerParameteri(sampler, GL_TEXTURE_COMPARE_MODE, GL_NONE);
		::glSamplerParameterf(sampler, GL_TEXTURE_MAX_ANISOTROPY_EXT, state.maxAnisotropy);
		::glSamplerParameterfv(sampler, GL_TEXTURE_BORDER_COLOR, border);
		::glSamplerParameterf(sampler, GL_TEXTURE_MIN_LOD, -1000.0f);
		::glSamplerParameterf(sampler, GL_TEXTURE_MAX_LOD, 1000.0f);

		if (m_states.size() >= 1024)
		{
			m_states.clear();
		}

		return m_states.emplace(state, std::move(samplerState)).first;
	}
}
