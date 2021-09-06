#include "pch.h"
#include "object.h"

object::object()
{
}

object::~object()
{
}

HRESULT object::init(ALLOBJECTS obj, const char* imageName,int framex,int framey, POINT pos)
{
    _obj = obj;
    _objectImg = IMAGEMANAGER->findImage(imageName);
    _posX = pos.x;
    _posY = pos.y;
    _frameX = framex;
    _frameY = framey;
    
    _speed = RND->getFromFloatTo(-10, 10);

    return S_OK;
}

HRESULT object::init()
{
    return S_OK;
}



void object::release()
{
}

void object::update()
{
    _posX -= _speed;
    _posY -= _speed;

    if (_speed > 0.5) _speed -= 0.49;
    else if (_speed < -0.5) _speed += 0.49;
    else _speed = 0;
}

void object::render()
{
    Draw();
}

void object::itemSetup()
{
}

void object::Draw()
{
    _objectRc = RectMakeCenter(_posX, _posY, _objectImg->getFrameWidth(), _objectImg->getFrameHeight());
    _objectImg->frameRender(getMemDC(), _objectRc.left, _objectRc.top, _frameX, _frameY);



}
