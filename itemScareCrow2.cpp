#include "pch.h"
#include "itemScareCrow2.h"

HRESULT itemScareCrow2::init()
{
	_item.craftItems = SCARECROW2;
	_item.itemImg = IMAGEMANAGER->findImage("craftItems");
	_item.frameX = 3;
	_item.frameY = 0;
	_item.itemName = "냥수아비";
	_item.itemInfo = "고양이 모양을 한 허수아비";
	_item.buyPrice = 0;
	_item.sellPrice = 0;
	_item.damage = 0;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = true;
	//_item.amount = 1;
	_item.itemNum = 6;
	_item.needAmountToCraft = 20;
	return S_OK;
}

void itemScareCrow2::release()
{
}

void itemScareCrow2::update()
{
}

void itemScareCrow2::render(int x, int y)
{
	item::render(x, y);
}
