#include "pch.h"
#include "itemRod.h"

itemRod::itemRod()
{
}

itemRod::~itemRod()
{
}

HRESULT itemRod::init()
{
	_item.items = ROD;
	_item.itemImg = IMAGEMANAGER->findImage("playerTool");
	_item.frameX = 5;
	_item.frameY = 0;
	_item.itemName = "낚시대";
	_item.itemInfo = "해변이나 개울에서 낚시를 할수있는 도구";
	_item.buyPrice = 30;
	_item.sellPrice = 15;
	_item.damage = 0;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = true;
	//_item.amount = 1;

	_item.itemNum = 25;
	return	S_OK;
}

void itemRod::release()
{
}

void itemRod::update()
{
}

void itemRod::render(int x, int y)
{
	item::render(x, y);
}
