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

# pragma once
# include <Siv3D/Common.hpp>
# include <Siv3D/Audio.hpp>

namespace s3d
{
	class SIV3D_NOVTABLE ISiv3DAudio
	{
	public:

		static ISiv3DAudio* Create();

		virtual ~ISiv3DAudio() = default;

		virtual void init() = 0;

		virtual Audio::IDType create(Wave&& wave, const Optional<AudioLoopTiming>& loop) = 0;

		virtual Audio::IDType create(Wave&& wave, const Duration& loopBegin, const Duration& loopEnd) = 0;

		virtual Audio::IDType createStreamingNonLoop(FilePathView path) = 0;

		virtual Audio::IDType createStreamingLoop(FilePathView path, uint64 loopBegin) = 0;

		virtual void release(Audio::IDType handleID) = 0;
	};
}
