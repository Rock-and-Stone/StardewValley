#pragma once
#include "gameNode.h"
#include "Clock.h"
#include "MouseSetting.h"
class entity;

class UserInterface :
    public gameNode
{
private:
    Clock*          _clock;
    MouseSetting*   _mouse;
    entity* _player;
    //µ· ¼¼¾îº¾½Ã´Ù.
    image* _gold10000000;
    image* _gold1000000;
    image* _gold100000;
    image* _gold10000;
    image* _gold1000;
    image* _gold100;
    image* _gold10;
    image* _gold1;
  

public:
    UserInterface();
    ~UserInterface();
    virtual HRESULT init();
    virtual void release();
    virtual void update();
    virtual void render();

    void SetMemoryAddressLink(entity* pl) { _player = pl; }
};

