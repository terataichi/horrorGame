#include "Model.h"
#include <DxLib.h>
#include <cassert>

#include "../_debug/_DebugConOut.h"
#include "../MyUtility.h"

Model::Model(Vector3f pos, Vector3f angle, Vector3f scale, Vector3f localAngle)
	:pos_(pos),angle_(angle),scale_(scale),localAngle_(localAngle)
{
	Init();
}

Model::~Model()
{
}

bool Model::LoadModel(std::string str)
{
	std::string modelPath= "Resource/Model/";
	modelHandle_ = MV1LoadModel((modelPath + str).c_str());

	if (modelHandle_ == -1)
	{
		TRACE("モデルの読み込み失敗 : %s \n", str.c_str());
		return false;
	}

	auto angle = angle_;
	angle.x_ += localAngle_.x_;
	angle.y_+= localAngle_.y_;
	angle.z_+= localAngle_.z_;

	MV1SetRotationXYZ(modelHandle_, MyUtility::VGet(angle));
	MV1SetPosition(modelHandle_, MyUtility::VGet(pos_));

	TRACE("モデルの読み込み成功 : %s \n", str.c_str());
	return true;
}

bool Model::LoadModelAndAnimation(std::string str)
{
	if (!LoadModel(str))
	{
		TRACE("LoadModelAndAnimation\n");
		assert(!"モデル読み込み失敗");
		return false;
	}

	// アニメーションがある分読み込む
	int i = 0;
	int tmpHandle;
	tmpHandle = MV1AttachAnim(modelHandle_, i);
	while (tmpHandle != -1)
	{
		animHandleVec_.emplace_back(tmpHandle);
		animToralTime_ = MV1GetAttachAnimTotalTime(modelHandle_, animHandleVec_[i]);

		i++;
		tmpHandle = MV1AttachAnim(modelHandle_, i);
	}

	if (i == 0)
	{
		TRACE("アニメーションなし : %s \n", str.c_str());
		return false;
	}

	// モデルにアニメーションを適用する
	MV1SetAttachAnimTime(modelHandle_, animHandleVec_[0], animStepTime_);

	TRACE("アニメーション読み込み成功 : %dつ読み込みました \n", static_cast<int>(animHandleVec_.size() - 1));
	return true;
}

const Vector3f& Model::LocalAngle(void) const
{
	return localAngle_;
}

void Model::LocalAngle(Vector3f& angle)
{
	localAngle_ = angle;
}

bool Model::Init(void)
{
	animToralTime_ = -1;
	animStepTime_ = -1;
	animSpeed_ = 0;
	modelHandle_ = 0;
	return true;
}

bool Model::Update(void)
{
	return false;
}

void Model::Draw(void)
{
	auto angle = angle_;
	angle.x_ += localAngle_.x_;
	angle.y_ += localAngle_.y_;
	angle.z_ += localAngle_.z_;
	MV1SetRotationXYZ(modelHandle_, MyUtility::VGet(angle));
	MV1SetPosition(modelHandle_, MyUtility::VGet(pos_));

	MV1DrawModel(modelHandle_);
}
