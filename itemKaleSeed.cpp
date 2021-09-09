#include "pch.h"
#include "itemKaleSeed.h"

HRESULT itemKaleSeed::init()
{
	_item.items =  KALESEED;
	_item.itemImg = IMAGEMANAGER->findImage("seedItem");
	_item.frameX = 5;
	_item.frameY = 0;
	_item.itemName = "케일 씨앗";
	_item.itemInfo = "케일 씨앗으로 케일을 키워보자";
	_item.buyPrice = 10;
	_item.sellPrice = 5;
	_item.damage = 0;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = true;
	//_item.amount = 1;
	_item.itemNum = 18;
    return S_OK;
}

void itemKaleSeed::release()
{
}

void itemKaleSeed::update()
{
}

void itemKaleSeed::render(int x, int y)
{
	item::render(x, y);
}
