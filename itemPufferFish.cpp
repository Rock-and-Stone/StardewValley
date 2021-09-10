#include "pch.h"
#include "itemPufferFish.h"

HRESULT itemPufferFish::init()
{
	_item.items = PUFFERFISH;
	_item.itemImg = IMAGEMANAGER->findImage("springObjects");
	_item.frameX = 8;
	_item.frameY = 5;
	_item.itemName = "뽂어";
	_item.itemInfo = "생으로 먹으면 치명적인 독으로 사망할 수 있다. 반드시 전문가에 팔도록....";
	_item.buyPrice = 0;
	_item.sellPrice = 500;
	_item.damage = 10;
	_item.hP = -200;
	_item.sP = -200;
	_item.isEatAble = true;
	_item.isHandleAble = false;
	//_item.amount = 1;
	_item.itemNum = 12;
    return S_OK;
}

void itemPufferFish::release()
{
}

void itemPufferFish::update()
{
}

void itemPufferFish::render(int x, int y)
{
	item::render(x, y);
}
