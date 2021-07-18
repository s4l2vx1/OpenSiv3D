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

# include "CModel.hpp"
# include <Siv3D/Error.hpp>
# include <Siv3D/EngineLog.hpp>

namespace s3d
{
	CModel::CModel()
	{
		// do nothing
	}

	CModel::~CModel()
	{
		LOG_SCOPED_TRACE(U"CModel::~CModel()");

		m_models.destroy();
	}

	void CModel::init()
	{
		LOG_SCOPED_TRACE(U"CModel::init()");

		// null Model を管理に登録
		{
			// null Model を作成
			auto nullModel = std::make_unique<ModelData>();

			if (not nullModel->isInitialized()) // もし作成に失敗していたら
			{
				throw EngineError{ U"Null Model initialization failed" };
			}

			// 管理に登録
			m_models.setNullData(std::move(nullModel));
		}
	}

	Model::IDType CModel::create(const FilePathView path)
	{
		auto model = std::make_unique<ModelData>(path);

		if (not model->isInitialized())
		{
			return Model::IDType::NullAsset();
		}

		return m_models.add(std::move(model), U"");
	}

	void CModel::release(const Model::IDType handleID)
	{
		m_models.erase(handleID);
	}
}
