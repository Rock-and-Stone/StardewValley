#pragma once
#include "Enemy.h"
class RockStone :  public Enemy
{
private:

public:
    RockStone();
    ~RockStone();

    virtual HRESULT InitVariables();

    virtual void update();
    virtual void render();

    virtual void SwitchImage();
};

