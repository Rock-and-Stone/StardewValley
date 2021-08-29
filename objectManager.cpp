#include "pch.h"
#include "objectManager.h"

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
}

void objectManager::render()
{
}
// =[ ============================================= »ý ¼º ========================================= ]=
void objectManager::SetAxe()
{
    object* Axe;
    Axe = new axe;
    Axe->init("playerTool", PointMake(WINSIZEX / 2, WINSIZEY / 2), AXE, TOOL, 3, 0);
    
    _vObject.push_back(Axe);
}

void objectManager::SetPickAxe()
{
    //object* PickAxe;
    //PickAxe = new pickAxe;
    //PickAxe->init("playerTool", PointMake(WINSIZEX / 2, WINSIZEY / 2), AXE, TOOL, 0, 0);

    //_vObject.push_back(PickAxe);
}

void objectManager::SetHoe()
{
 /*   object* Hoe;
    Hoe = new hoe;
    Hoe->init("playerTool", PointMake(WINSIZEX / 2, WINSIZEY / 2), AXE, TOOL, 1, 0);

    _vObject.push_back(Hoe);*/
}

void objectManager::SetCan()
{
    //object* Can;
    //Can = new can;
    //Can->init("playerTool", PointMake(WINSIZEX / 2, WINSIZEY / 2), AXE, TOOL, 4, 0);

    //_vObject.push_back(Can);
}

void objectManager::SetRod()
{
    //object* Rod;
    //Rod = new rod;
    //Rod->init("playerTool", PointMake(WINSIZEX / 2, WINSIZEY / 2), AXE, TOOL, 5, 0);

    //_vObject.push_back(Rod);
}

void objectManager::SetSword()
{
}

void objectManager::SetSlingShot()
{
}

void objectManager::SetPufferFish()
{
}

void objectManager::SetTuna()
{
}

void objectManager::SetHaliBut()
{
}

void objectManager::SetCauliFlowerSeed()
{
}

void objectManager::SetParsnipSeed()
{
}

void objectManager::SetPotatoSeed()
{
}

void objectManager::SetKaleSeed()
{
}

void objectManager::SetCauliFlower()
{
}

void objectManager::SetParsnip()
{
}

void objectManager::SetPotato()
{
}

void objectManager::SetKale()
{
}

void objectManager::SetCopper()
{
}

void objectManager::SetIron()
{
}

void objectManager::SetGold()
{
}
