#include "WorldTransformEx.h"

using namespace KamataEngine;
using namespace KamataEngine::MathUtility;

// Scale, Rotation, Tranlate 行列から World行列を計算
// そして定数バッファへの転送も行う
void WorldTransformEx::UpDateMatrix() {
	// World変換行列を計算し、matWorld_ に格納する
	matWorld_ = MakeAffinMatrix();
	// 定数バッファへ転送する
	TransferMatrix();
}

KamataEngine::Matrix4x4 WorldTransformEx::MakeAffinMatrix() { 
	// Scale Matrix
	Matrix4x4 matScale = MakeScaleMatrix(scale_);

	// Rotation Matrix
	Matrix4x4 matRotX = MakeRotateXMatrix(rotation_.x);
	Matrix4x4 matRotY = MakeRotateYMatrix(rotation_.y);
	Matrix4x4 matRotZ = MakeRotateZMatrix(rotation_.z);
	Matrix4x4 matRot = matRotZ * matRotX * matRotY;

	// Translete Matrix
	Matrix4x4 matTrans = MakeTranslateMatrix(translation_);

	// World Matrix
	Matrix4x4 matWorld = matScale * matRot * matTrans;

	return matWorld;
}
