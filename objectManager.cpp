#include "pch.h"
#include "objectManager.h"
#include "inventory.h"

objectManager::objectManager()
{
}

objectManager::~objectManager()
{
}

HRESULT objectManager::init()
{
    return S_OK;
}

void objectManager::release()
{
}
 
void objectManager::update()
{
    for (_viObject = _vObject.begin(); _viObject != _vObject.end(); _viObject++)
    {
        (*_viObject)->update();
    }
}

void objectManager::render()
{
    for (_viObject = _vObject.begin(); _viObject != _vObject.end(); _viObject++)
    {
        RECT Temp = (*_viObject)->GetObjectRect();
        (*_viObject)->render();
     
        
    }
}
// =[ ============================================= »ý ¼º ========================================= ]= //
void objectManager::SetWood(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
         object* Wood;
         Wood = new wood;
         if (amount < 10)
         {
             Wood->init(OBJ_WOOD, "springObjects", 6, 12, PointMake(x + (5 * i), y + (5 * i)));
         }
         else
             Wood->init(OBJ_WOOD, "springObjects", 6, 12, PointMake(x, y));

         
         _vObject.push_back(Wood);
    }
}
void objectManager::SetStone(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object*  Stone;
        Stone = new stone;
        Stone->init(OBJ_STONE, "springObjects", 6, 12, PointMake(x + (i * 10), y));
        _vObject.push_back(Stone);
    }
}
void objectManager::SetPufferFish(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* PufferFish;
        PufferFish = new pufferFish;
        PufferFish->init(OBJ_PUFFERFISH, "springObjects", 6, 12, PointMake(x + (i * 10), y));
        _vObject.push_back(PufferFish);
    }
}
void objectManager::SetTuna(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Tuna;
        Tuna = new tuna;
        Tuna->init(OBJ_TUNA, "springObjects", 6, 12, PointMake(x + (i * 10), y));
        _vObject.push_back(Tuna);
    }
}
void objectManager::SetHaliBut(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Halibut;
        Halibut = new haliBut;
        Halibut->init(OBJ_HALIBUT, "springObjects", 6, 12, PointMake(x + (i * 10), y));
        _vObject.push_back(Halibut);
    }
}
void objectManager::SetCauliFlowerSeed(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
{
    object* CauliSeed;
    CauliSeed = new cauliFlowerSeed;
    CauliSeed->init(OBJ_CAULIFLOWERSEED,"2",2,2,PointMake(x,y));
    _vObject.push_back(CauliSeed);
}
}
void objectManager::SetParsnipSeed(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* ParsnipSeed;
        ParsnipSeed = new axe;
        ParsnipSeed->init(OBJ_PARSNIPSEED,"2",2,2,PointMake(x,y));
        _vObject.push_back(ParsnipSeed);
    }
}
void objectManager::SetPotatoSeed(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* PotatoSeed;
        PotatoSeed = new potatoSeed;
        PotatoSeed->init(OBJ_POTATOSEED, "2", 2, 2, PointMake(x, y));
        _vObject.push_back(PotatoSeed);
    }
}
void objectManager::SetKaleSeed(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* KaleSeed;
        KaleSeed = new kaleSeed;
        KaleSeed->init(OBJ_KALESEED, "2", 2, 2, PointMake(x, y));
        _vObject.push_back(KaleSeed);
    }
}
void objectManager::SetCauliFlower(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* CauliFlower;
        CauliFlower = new cauliFlower;
        CauliFlower->init(OBJ_PARSNIPSEED, "2", 2, 2, PointMake(x, y));
        _vObject.push_back(CauliFlower);
    }
}
void objectManager::SetParsnip(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Parsnip;
        Parsnip = new parsnip;
        Parsnip->init(OBJ_PARSNIP, "2", 2, 2, PointMake(x, y));
        _vObject.push_back(Parsnip);
    }
}
void objectManager::SetPotato(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Potato;
        Potato = new potato;
        Potato->init(OBJ_POTATO, "2", 2, 2, PointMake(x, y));
        _vObject.push_back(Potato);
    }
}
void objectManager::SetKale(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Kale;
        Kale = new kale;
        Kale->init(OBJ_KALE, "2", 2, 2, PointMake(x, y));
        _vObject.push_back(Kale);
    }
}
void objectManager::SetCopper(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Copper;
        Copper = new copper;
        Copper->init(OBJ_COPPER, "2", 2, 2, PointMake(x, y));
        _vObject.push_back(Copper);
    }
}
void objectManager::SetIron(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Iron;
        Iron = new iron;
        Iron->init(OBJ_PARSNIPSEED, "2", 2, 2, PointMake(x, y));
        _vObject.push_back(Iron);
    }
}
void objectManager::SetGold(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Gold;
        Gold = new gold;
        Gold->init(OBJ_GOLD, "2", 2, 2, PointMake(x, y));
        _vObject.push_back(Gold);
    }
}
void objectManager::ObjectCollsion()
{
    RECT temp;
    RECT playerRc;
    RECT ObjcetRc;
    for (int i = 0; i < _vObject.size(); i++)
    {

    }
}

