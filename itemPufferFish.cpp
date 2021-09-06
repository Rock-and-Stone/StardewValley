#include "pch.h"
#include "itemPufferFish.h"

HRESULT itemPufferFish::init()
{
	_item.items = PUFFERFISH;
	_item.itemImg = IMAGEMANAGER->findImage("playerTool");
	_item.frameX = 8;
	_item.frameY = 4;
	_item.itemName = "�þ�";
	_item.itemInfo = "������ ������ ġ������ ������ ����� �� �ִ�. �ݵ�� �������� �ȵ���....";
	_item.buyPrice = 0;
	_item.sellPrice = 500;
	_item.damage = 10;
	_item.hP = -200;
	_item.sP = -200;
	_item.isEatAble = true;
	_item.isHandleAble = false;
	//_item.amount = 1;
    return S_OK;
}

void itemPufferFish::release()
{
}

void itemPufferFish::update()
{
}

void itemPufferFish::render(int x, int y)
{
	item::render(x, y);
}
