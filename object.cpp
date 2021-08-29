#include "pch.h"
#include "object.h"

object::object()
{
}

object::~object()
{
}

HRESULT object::init()
{


    return S_OK;
}

HRESULT object::init(const char* imageName, POINT position, ALLITEMS items, ITEMTYPE itemTypes, int frameX, int frameY)
{
    _objectImg = IMAGEMANAGER->findImage(imageName);

    _posX = position.x;
    _posY = position.y;

    _items = items;
    _itemType = itemTypes;

    _frameX = frameX;
    _frameY = frameY;



    return S_OK;
}

void object::release()
{
}

void object::update()
{

}

void object::render()
{
    Draw();
}

void object::Draw()
{
    _rendX = _posX;
    _rendY = _posY;

    _objectRc = RectMake(_posX, _posY, _objectImg->getFrameWidth(), _objectImg->getFrameHeight());
    _objectImg->frameRender(getMemDC(), _objectRc.left, _objectRc.top, _frameX, _frameY);
}
