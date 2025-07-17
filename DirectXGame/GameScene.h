#pragma once
#include "WorldTransformEx.h"

class GameScene {
	struct ObjectInstance {
		KamataEngine::Model* model = nullptr;
		WorldTransformEx* worldTransform = nullptr;
	};

public:

	void Initialize();

	void Update();

	void Draw();

	void Finalize();

private:
	KamataEngine::Camera camera_;

	std::vector<ObjectInstance> instances_;

};
