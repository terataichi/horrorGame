#include "TmxLoader.h"
#include <iostream>
#include <sstream>
#include <cassert>

TmxLoader::TmxLoader()
{
    version_.try_emplace("1.4", 1);
    version_.try_emplace("1.4.1", 1);
    version_.try_emplace("1.4.2", 1);
    version_.try_emplace("1.4.3", 1);
    version_.try_emplace("1.5", 1);

    stoDataType_.try_emplace("Item", DataType::Item);
    stoDataType_.try_emplace("EnemyPoint", DataType::EnemyPoint);
    stoDataType_.try_emplace("StartPoint", DataType::StartPoint);
    stoDataType_.try_emplace("Right", DataType::Light);

}

TmxLoader::~TmxLoader()
{
}

bool TmxLoader::LoadTmx(std::string fileName)
{
    rapidxml::file<> file(fileName.c_str());
    docment.parse<0>(file.data());

    rapidxml::xml_node<>* root_node;
    root_node = docment.first_node("TestData");

    tmxFileName_ = fileName;

    //  �~�����}�b�v���̊i�[
    for (rapidxml::xml_node<>* data_node = root_node->first_node("TestData");
        data_node != nullptr;
        data_node = data_node->next_sibling("TestData"))
    {
        ObjectData objData;

        // ��{���̊i�[
        objData.type = data_node->first_node("objType")->value();
        objData.name = data_node->first_node("objName")->value();

        objData.pos.x_ = atof(data_node->first_node("pos")->first_node("x")->value());
        objData.pos.y_ = atof(data_node->first_node("pos")->first_node("y")->value());
        objData.pos.z_ = atof(data_node->first_node("pos")->first_node("z")->value());

        objData.angle.x_ = atof(data_node->first_node("rota")->first_node("eulerAngles")->first_node("x")->value());
        objData.angle.y_ = atof(data_node->first_node("rota")->first_node("eulerAngles")->first_node("y")->value());
        objData.angle.z_ = atof(data_node->first_node("rota")->first_node("eulerAngles")->first_node("z")->value());

        objData.scale.x_ = atof(data_node->first_node("scale")->first_node("x")->value());
        objData.scale.y_ = atof(data_node->first_node("scale")->first_node("y")->value());
        objData.scale.z_ = atof(data_node->first_node("scale")->first_node("z")->value());

        if (stoDataType_.count(objData.type))
        {
            typeData_[stoDataType_[objData.type]].push_back(objData);
        }
    }

    return true;
}


std::string TmxLoader::GetTmxFileName(void)
{
    return tmxFileName_;
}

TypeDataMap TmxLoader::GetTypeData(void) const
{
    return typeData_;
}
