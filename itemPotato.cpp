#include "pch.h"
#include "itemPotato.h"

HRESULT itemPotato::init()
{
	_item.items = POTATO;
	_item.itemImg = IMAGEMANAGER->findImage("crops");
	_item.frameX = 5;
	_item.frameY = 1;
	_item.itemName = "´ëÈ«´Ü °¨ÀÚ";
	_item.itemInfo = "¿Õ°¨ÀÚ ~ ¿Õ°¨ÀÚ";
	_item.buyPrice = 0;
	_item.sellPrice = 150;
	_item.damage = 10;
	_item.hP = 65;
	_item.sP = 29;
	_item.isEatAble = true;
	_item.isHandleAble = false;
	//_item.amount = 1;
	_item.itemNum = 10;
    return S_OK;
}

void itemPotato::release()
{
}

void itemPotato::update()
{
}

void itemPotato::render(int x, int y)
{
	item::render(x, y);
}
