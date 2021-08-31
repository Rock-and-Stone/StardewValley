#include "pch.h"
#include "rod.h"

HRESULT rod::init()
{
    _item.items = ROD;
    _item.itemImg = IMAGEMANAGER->findImage("playerTool");
    _item.frameX = 5;
    _item.frameY = 0;
    _item.itemName = "³¬½Ã´ë";
    _item.itemInfo = "¹°°í±â¸¦ ³¬¾ÆÃ§¼ö ÀÖ´Â µµ±¸";
    _item.damage = 0;
    _item.hP = 0;
    _item.sP = 0;
    _item.price = 100;

    _item.isburiedAble = false;
    return S_OK;
}

void rod::release()
{
}

void rod::update()
{
}

void rod::render()
{
}

void rod::Draw()
{
}
