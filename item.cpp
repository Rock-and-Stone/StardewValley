#include "pch.h"
#include "item.h"

item::item()
{
}

item::~item()
{
}

HRESULT item::init()
{
    return S_OK;
}

void item::release()
{
}

void item::update()
{
}

void item::render(int x, int y)
{
    _item.itemImg->frameRender(getMemDC(), x, y, _item.frameX, _item.frameY);
}


