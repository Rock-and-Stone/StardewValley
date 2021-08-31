#include "pch.h"
#include "sickle.h"

HRESULT sickle::init()
{
    _item.items = SICKLE;
    _item.objectImg = IMAGEMANAGER->findImage("playerTool");
    _item.frameX = 2;
    _item.frameY = 0;
    _item.itemName = "낫";
    _item.itemInfo = "작물이나 풀등을 베어낼 수 있는 도구";
    _item.damage = 10;
    _item.hP = 0;
    _item.sP = 0;
    _item.price = 30;

    _item.isburiedAble = false;
	return S_OK;
}

void sickle::release()
{
}

void sickle::update()
{
}

void sickle::render()
{
}

void sickle::Draw()
{
}
