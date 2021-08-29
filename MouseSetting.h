#pragma once
#include "gameNode.h"
class MouseSetting :
    public gameNode
{
private:
    image*  _mouse; //마우스 이미지
    RECT    _rc;    //마우스 렉트
    int _frameX, _frameY; //마우스 프레임 X,Y

public:
    MouseSetting();
    ~MouseSetting();
    virtual HRESULT init();
    virtual void release();
    virtual void update();
    virtual void render();
};

