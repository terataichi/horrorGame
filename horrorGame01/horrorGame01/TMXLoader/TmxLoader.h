#pragma once
#include <map>
#include <string>
#include <list>
#include "../Common/Vector2.h"
#include "../Common/Vector3.h"

// rappidXml
#include "../RapidXml/rapidxml.hpp"
#include "../RapidXml/rapidxml_utils.hpp"

#define TMX_VERSION "1.4"

enum class DataType
{
	Item,
	Light,
	EnemyPoint,
	StartPoint,
};

// XMLに入っているデータ
struct ObjectData
{
	std::string type;
	std::string name;
	Vector3f pos;
	Vector3f angle;
	Vector3f scale;
};

using TypeDataMap = std::map<DataType, std::list<ObjectData>>;

class TmxLoader
{
public:
	TmxLoader();
	~TmxLoader();

	bool LoadTmx(std::string fileName);
	//rapidxml::xml_node<>& GetNode(std::string nodeName);
	std::string GetTmxFileName(void);

	TypeDataMap GetTypeData(void)const;

private:
	std::map<std::string, int>version_;
	//std::string version_;											// 現在のファイルのVersionを定義して格納しておく

	std::map<std::string, DataType> stoDataType_;					// ストリング変換機
	TypeDataMap typeData_;											// タイプ別にデータを格納

	std::string tmxFileName_;										// Tmxファイル名保存

	rapidxml::xml_document<> docment;
};

