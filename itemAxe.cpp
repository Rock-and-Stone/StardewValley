#include "pch.h"
#include "itemAxe.h"

itemAxe::itemAxe()
{
}

itemAxe::~itemAxe()
{
}

HRESULT itemAxe::init()
{
	_item.items = AXE;
	_item.itemImg = IMAGEMANAGER->findImage("playerTool");
	_item.frameX = 3;
	_item.frameY = 0;
	_item.itemName = "도끼";
	_item.itemInfo = "나무를 자를수 있음";
	_item.buyPrice = 50;
	_item.sellPrice = 20;
	_item.damage = 10;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = true;
	//_item.amount = 1;
	_item.itemNum = 21;

	return S_OK;
}

void itemAxe::release()
{
}

void itemAxe::update()
{
}

void itemAxe::render(int x, int y)
{
	item::render(x,y);
	//_item.itemImg->frameRender(getMemDC(), x, y, _item.frameX, _item.frameY);
}
