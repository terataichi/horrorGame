#pragma once
#include <DxLib.h>

#include "Common/Vector3.h"

static class MyUtility
{
public:
	// VECTORに変換する
	static VECTOR VGet(const Vector3f& vec);
};