#pragma once
#include "gameNode.h"
#include "Clock.h"
#include "MouseSetting.h"

class UserInterface :
    public gameNode
{
private:
    Clock*          _clock;
    MouseSetting*   _mouse;

public:
    UserInterface();
    ~UserInterface();
    virtual HRESULT init();
    virtual void release();
    virtual void update();
    virtual void render();
};

