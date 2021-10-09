#pragma once
#include <DxLib.h>

#include "Common/Vector3.h"

static class MyUtility
{
public:
	// VECTOR�ɕϊ�����
	static VECTOR VGet(const Vector3f& vec);

	// �x�������烉�W�A��
	static float DegToRad(float deg);
	// ���W�A������x��
	static float RadToDeg(float rad);
	// 0(0)�`360�x�͈̔͂Ɏ��߂�
	static double RadIn2PI(float rad);
};