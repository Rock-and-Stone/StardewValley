#include "pch.h"
#include "itemNull.h"

itemNull::itemNull()
{
}

itemNull::~itemNull()
{
}

HRESULT itemNull::init()
{
	_item.items = NONE;
	_item.itemImg = NULL;
	_item.frameX = NULL;
	_item.frameY = NULL;
	_item.itemName = "";
	_item.itemInfo = "";
	_item.buyPrice = NULL;
	_item.sellPrice = NULL;
	_item.damage = NULL;
	_item.hP = NULL;
	_item.sP = NULL;
	_item.isEatAble = NULL;
	_item.isHandleAble = NULL;
	_item.itemNum = 0;
	//_item.amount = NULL;

	return S_OK;
}

void itemNull::release()
{
}

void itemNull::update()
{
}

void itemNull::render(int x, int y)
{
}
