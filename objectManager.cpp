#include "pch.h"
#include "objectManager.h"
#include "inventory.h"
#include "CameraManager.h"
#include "player.h"

objectManager::objectManager()
{
}

objectManager::~objectManager()
{
}

HRESULT objectManager::init()
{ 

#pragma region heukuaaaaaaa
    _itemstone          = new itemStone;
    _itemwood           = new itemWood;
    _itembox            = new itemBox;
    _itemfurnance       = new itemFurNance;
    _itemscareCrow1     = new itemScareCrow1;
    _itemscareCrow2     = new itemScareCrow2;
    _itemcauliFlower    = new itemCauliFlower;
    _itemkale           = new itemKale;
    _itemparsnip        = new itemParsnip;
    _itempotato         = new itemPotato;
    _itemhalibut        = new itemHaliBut;
    _itempufferFish     = new itemPufferFish;
    _itemtuna           = new itemTuna;
    _itemcopper         = new itemCopper;
    _itemgold           = new itemGold;
    _itemiron           = new itemIron;
    _itemcauliSeed      = new itemCauliSeed;
    _itemkaleSeed       = new itemKaleSeed;
    _itemparsnipSeed    = new itemParsnipSeed;
    _itempotatoSeed     = new itemPotatoSeed;
    _itemstone         ->init();
    _itemwood          ->init(); 
    _itembox           ->init();
    _itemfurnance      ->init();
    _itemscareCrow1    ->init();
    _itemscareCrow2    ->init();
    _itemcauliFlower   ->init();
    _itemkale          ->init();
    _itemparsnip       ->init();
    _itempotato        ->init();
    _itemhalibut       ->init();
    _itempufferFish    ->init();
    _itemtuna          ->init();
    _itemcopper        ->init();
    _itemgold          ->init();
    _itemiron          ->init();
    _itemcauliSeed     ->init();
    _itemkaleSeed      ->init();
    _itemparsnipSeed   ->init();
    _itempotatoSeed    ->init();
#pragma endregion

    
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
    ObjectCollsion();
}

void objectManager::render()
{
    for (_viObject = _vObject.begin(); _viObject != _vObject.end(); _viObject++)
    {
        RECT Temp = (*_viObject)->GetObjectRect();
        (*_viObject)->Draw(_cm->getCamX(),_cm->getCamY());
     
        
    }
}
// =[ ============================================= 积 己 ========================================= ]= //
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
    
    for (int i = 0; i < _vObject.size(); i++)
    {
        float playerToObjectDis = getDistance((_player->getRect().left + _player->getRect().right) / 2,
            (_player->getRect().top + _player->getRect().bottom) / 2,
            _vObject[i]->GetObjectPosX(), _vObject[i]->GetObjectPosY());

        float playerToObjectAng = getAngle((_player->getRect().left + _player->getRect().right) / 2,
            (_player->getRect().top + _player->getRect().bottom) / 2,
            _vObject[i]->GetObjectPosX(), _vObject[i]->GetObjectPosY());

        //芭府备窍扁
        if (playerToObjectDis < 200)
        {
            float mS = -5.0f;
            float ox = _vObject[i]->GetObjectPosX();
            float oy = _vObject[i]->GetObjectPosY();
            ox += mS * cosf(playerToObjectAng);
            oy += mS * -sinf(playerToObjectAng);

            _vObject[i]->SetObjectPosX(ox);
            _vObject[i]->SetObjectPosY(oy);

          
            if (playerToObjectDis < 10)
            {
                switch (_vObject[i]->GetObjectType())
                {
                case OBJ_WOOD:
                    _inven->AddItem(_itemwood);
                    break;
                case OBJ_STONE:
                    _inven->AddItem(_itemstone);
                    break;
                case OBJ_PUFFERFISH:
                    _inven->AddItem(_itempufferFish);
                    break;
                case OBJ_TUNA:
                    _inven->AddItem(_itemtuna);
                    break;
                case OBJ_HALIBUT:
                    _inven->AddItem(_itemhalibut);
                    break;
                case OBJ_CAULIFLOWERSEED:
                    _inven->AddItem(_itemcauliSeed);
                    break;
                case OBJ_PARSNIPSEED:
                    _inven->AddItem(_itemparsnipSeed);
                    break;
                case OBJ_POTATOSEED:
                    _inven->AddItem(_itempotatoSeed);
                    break;
                case OBJ_KALESEED:
                    _inven->AddItem(_itemkaleSeed);
                    break;
                case OBJ_CAULIFLOWER:
                    _inven->AddItem(_itemcauliFlower);
                    break;
                case OBJ_PARSNIP:
                    _inven->AddItem(_itemparsnip);
                    break;
                case OBJ_POTATO:
                    _inven->AddItem(_itempotato);
                    break;
                case OBJ_KALE:
                    _inven->AddItem(_itemkale);
                    break;
                case OBJ_COPPER:
                    _inven->AddItem(_itemcopper);
                    break;
                case OBJ_IRON:
                    _inven->AddItem(_itemiron);
                    break;
                case OBJ_GOLD:
                    _inven->AddItem(_itemgold);
                    break;
                case OBJ_BOX:
                    _inven->AddItem(_itembox);
                    break;
                case OBJ_FURNACE:
                    _inven->AddItem(_itemfurnance);
                    break;
                case OBJ_SCARECROW1:
                    _inven->AddItem(_itemscareCrow1);
                    break;
                case OBJ_SCARECROW2:
                    _inven->AddItem(_itemscareCrow2);
                    break;
                default:
                    break;
                }
                _vObject.erase(_vObject.begin() + i);
            }
            
        }
    }
}

