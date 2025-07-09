#include "GameScene.h"
#include "KamataEngine.h"

#include <string>
#include <json.hpp>
#include <fstream>
#include <cassert>
#include <vector>

using namespace KamataEngine;

void GameScene::Initialize() {

	// -----------------------------------------------------
	//    レベルエディタを格納するための構造体
	// -----------------------------------------------------

	// オブジェクト 1個分のデータ
	struct ObjectData {
		std::string type;
		std::string name;

		// "transform"
		struct Transform {
			Vector3 translation;
			Vector3 rotation;
			Vector3 scaling;
		};

		Transform transform;


		// "file_name
		std::string file_name;
	};

	// レベルデータ
	struct LevelData {
		// "name"
		std::string name;

		// "objects"
		std::vector<ObjectData> objects;
	};

	// -----------------------------------------------------
	//    jsonファイルの デシリアライズ化
	// -----------------------------------------------------


	// jsonファイルのパス名
	const std::string fullpath = std::string("Resources/levels") + "scene.json";

	// ファイルストリーム
	std::ifstream file;

	// ファイルを開く
	file.open(fullpath);
	// ファイルオープン失敗チェック
	if (file.fail()) {
		assert(0);
	}

	nlohmann::json deserialized;

	// ファイルから読み込み、メモリへ格納
	file >> deserialized;

	// 正しいレベルデータファイルかチェック
	assert(deserialized.is_object());

	assert(deserialized.contains("name"));
	assert(deserialized["name"].is_string());

	// -----------------------------------------------------
	//    レベルデータを構造体に格納していく
	// -----------------------------------------------------
	
	LevelData* levelData = new LevelData();

	// "name"を文字列として取得
	levelData->name = deserialized["name"].get<std::string>();
	assert(levelData->name == "scene");

	// "object"の全オブジェクトを走査
	if (nlohmann::json & object : deserialized["object"]) {

		// オブジェクト 1つ分の妥当性のチェック
		assert(object.contains("type"));

		if (object["type"].get<std::string>() == "MESH") {

			// 1個分の要素の準備
			levelData->objects.emplace_back(ObjectData{});
			ObjectData& objectData = levelData->objects.back();

			objectData.type = object["type"].get<std::string>();
			objectData.name = object["name"].get<std::string>();

			// トランスフォームのパラメータ読み込み
			nlohmann::json& transform = object["transform"];
		}
	}

}

void GameScene::Update() {}

void GameScene::Draw() {}
