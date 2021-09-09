#include "pch.h"
#include "itemGold.h"

HRESULT itemGold::init()
{
	_item.items = GOLD;
	_item.itemImg = IMAGEMANAGER->findImage("ores");
	_item.frameX = 12;
	_item.frameY = 4;
	_item.itemName = "±Ý";
	_item.itemInfo = "±Ý..ºñ½Î´Ù..";
	_item.buyPrice = 300;
	_item.sellPrice = 150;
	_item.damage = 0;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = false;
	//_item.amount = 1;
	_item.itemNum = 15;
	return S_OK;
}

void itemGold::release()
{
}

void itemGold::update()
{
}

void itemGold::render(int x, int y)
{
	item::render(x, y);
}
