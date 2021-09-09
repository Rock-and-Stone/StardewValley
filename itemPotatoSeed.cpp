#include "pch.h"
#include "itemPotatoSeed.h"

HRESULT itemPotatoSeed::init()
{
	_item.items = POTATOSEED;
	_item.itemImg = IMAGEMANAGER->findImage("seedItem");
	_item.frameX = 4;
	_item.frameY = 2;
	_item.itemName = "감자씨앗";
	_item.itemInfo = "감자를 키우자";
	_item.buyPrice = 25;
	_item.sellPrice = 15;
	_item.damage = 0;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = false;
	//_item.amount = 1;
	_item.itemNum = 20;
    return S_OK;
}

void itemPotatoSeed::release()
{
}

void itemPotatoSeed::update()
{
}

void itemPotatoSeed::render(int x, int y)
{
	item::render(x, y);
}
