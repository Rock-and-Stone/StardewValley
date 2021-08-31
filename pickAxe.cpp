#include "pch.h"
#include "pickAxe.h"

HRESULT pickAxe::init()
{
    _item.items = PICKAXE;
    _item.objectImg = IMAGEMANAGER->findImage("playerTool");
    _item.frameX = 0;
    _item.frameY = 0;
    _item.itemName = "°î±ªÀÌ";
    _item.itemInfo = "µ¹ÀÌ³ª ±¤¼®À» Ä¶ ¼ö ÀÖ´Â µµ±¸";
    _item.damage = 10;
    _item.hP = 0;
    _item.sP = 0;
    _item.price = 50;

    _item.isburiedAble = false;
    return S_OK;
}

void pickAxe::release()
{
}

void pickAxe::update()
{
}

void pickAxe::render()
{
}

void pickAxe::Draw()
{
}
