#pragma once
#include <map>
#include <string>
#include <list>
#include <DxLib.h>
#include "../Common/Vector2.h"

// rappidXml
#include "../RapidXml/rapidxml.hpp"
#include "../RapidXml/rapidxml_utils.hpp"

#define TMX_VERSION "1.4"

enum class DataType
{
	Object,
	Item,
	Right,
	EnemyPoint,
	StartPoint,
};

// XML�ɓ����Ă���f�[�^
struct ObjectData
{
	std::string type;
	std::string name;
	VECTOR pos;
	VECTOR angle;
	VECTOR scale;
};

class TmxLoader
{
public:
	TmxLoader();
	~TmxLoader();

	bool LoadTmx(std::string fileName);
	//rapidxml::xml_node<>& GetNode(std::string nodeName);
	std::string GetTmxFileName(void);
private:
	std::map<std::string, int>version_;
	//std::string version_;											// ���݂̃t�@�C����Version���`���Ċi�[���Ă���

	std::map<std::string, DataType> stoDataType_;					// �X�g�����O�ϊ��@
	std::map<DataType, std::list<ObjectData>>itemData_;				// �^�C�v�ʂɃf�[�^���i�[

	std::string tmxFileName_;										// Tmx�t�@�C�����ۑ�

	rapidxml::xml_document<> docment;
};

