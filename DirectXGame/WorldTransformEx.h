#pragma once
#include "KamataEngine.h"
class WorldTransformEx : 
	public KamataEngine::WorldTransform {

public:
	// Affine変換行列の生成と定数バッファへの転送を行う
	void UpDateMatrix();

	// Affine変換行列の生成
	KamataEngine::Matrix4x4 MakeAffinMatrix();
};
