#include "pch.h"
#include "axe.h"

HRESULT axe::init()
{
    _item.items = AXE;
    _item.objectImg = IMAGEMANAGER->findImage("playerTool");
    _item.frameX = 3;
    _item.frameY = 0;
    _item.itemName = "도끼";
    _item.itemInfo = "나무를 베어낼 수 있는 도구";
    _item.damage = 2;
    _item.hP = 0;
    _item.sP = 0;
    _item.price = 100;

    _item.isburiedAble = false;
    
    


    return S_OK;
}

void axe::release()
{
}

void axe::update()
{
}

void axe::render()
{
}

void axe::Draw()
{

}
