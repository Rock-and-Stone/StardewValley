#include "pch.h"
#include "itemKale.h"

HRESULT itemKale::init()
{
	_item.items = KALE;
	_item.itemImg = IMAGEMANAGER->findImage("crops");
	_item.frameX = 6;
	_item.frameY = 1;
	_item.itemName = "케일";
	_item.itemInfo = "올레라케아 종의 한종류 ";
	_item.buyPrice = 0;
	_item.sellPrice = 220;
	_item.damage = 0;
	_item.hP = 130;
	_item.sP = 58;
	_item.isEatAble = true;
	_item.isHandleAble = false;
	//_item.amount = 1;
	_item.itemNum = 8;
    return S_OK;
}

void itemKale::release()
{
}

void itemKale::update()
{
   
}

void itemKale::render(int x, int y)
{
	item::render(x, y);
}
