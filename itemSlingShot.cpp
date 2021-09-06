#include "pch.h"
#include "itemSlingShot.h"

HRESULT itemSlingShot::init()
{
	_item.items = SLINGSHOT;
	_item.itemImg = IMAGEMANAGER->findImage("playerTool");
	_item.frameX = 1;
	_item.frameY = 7;
	_item.itemName = "����";
	_item.itemInfo = "������� ����....����";
	_item.buyPrice = 1500;
	_item.sellPrice = 750;
	_item.damage = 40;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = true;
	//_item.amount = 1;
    return S_OK;
}

void itemSlingShot::release()
{
}

void itemSlingShot::update()
{
}

void itemSlingShot::render(int x, int y)
{
	item::render(x, y);
}
