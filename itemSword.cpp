#include "pch.h"
#include "itemSword.h"

HRESULT itemSword::init()
{
	_item.items = SWORD;
	_item.itemImg = IMAGEMANAGER->findImage("springObjects");
	_item.frameX = 13;
	_item.frameY = 4;
	_item.itemName = "검";
	_item.itemInfo = "몬스터를 해치울수 있다!";
	_item.buyPrice = 1080;
	_item.sellPrice = 540;
	_item.damage = 20;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = true;
	//_item.amount = 1;
	_item.itemNum = 28;
    return S_OK;
}

void itemSword::release()
{
}

void itemSword::update()
{
}

void itemSword::render(int x, int y)
{
	item::render(x, y);
}
