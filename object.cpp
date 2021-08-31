#include "pch.h"
#include "object.h"

object::object()
{
}

object::~object()
{
}

HRESULT object::init()
{


    return S_OK;
}

HRESULT object::init(ALLITEMS item, const char* imageName, string itemname, string iteminfo, int framex, int framey, int Price, int Damage, int hp, int sp, bool isbarriable)
{
    _item.items     = item;
    _item.itemImg = IMAGEMANAGER->findImage(imageName);
    _item.itemName = itemname;
    _item.itemInfo = iteminfo;
    _item.frameX = framex;
    _item.frameY = framey;
    _item.price = Price;
    _item.damage = Damage;
    _item.hP = hp;
    _item.sP = sp;
    _item.isburiedAble = isbarriable;

    return S_OK;
}

void object::release()
{
}

void object::update()
{
   
}

void object::render()
{
    Draw();
}

void object::itemSetup()
{
}

void object::Draw()
{



}
