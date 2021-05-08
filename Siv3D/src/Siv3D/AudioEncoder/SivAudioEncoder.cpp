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

# include <Siv3D/AudioEncoder.hpp>
# include <Siv3D/Wave.hpp>
# include <Siv3D/AudioFormat.hpp>
# include "IAudioEncoder.hpp"
# include <Siv3D/Common/Siv3DEngine.hpp>
# include <Siv3D/FileSystem.hpp>

namespace s3d
{
	namespace detail
	{
		[[nodiscard]]
		constexpr StringView ToString(const AudioFormat imageFormat) noexcept
		{
			switch (imageFormat)
			{
			case AudioFormat::WAVE:
				return U"WAVE"_sv;
			case AudioFormat::MP3:
				return U"MP3"_sv;
			case AudioFormat::AAC:
				return U"AAC"_sv;
			case AudioFormat::OggVorbis:
				return U"OggVorbis"_sv;
			case AudioFormat::Opus:
				return U"Opus"_sv;
			default:
				return U""_sv;
			}
		}
	}

	namespace AudioEncoder
	{
		bool Save(const Wave& wave, AudioFormat format, const FilePathView path)
		{
			if (not wave)
			{
				return false;
			}

			String encoderName;

			if (format == AudioFormat::Unspecified)
			{
				encoderName = SIV3D_ENGINE(AudioEncoder)->getEncoderNameFromExtension(FileSystem::Extension(path));
			}
			else
			{
				encoderName = detail::ToString(format);
			}

			return Save(wave, encoderName, path);
		}

		bool Save(const Wave& wave, const String& encoderName, const FilePathView path)
		{
			return SIV3D_ENGINE(AudioEncoder)->save(wave, encoderName, path);
		}

		bool Encode(const Wave& wave, const AudioFormat format, IWriter& writer)
		{
			return Encode(wave, String(detail::ToString(format)), writer);
		}

		bool Encode(const Wave& wave, const String& encoderName, IWriter& writer)
		{
			return SIV3D_ENGINE(AudioEncoder)->encode(wave, encoderName, writer);
		}

		Blob Encode(const Wave& wave, const AudioFormat format)
		{
			return Encode(wave, String(detail::ToString(format)));
		}

		Blob Encode(const Wave& wave, const String& encoderName)
		{
			return SIV3D_ENGINE(AudioEncoder)->encode(wave, encoderName);
		}

		bool Add(std::unique_ptr<IAudioEncoder>&& Encoder)
		{
			return SIV3D_ENGINE(AudioEncoder)->add(std::move(Encoder));
		}

		void Remove(const StringView name)
		{
			return SIV3D_ENGINE(AudioEncoder)->remove(name);
		}

		const Array<std::unique_ptr<IAudioEncoder>>& Enum()
		{
			return SIV3D_ENGINE(AudioEncoder)->enumEncoder();
		}
	}
}
