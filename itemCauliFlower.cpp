#include "pch.h"
#include "itemCauliFlower.h"

HRESULT itemCauliFlower::init()
{
	_item.items = CAULIFLOWER;
	_item.itemImg = IMAGEMANAGER->findImage("crops");
	_item.frameX = 1;
	_item.frameY = 0;
	_item.itemName = "콜리플라워";
	_item.itemInfo = "하얗게 생긴 브로콜리";
	_item.buyPrice = 0;
	_item.sellPrice = 350;
	_item.damage = 0;
	_item.hP = 195;
	_item.sP = 87;
	_item.isEatAble = true;
	_item.isHandleAble = false;
	//_item.amount = 1;
	_item.itemNum = 7;
    return S_OK;
}

void itemCauliFlower::release()
{
}

void itemCauliFlower::update()
{
}

void itemCauliFlower::render(int x, int y)
{
	item::render(x, y);
}
