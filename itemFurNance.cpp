#include "pch.h"
#include "itemFurNance.h"

HRESULT itemFurNance::init()
{

	_item.craftItems = FURNACE;
	_item.itemImg = IMAGEMANAGER->findImage("craftItems");
	_item.frameX = 1;
	_item.frameY = 0;
	_item.itemName = "¿ë±¤·Î";
	_item.itemInfo = "±¤¹°À» ³ì¿©º¸ÀÚ!!";
	_item.buyPrice = 0;
	_item.sellPrice = 0;
	_item.damage = 0;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = true;
	//_item.amount = 1;
	_item.needAmountToCraft = 10;
	_item.itemNum = 4;
    return S_OK;
}

void itemFurNance::release()
{
}

void itemFurNance::update()
{
}

void itemFurNance::render(int x, int y)
{
	item::render(x, y);
}
