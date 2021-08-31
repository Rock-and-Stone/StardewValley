#include "pch.h"
#include "can.h"

HRESULT can::init()
{
    _item.items = CAN;
    _item.objectImg = IMAGEMANAGER->findImage("playerTool");
    _item.frameX = 4;
    _item.frameY = 0;
    _item.itemName = "물 뿌리개";
    _item.itemInfo = "물을 담아 작물에 물을 줄 수있는 도구";
    _item.damage = 0;
    _item.hP = 0;
    _item.sP = 0;
    _item.price = 20;

    _item.isburiedAble = true;

	return S_OK;
}

void can::release()
{
}

void can::update()
{
}

void can::render()
{
}

void can::Draw()
{
}
