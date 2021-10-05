#pragma once
#include <DxLib.h>
#include <map>
#include <utility>
#include "../Common/Vector2.h"
#include "MouseID.h"


class Mouse
{
public:
    Mouse();
    ~Mouse();

    void Update(void);

    bool GetClick(MouseID&& id);
    bool GetClickPush(MouseID&& id);
    bool GetClickRelease(MouseID&& id);
    const Vector2& GetPotision(void) ;
private:
    Vector2 pos_;
    
    // now情報とold情報を入れる
    std::map<MouseID, std::pair<bool, bool>> mouseMap_;
    // IDに対応したDxlibのマウスインプット保存
    std::map<MouseID, int> IDMap_;
};

