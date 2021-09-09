#include "pch.h"
#include "itemStone.h"

HRESULT itemStone::init()
{
	_item.items = STONE;
	_item.itemImg = IMAGEMANAGER->findImage("ores");
	_item.frameX = 2;
	_item.frameY = 0;
	_item.itemName = "µ¹";
	_item.itemInfo = "±×Àú ¶¥¹Ù´Ú¿¡ ±¼·¯´Ù´Ï´Â µ¹... ";
	_item.buyPrice = 0;
	_item.sellPrice = 5;
	_item.damage = 0;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = false;
	_item.itemNum = 1;

	//_item.amount = 1;
	return S_OK;
}

void itemStone::release()
{
}

void itemStone::update()
{
}

void itemStone::render(int x, int y)
{
	item::render(x, y);
}
