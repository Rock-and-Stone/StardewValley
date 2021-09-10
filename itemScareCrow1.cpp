#include "pch.h"
#include "itemScareCrow1.h"

HRESULT itemScareCrow1::init()
{
	_item.craftItems = SCARECROW1;
	_item.itemImg = IMAGEMANAGER->findImage("craftItems");
	_item.frameX = 2;
	_item.frameY = 0;
	_item.itemName = "허수아비";
	_item.itemInfo = "허수아비를 설치해서 새들을 겁주세요!";
	_item.buyPrice = 0;
	_item.sellPrice = 0;
	_item.damage = 0;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = true;
	//_item.amount = 1;
	_item.itemNum = 5;
	_item.needAmountToCraft = 10;
    return S_OK;
}

void itemScareCrow1::release()
{
}

void itemScareCrow1::update()
{
}

void itemScareCrow1::render(int x, int y)
{
	item::render(x, y);
}
