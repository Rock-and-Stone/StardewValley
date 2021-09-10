#include "pch.h"
#include "itemPickAxe.h"

itemPickAxe::itemPickAxe()
{
}

itemPickAxe::~itemPickAxe()
{
}

HRESULT itemPickAxe::init()
{
	_item.items = PICKAXE;
	_item.itemImg = IMAGEMANAGER->findImage("playerTool");
	_item.frameX = 0;
	_item.frameY = 0;
	_item.itemName = "°î±ªÀÌ";
	_item.itemInfo = "µ¹À» Ä¶¼öÀÖ´Ù";
	_item.buyPrice = 60;
	_item.sellPrice = 30;
	_item.damage = 5;
	_item.hP = 0;
	_item.sP = 0;
	_item.isEatAble = false;
	_item.isHandleAble = false;
	//_item.amount = 1;
	_item.itemNum = 24;
    return	S_OK;
}

void itemPickAxe::release()
{
}

void itemPickAxe::update()
{
}

void itemPickAxe::render(int x, int y)
{
	item::render(x, y);
	//_item.itemImg->frameRender(getMemDC(), x, y, _item.frameX, _item.frameY);
}
