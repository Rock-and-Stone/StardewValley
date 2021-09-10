#include "pch.h"
#include "itemTuna.h"

HRESULT itemTuna::init()
{
	_item.items = TUNA;
	_item.itemImg = IMAGEMANAGER->findImage("springObjects");
	_item.frameX = 19;
	_item.frameY = 5;
	_item.itemName = "참치"; 
	_item.itemInfo = "통조림으로 될 운명.... ";
	_item.buyPrice = 0;
	_item.sellPrice = 900;
	_item.damage = 10;
	_item.hP = 200;
	_item.sP = 80;
	_item.isEatAble = true;
	_item.isHandleAble = false;
	//_item.amount = 1;
	_item.itemNum = 13;
    return S_OK;
}

void itemTuna::release()
{
}

void itemTuna::update()
{
}

void itemTuna::render(int x, int y)
{
	item::render(x, y);
}
