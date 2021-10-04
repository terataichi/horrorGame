#pragma once
#include <string>
#include <vector>

#include "../Common/Vector3.h"
#include "../Object/BaseObject.h"

// ���f�����ێ��N���X
// ���[�h�͊֐��Ă��
class Model :
	public BaseObject
{
public:
	Model(Vector3f pos, Vector3f angle, Vector3f scale, Vector3f localAngle);
	~Model();

	bool Init(void)override;
	bool Update(void)override;
	void Draw(void)override;

	/// <summary>
	/// ���f���ǂݍ���
	/// </summary>
	/// <param name="str">Resource/Model/ �ȍ~�̃p�X</param>
	/// <returns>false : ���s</returns>
	bool LoadModel(std::string str);
	/// <summary>
	/// �A�j���[�V����������ꍇ
	/// </summary>
	/// <returns>false : ���s</returns>
	bool LoadModelAndAnimation(std::string str);

	/// <summary>
	/// ---- Get,Set
	/// </summary>
	const Vector3f& LocalAngle(void)const;
	void LocalAngle(Vector3f& angle);

private:

	// ���f���ǂݍ��ݗp
	int modelHandle_;
	// �A�j���[�V�����ǂݍ��ݗp
	std::vector<int>animHandleVec_;
	// �A�j���[�V�����̍Đ����ԋL�^�p
	float animToralTime_;
	// ���̃A�j���[�V�����̎���
	float animStepTime_;
	// �A�j���[�V�����̑��x
	float animSpeed_;

	Vector3f localAngle_;

};

