#include "pch.h"
#include "itemNULL.h"

itemNULL::itemNULL()
{
}

itemNULL::~itemNULL()
{
}

HRESULT itemNULL::init()
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
	_item.amount = NULL;

	return S_OK;
}

void itemNULL::release()
{
}

void itemNULL::update()
{
}

void itemNULL::render()
{
}
