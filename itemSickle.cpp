#include "pch.h"
#include "itemSickle.h"

itemSickle::itemSickle()
{
}

itemSickle::~itemSickle()
{
}

HRESULT itemSickle::init()
{
	_item.items = SICKLE;
	_item.itemImg = IMAGEMANAGER->findImage("playerTool");
	_item.frameX = 2;
	_item.frameY = 0;
	_item.itemName = "낫";
	_item.itemInfo = "잡초를 베어낼 수 있다";
	_item.buyPrice = 10;
	_item.sellPrice = 5;
	_item.damage = 5;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = false;
	//_item.amount = 1;
	return S_OK;
}

void itemSickle::release()
{
}

void itemSickle::update()
{
}

void itemSickle::render(int x, int y)
{
	item::render(x, y);
}
