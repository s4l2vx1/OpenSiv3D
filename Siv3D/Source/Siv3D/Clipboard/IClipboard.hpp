﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2017 Ryo Suzuki
//	Copyright (c) 2016-2017 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include <utility>
# include <Siv3D/Fwd.hpp>

namespace s3d
{
	class ISiv3DClipboard
	{
	public:

		static ISiv3DClipboard* Create();

		virtual ~ISiv3DClipboard() = default;

		virtual bool init() = 0;

		virtual void update() = 0;
	};
}
