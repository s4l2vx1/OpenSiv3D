# pragma once

# include "AsyncTask.hpp"
# include "FileSystem.hpp"
# include "System.hpp"

# if SIV3D_PLATFORM(WEB)
namespace s3d::Platform::Web
{
	/// @brief ファイルシステム上のデータをIndexedDB上に保存するための関数群を提供します。
	/// @note この機能を利用するにはリンクオプションに `-lidbfs.js` を追加してください。
	namespace IndexedDB
	{
		/// @brief 指定されたパス以下をIndexedDBの同期対象に設定し、既にデータが存在する場合には非同期でロードします。
		inline AsyncTask<bool> InitAsync(FilePathView path);

		/// @brief 指定されたパス以下をIndexedDBの同期対象に設定し、既にデータが存在する場合にはロードします。
		inline bool Init(FilePathView path);

		/// @brief 指定されたパス以下をIndexedDBの同期対象に設定し、既にデータが存在する場合には非同期でロードします。
		inline AsyncTask<bool> InitAsync(std::initializer_list<FilePathView> path);

		/// @brief 指定されたパス以下をIndexedDBの同期対象に設定し、既にデータが存在する場合にはロードします。
		inline bool Init(std::initializer_list<FilePathView> paths);

		/// @brief 現在のファイルの内容をIndexedDBに非同期で保存します。
		inline AsyncTask<bool> SaveAsync();

		/// @brief 現在のファイルの内容をIndexedDBに保存します。
		inline bool Save();
	}
}
# endif

# include "detail/IndexedDB.ipp"