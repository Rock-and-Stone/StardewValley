#include "pch.h"
#include "itemWood.h"

HRESULT itemWood::init()
{
	_item.items = WOOD;
	_item.itemImg = IMAGEMANAGER->findImage("springObjects");
	_item.frameX = 6;
	_item.frameY = 12;
	_item.itemName = "나무";
	_item.itemInfo = "자연을 보호합시다. ";
	_item.buyPrice = 0;
	_item.sellPrice = 90;
	_item.damage = 0;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = false;
	_item.itemNum = 2;
	//_item.amount = 1;
    return  S_OK;
}

void itemWood::release()
{
}

void itemWood::update()
{
}

void itemWood::render(int x, int y)
{
	item::render(x, y);
}
