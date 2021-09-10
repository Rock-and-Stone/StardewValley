#include "pch.h"
#include "itemIron.h"

HRESULT itemIron::init()
{
	_item.items = IRON;
	_item.itemImg = IMAGEMANAGER->findImage("ores");
	_item.frameX = 8;
	_item.frameY = 4;
	_item.itemName = "√∂";
	_item.itemInfo = "¥‹¥‹«— .. √∂¿Ã¥Ÿ";
	_item.buyPrice = 30;
	_item.sellPrice = 15;
	_item.damage = 10;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = true;
	_item.itemNum = 10;
	//_item.amount = 1;
	_item.itemNum = 16;
    return S_OK;
}

void itemIron::release()
{
}

void itemIron::update()
{
}

void itemIron::render(int x, int y)
{
	item::render(x, y);
}
