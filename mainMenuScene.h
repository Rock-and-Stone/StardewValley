#pragma once
#include "gameNode.h"
#include "UserInterface.h"

struct tagSelect
{
    RECT rc[4];
    image* img[4];
    float x[4];
    float y[4];
    bool isPlay[4];
};
class mainMenuScene :
    public gameNode
{
private:
    tagSelect _select;
    UserInterface* _ui;
  

public:
    virtual HRESULT init();
    virtual void release();
    virtual void update();
    virtual void render();
};

