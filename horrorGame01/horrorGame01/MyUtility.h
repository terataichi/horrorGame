#pragma once
#include <DxLib.h>

#include "Common/Vector3.h"

static class MyUtility
{
public:
	// VECTORに変換する
	static VECTOR VGet(const Vector3f& vec);

	// 度数方からラジアン
	static float DegToRad(float deg);
	// ラジアンから度数
	static float RadToDeg(float rad);
};