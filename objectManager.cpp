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
     
        (*_viObject)->render();  

    }

}
// =[ ============================================= 积 己 ========================================= ]= //
void objectManager::SetWood(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
         object* Wood;
         Wood = new wood;
       
         Wood->init(OBJ_WOOD, "springObjectsItem", 6, 12, PointMake(x + (i * 10), y),2);
         
   

         _vObject.push_back(Wood);
    }
}
void objectManager::SetStone(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object*  Stone;
        Stone = new stone;
        Stone->init(OBJ_STONE, "springObjectsItem", 10, 1, PointMake(x+(i*10), y),1);

        _vObject.push_back(Stone);
    }
}
void objectManager::SetPufferFish(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* PufferFish;
        PufferFish = new pufferFish;
        PufferFish->init(OBJ_PUFFERFISH, "springObjectsItem", 8, 5, PointMake(x + (i * 10), y),12);

        _vObject.push_back(PufferFish);
    }
}
void objectManager::SetTuna(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Tuna;
        Tuna = new tuna;
        Tuna->init(OBJ_TUNA, "springObjectsItem", 19, 5, PointMake(x , y),13);

        _vObject.push_back(Tuna);
    }
}
void objectManager::SetHaliBut(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Halibut;
        Halibut = new haliBut;
        Halibut->init(OBJ_HALIBUT, "springObjectsItem", 23, 5, PointMake(x + (i * 10), y),11);

        _vObject.push_back(Halibut);
    }
}
void objectManager::SetCauliFlowerSeed(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
{
    object* CauliSeed;
    CauliSeed = new cauliFlowerSeed;
    CauliSeed->init(OBJ_CAULIFLOWERSEED, "springObjectsItem", 18, 19, PointMake(x, y), 17);

    _vObject.push_back(CauliSeed);
}
}
void objectManager::SetParsnipSeed(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* ParsnipSeed;
        ParsnipSeed = new axe;
        ParsnipSeed->init(OBJ_PARSNIPSEED,"springObjectsItem",16,19,PointMake(x,y),19);

        _vObject.push_back(ParsnipSeed);
    }
}
void objectManager::SetPotatoSeed(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* PotatoSeed;
        PotatoSeed = new potatoSeed;
        PotatoSeed->init(OBJ_POTATOSEED, "springObjectsItem", 19, 19, PointMake(x, y),20);

        _vObject.push_back(PotatoSeed);
    }
}
void objectManager::SetKaleSeed(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* KaleSeed;
        KaleSeed = new kaleSeed;
        KaleSeed->init(OBJ_KALESEED, "springObjectsItem", 21, 19, PointMake(x, y), 18);

        _vObject.push_back(KaleSeed);
    }
}
void objectManager::SetCauliFlower(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* CauliFlower;
        CauliFlower = new cauliFlower;
        CauliFlower->init(OBJ_PARSNIPSEED, "crops", 1, 0, PointMake(x, y), 17);
        _vObject.push_back(CauliFlower);
    }
}
void objectManager::SetParsnip(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Parsnip;
        Parsnip = new parsnip;
        Parsnip->init(OBJ_PARSNIP, "crops", 0, 0, PointMake(x, y),9);

        _vObject.push_back(Parsnip);
    }
}
void objectManager::SetPotato(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Potato;
        Potato = new potato;
        Potato->init(OBJ_POTATO, "crops", 5, 1, PointMake(x, y),10);

        _vObject.push_back(Potato);
    }
}
void objectManager::SetKale(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Kale;
        Kale = new kale;
        Kale->init(OBJ_KALE, "crops", 6, 1, PointMake(x, y),8);
        _vObject.push_back(Kale);
    }
}
void objectManager::SetCopper(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Copper;
        Copper = new copper;
        Copper->init(OBJ_COPPER, "springObjectsItem", 22, 13, PointMake(x, y),14);

        _vObject.push_back(Copper);
    }
}
void objectManager::SetIron(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Iron;
        Iron = new iron;
        Iron->init(OBJ_IRON, "springObjectsItem", 23, 13, PointMake(x, y), 15);
        _vObject.push_back(Iron);
    }
}
void objectManager::SetGold(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Gold;
        Gold = new gold;

        Gold->init(OBJ_GOLD, "springObjectsItem", 0, 14, PointMake(x, y), 16);

        _vObject.push_back(Gold);
    }
}
void objectManager::SetBox(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* box;
        box = new Box;
        box->init(OBJ_BOX, "craftObjectSmall", 0, 14, PointMake(x, y), 3);
        _vObject.push_back(box);
    }
}
void objectManager::SetFurnance(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* Furnance;
        Furnance = new furnance;
        Furnance->init(OBJ_FURNACE, "craftObjectSmall", 0, 14, PointMake(x, y), 4);
        _vObject.push_back(Furnance);
    }
}
void objectManager::SetScarecrow1(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* crow1;
        crow1 = new scarecrow1;
        crow1->init(OBJ_SCARECROW1, "craftObjectSmall", 0, 14, PointMake(x, y), 5);
        _vObject.push_back(crow1);
    }
}
void objectManager::SetScarecrow2(float x, float y, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        object* crow2;
        crow2 = new scarecrow2;
        crow2->init(OBJ_SCARECROW2, "craftObjectSmall", 0, 14, PointMake(x, y), 6);
        _vObject.push_back(crow2);
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
        if (playerToObjectDis < 100)
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
                    _inven->AddItem(_inven->GetWood());
                    break;
                case OBJ_STONE:
                    _inven->AddItem(_inven->GetStone());
                    break;
                case OBJ_PUFFERFISH:
                    _inven->AddItem(_inven->GetPufferFish());
                    break;
                case OBJ_TUNA:
                    _inven->AddItem(_inven->GetTuna());
                    break;
                case OBJ_HALIBUT:
                    _inven->AddItem(_inven->GetHaliBut());
                    break;
                case OBJ_CAULIFLOWERSEED:
                    _inven->AddItem(_inven->GetCauliSeed());
                    break;
                case OBJ_PARSNIPSEED:
                    _inven->AddItem(_inven->GetParsnipSeed());
                    break;
                case OBJ_POTATOSEED:
                    _inven->AddItem(_inven->GetPotatoSeed());
                    break;
                case OBJ_KALESEED:
                    _inven->AddItem(_inven->GetKaleSeed());
                    break;
                case OBJ_CAULIFLOWER:
                    _inven->AddItem(_inven->GetCauliFlower());
                    break;
                case OBJ_PARSNIP:
                    _inven->AddItem(_inven->GetParsnip());
                    break;
                case OBJ_POTATO:
                    _inven->AddItem(_inven->GetPotato());
                    break;
                case OBJ_KALE:
                    _inven->AddItem(_inven->GetKale());
                    break;
                case OBJ_COPPER:
                    _inven->AddItem(_inven->GetCopper());
                    break;
                case OBJ_IRON:
                    _inven->AddItem(_inven->GetIron());
                    break;
                case OBJ_GOLD:
                    _inven->AddItem(_inven->GetGold());
                    break;
                case OBJ_BOX:
                    _inven->AddItem(_inven->GetBox());
                    break;
                case OBJ_FURNACE:
                    _inven->AddItem(_inven->GetFurNance());
                    break;
                case OBJ_SCARECROW1:
                    _inven->AddItem(_inven->GetCrow1());
                    break;
                case OBJ_SCARECROW2:
                    _inven->AddItem(_inven->GetCrow2());
                    break;
                default:
                    break;
                }
                _vObject.erase(_vObject.begin() + i);
                SOUNDMANAGER->play("getItem", 1.0f);
            }
            
        }
    }
}

