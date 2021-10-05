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
    
    // now����old��������
    std::map<MouseID, std::pair<bool, bool>> mouseMap_;
    // ID�ɑΉ�����Dxlib�̃}�E�X�C���v�b�g�ۑ�
    std::map<MouseID, int> IDMap_;
};

