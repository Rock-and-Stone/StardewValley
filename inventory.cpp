#include "pch.h"
#include "inventory.h"
#include "button.h"

HRESULT inventory::init()
{
    //아이템 자식들 //흑염룡이 날뛰는 NEW 구문....
#pragma region Newitems
    _null           = new itemNull;

    _stone          = new itemStone;
    _wood           = new itemWood;

    _box            = new  itemBox;
    _furnance       = new  itemFurNance;
    _scareCrow1     = new  itemScareCrow1;
    _scareCrow2     = new  itemScareCrow2;

    _cauliFlower    = new  itemCauliFlower;
    _kale           = new  itemKale;
    _parsnip        = new  itemParsnip;
    _potato         = new  itemPotato;

    _halibut        = new  itemHaliBut;
    _pufferFish     = new  itemPufferFish;
    _tuna           = new  itemTuna;

    _copper         = new  itemCopper;
    _gold           = new  itemGold;
    _iron           = new  itemIron;

    _cauliSeed      = new  itemCauliSeed;
    _kaleSeed       = new  itemKaleSeed;
    _parsnipSeed    = new  itemParsnipSeed;
    _potatoSeed     = new  itemPotatoSeed;

    _axe            = new  itemAxe;
    _pickAxe        = new  itemPickAxe;
    _can            = new  itemCan;
    _hoe            = new  itemHoe;
    _rod            = new  itemRod;
    _sickle         = new  itemSickle;

    _slingShot      = new  itemSlingShot;
    _sword          = new   itemSword;
   

    //마 데이타 싹긁어와라 마!
    _null        ->init();
                
    _stone       ->init();
    _wood        ->init();
             
    _box         ->init();
    _furnance    ->init();
    _scareCrow1  ->init();
    _scareCrow2  ->init();
            
    _cauliFlower ->init();
    _kale        ->init();
    _parsnip     ->init();
    _potato      ->init();
               
    _halibut     ->init();
    _pufferFish  ->init();
    _tuna        ->init();
            
    _copper      ->init();
    _gold        ->init();
    _iron        ->init();
           
    _cauliSeed   ->init();
    _kaleSeed    ->init();
    _parsnipSeed ->init();
    _potatoSeed  ->init();
           
    _axe         ->init();
    _pickAxe     ->init();
    _can         ->init();
    _hoe         ->init();
    _rod         ->init();
    _sickle      ->init();
          
    _slingShot   ->init();
    _sword       ->init();
#pragma endregion

    //버튼용이미지
    IMAGEMANAGER->addFrameImage("ExitButton", "source/Images/inventory/ExitButton.bmp", 185, 292, 1, 2, true, MAGENTA);
    IMAGEMANAGER->addFrameImage("MenuButton", "source/Images/inventory/MenuButton.bmp", 185, 292, 1, 2, true, MAGENTA);
   
    _quickSlotMin = 0;
    _quickSlotMax = 12;

    _buttonExit = new button;
    _buttonToMenu = new button;


    //아이템정보창 이미지
    _itemInfoImg = IMAGEMANAGER->findImage("itemInfo");
     
    //퀵슬롯 이미지
    _quickSlot = IMAGEMANAGER->findImage("quickSlot");
    
    //메뉴판 이미지 초기화
    _invenImg = IMAGEMANAGER->findImage("itemInventory");
    _statImg = IMAGEMANAGER->findImage("statMenu");
    _craftImg = IMAGEMANAGER->findImage("craftMenu");
    _settingImg = IMAGEMANAGER->findImage("settingMenu");
    _exitImg = IMAGEMANAGER->findImage("exitMenu");

    //현재 메뉴 이미지는 = 인벤이미지로 초기화
    _currentMenuImg = _invenImg;
    
    //메뉴와 퀵슬롯 Rc 위치 초기화
    _quickSlotRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY - _quickSlot->getHeight() / 2, _quickSlot->getWidth(), _quickSlot->getHeight());
    _menuRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _currentMenuImg->getWidth(), _currentMenuImg->getHeight());

    //버튼용 RC 초기화
    _storageRc = RectMake(_menuRc.left + 46, _menuRc.top, 53, 60);
    _statRc = RectMake(_storageRc.right + 5, _storageRc.top, 53, 60);
    _craftRc = RectMake(_statRc.right + 5, _statRc.top, 53, 60);
    _settingRc = RectMake(_craftRc.right + 5, _craftRc.top, 53, 60);
    _exitRc = RectMake(_settingRc.right + 5, _settingRc.top, 53, 60);
    
    _isMenuOpen = false;

    //버튼메뉴
    _buttonToMenu->init("MenuButton", WINSIZEX / 2, WINSIZEY / 2 - 100, PointMake(0, 1), PointMake(0, 0), Button, this);
    _buttonExit->init("ExitButton", WINSIZEX / 2, WINSIZEY / 2 + 100, PointMake(0, 1), PointMake(0, 0), Button, this);


    //인벤에 널값이라도 쳐넣자
    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        _vInven.push_back(_null);
    }

    //기본 툴 넣기
    for (int i = 0; i < 150; i++)
    {
        AddItem(_axe);
    }
      
        AddItem(_pickAxe);
        AddItem(_rod);
        AddItem(_hoe);
        AddItem(_sickle);
        AddItem(_can);


    
    //테스트 아이템 집어넣기
    QuickSlot();
    
    _downPtItem = NULL;
    _upPtItem = NULL;
    return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{
    //메뉴를 키기 위한 함수
    MenuOpen();

    //메뉴창이 켜졌을때
    if (_isMenuOpen)
    {
        //창고르는 버튼용

        SelectMenu();

        //메뉴창에서 실행될 함수
        switch (_menuPage)
        {
        case InvenPage:
            MenuInvetoryOpen();
          
            break;
        case StatPage:
            break;
        case CraftPage:
            MenuCraftOpen();

            break;
        case SettingPage:
            break;
        case ExitPage:
            _buttonExit->update();
            _buttonToMenu->update();
            break;

        default:
            break;
        }
    }

    else if (!_isMenuOpen)
    {
       //QuickSlot();


    }
   
}

void inventory::render()
{
    //디버깅 테스트
    char str[128];
    SetBkMode(getMemDC(), TRANSPARENT);
    HFONT oldFont, font1;
    SetTextColor(getMemDC(), RGB(0, 0, 0));
    HFONT font2 = CreateFont(30, 0, 0, 0, 400, true, false, false,
        DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
        PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("sandoll 미생"));
    HFONT oldFont2 = (HFONT)SelectObject(getMemDC(), font2);


    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        if (PtInRect(&_inven[i].rc, _ptMouse))
        {
            sprintf_s(str, "%d", _inven[i].itemExist);
            TextOut(getMemDC(), 10, 180, str, strlen(str));

    
            sprintf_s(str, "%s", _vInven[i]->GetItemInfo().itemName.c_str());
            TextOut(getMemDC(), 10, 200, str, strlen(str));
        }
    
    }

    //메뉴창이 열렸으면 메뉴창 아니면 퀵슬롯용
    if (_isMenuOpen)
    {
        _currentMenuImg->render(getMemDC(), _menuRc.left, _menuRc.top);

        if (KEYMANAGER->isToggleKey(VK_F1))
        {
            for (int i = 0; i < INVENTORYSIZE; ++i)
            {
                Rectangle(getMemDC(), _inven[i].rc);
                sprintf_s(str, "%d", i);
                TextOut(getMemDC(), _inven[i].rc.left, _inven[i].rc.bottom, str, strlen(str));
            }
        }

        //메뉴창에서 실행될 렌더
        switch (_menuPage)
        {
        case InvenPage:
            
            for (int i = 0; i < _vInven.size(); i++)
            {
                _vInven[i]->render(_inven[i].rc.left, _inven[i].rc.top);
                //
                if (_inven[i].amount != 1 && _inven[i].amount != 0)
                {
                    sprintf_s(str, "%d", _inven[i].amount);
                    TextOut(getMemDC(), _inven[i].rc.right - 25, _inven[i].rc.bottom - 12, str, strlen(str));
                }
                if (_dragActivate)
                {
                    _vInven[_downPtItem]->render(_ptMouse.x - 20, _ptMouse.y - 20);

                    if (_inven[_downPtItem].amount != 1 && _inven[_downPtItem].amount != 0)
                    {
                        sprintf_s(str, "%d", _inven[_downPtItem].amount);
                        TextOut(getMemDC(), _ptMouse.x + 10, _ptMouse.y + 10, str, strlen(str));
                    }
                }

                if (PtInRect(&_inven[i].rc, _ptMouse) && _vInven[i] != _null)
                {
               
                    _itemInfoImg->render(getMemDC(), _ptMouse.x, _ptMouse.y);

                    sprintf_s(str, "%s", _vInven[i]->GetItemInfo().itemName.c_str());
                    TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 20, str, strlen(str));
                    

                    string  temp = _vInven[i]->GetItemInfo().itemInfo;


                    if (temp.length() > 20)
                    {
                        sprintf_s(str, "%s", temp.substr(0,20).c_str());
                        TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 70, str, strlen(str));
                        sprintf_s(str, "%s", temp.substr(20, 20).c_str());
                        TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 90, str, strlen(str));
                    }
                    if (temp.length() < 20)
                    {
                        sprintf_s(str, "%s", temp.substr(0, temp.length()).c_str());
                        TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 70, str, strlen(str));
                    }
            

       
                }
            }
            break;

        case StatPage:
            break;

        case CraftPage:

            for (int i = 0; i < _vInven.size(); i++)
            {
                _vInven[i]->render(_inven[i].rc.left, _inven[i].rc.top);

                if (_inven[i].amount != 1 && _inven[i].amount != 0)
                {
                    sprintf_s(str, "%d", _inven[i].amount);
                    TextOut(getMemDC(), _inven[i].rc.right, _inven[i].rc.bottom, str, strlen(str));
                }
                if (_dragActivate)
                {
                    _vInven[_downPtItem]->render(_ptMouse.x - 20, _ptMouse.y - 20);

                }

                if (PtInRect(&_inven[i].rc, _ptMouse) && _vInven[i] != _null)
                {

                    _itemInfoImg->render(getMemDC(), _ptMouse.x, _ptMouse.y);

                    sprintf_s(str, "%s", _vInven[i]->GetItemInfo().itemName.c_str());
                    TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 20, str, strlen(str));
                    
                    sprintf_s(str, "%s", _vInven[i]->GetItemInfo().itemInfo);
                    TextOut(getMemDC(), _ptMouse.x + 20, _ptMouse.y + 70, str, strlen(str));
                }
            }
            break;

        case SettingPage:
            break;

        case ExitPage:
           _buttonExit->render();
           _buttonToMenu->render();
            break;

        default:
            break;
        }
        

    }
    //메뉴창이 꺼졌을땐 퀵슬롯을 렌더한다
    else if (!_isMenuOpen)
    {
        //퀵슬롯의 이미지를 렌더한다
        _quickSlot->render(getMemDC(), _quickSlotRc.left, _quickSlotRc.top);

        for (int i = _quickSlotMin; i < _quickSlotMax; i++) 
        {
            _vInven[i]->render(_quick[i % 12].rc.left, _quick[i % 12].rc.top);

            if (_inven[i].amount != 1 && _inven[i].amount != 0)
            {
                sprintf_s(str, "%d", _inven[i].amount);
                TextOut(getMemDC(), _quick[i].rc.right - 25, _quick[i].rc.bottom - 12, str, strlen(str));
            }
       
        }
       
    }
    //퀵슬롯 벡터 넘겨주는 용도
    if (KEYMANAGER->isOnceKeyDown(VK_TAB))
    {
        SOUNDMANAGER->play("pickUpItem", 0.1f);

        _quickSlotMin += 12;
        _quickSlotMax += 12;


        if (_quickSlotMax > 36)
        {
            _quickSlotMin = 0;
            _quickSlotMax = 12;

        }
    }
   
    SelectObject(getMemDC(), oldFont2);
    DeleteObject(font2);

}
//메뉴창 열어주고 끄는것
void inventory::MenuOpen()
{
    //메뉴 키고 끄는 버튼
    if (KEYMANAGER->isOnceKeyDown('E')) 
    { 
        _isMenuOpen = !_isMenuOpen; 
     
     
        if (!_isMenuOpen)
            SOUNDMANAGER->play("menuClose", 0.5f);
        else
            SOUNDMANAGER->play("menuOpen", 0.5f);
    }
}
//퀵슬롯 칸생성
void inventory::QuickSlot()
{
    if (!_isMenuOpen)
    {
        for (int i = 0; i < 12; i++)
        {
            //12개 칸으로 생성하고
            _quick[i].rc = RectMake((_quickSlotRc.left + 15) + (i * 44.7), (_quickSlotRc.top + 13), 42, 42); 
        }
    }   
}

//메뉴창에서 인벤토리창
void inventory::MenuInvetoryOpen()
{
    //먼저 직사각형 생성해준다
        for (int j = 0; j < 3; ++j)
        {
            for (int i = 0; i < 12; ++i)
            {
                //12X3 나열순으로 rc 생성
                _inven[12 * j + i].rc = RectMake(307 + (i * 55.3), 178 + (j * 63), 49, 45);
            }
        }
        //스왑 구문
        for (int i = 0; i < INVENTORYSIZE; i++)
        {
            if (PtInRect(&_inven[i].rc, _ptMouse))
            {
                if (KEYMANAGER->isStayKeyDown(VK_LBUTTON)) _dragActivate = true;

        /*        int halfNum ;
                if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
                {
                    halfNum = i;
                    _inven[halfNum].amount /= 2;
                    AddItem(_vInven[halfNum]);
                }*/

                if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
                {
                    _downPtItem = i;
                    if (!_inven[i].itemExist) continue;
                    SOUNDMANAGER->play("pickUpItem", 0.1f);
                }

                if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
                {
                    _dragActivate = false;
                    for (int j = 0; j < INVENTORYSIZE; j++)
                    {
                        if (PtInRect(&_inven[j].rc, _ptMouse))
                        {
                            _upPtItem = j;
                            if (!_inven[_downPtItem].itemExist) break;
                            SOUNDMANAGER->play("pickUpItem", 0.1f);
                        }

                    }
                    swap(_vInven[_downPtItem], _vInven[_upPtItem]);
                    swap(_inven[_downPtItem], _inven[_upPtItem]);
                }
            }
        }
        if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
        {
            _dragActivate = false;

            if (PtInRect(&_menuRc, _ptMouse))
            {
                swap(_vInven[_downPtItem], _vInven[_downPtItem]);
              
            }
        }
     
    
}
//스탯창
void inventory::MenuStatOpen()
{

}
//제작창
void inventory::MenuCraftOpen()
{
    //직사각형 칸생성
    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < 12; ++i)
        {
            //12X3 나열순으로 rc 생성
            _inven[12 * j + i].rc = RectMake(307 + (i * 55.3), 448 + (j * 55.2), 49, 45);
        }
    }
    //스왑 구문
    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        if (PtInRect(&_inven[i].rc, _ptMouse))
        {
            if (KEYMANAGER->isStayKeyDown(VK_LBUTTON)) _dragActivate = true;

            // else 

            if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
            {
                _downPtItem = i;
                if (_vInven[i]->GetItemInfo().items == NONE) continue;
                SOUNDMANAGER->play("pickUpItem", 0.1f);
            }

            if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
            {
                _dragActivate = false;
                for (int j = 0; j < INVENTORYSIZE; j++)
                {
                    if (PtInRect(&_inven[j].rc, _ptMouse))
                    {
                        _upPtItem = j;
                        if (_vInven[_downPtItem]->GetItemInfo().items == NONE) break;
                        SOUNDMANAGER->play("pickUpItem", 0.1f);
                    }

                }
                swap(_vInven[_downPtItem], _vInven[_upPtItem]);
            }
        }
    }
    if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
    {
        _dragActivate = false;

        if (PtInRect(&_menuRc, _ptMouse))
        {
            swap(_vInven[_downPtItem], _vInven[_downPtItem]);
        }
    }

}

//세팅창
void inventory::MenuSettingOpen()
{
}
//나가는창
void inventory::MenuExitOpen()
{
}
//아이템 추가
void inventory::AddItem(item* item)
{
    //신세대
    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        //같은 아이템 넣는거네>>??
        if (_vInven[i] == item)
        {
            //사실상 99개
            if (_inven[i].amount > 98)
            {
                continue;
            }
            else 
            { 
                _inven[i].amount++; 
                _inven[i].itemExist = true;
                break; 
            }
        }
        //같은게 읎네?
        else
        {
            //빈자리입니까?
            if (!_inven[i].itemExist)
            {
                _vInven[i] = item;
                _inven[i].itemExist = true;
                break;
            }
            //임자있네요
            else
            {
                continue;
            }
        }
    }
}

//메뉴버튼용
void inventory::SelectMenu()
{
    if (PtInRect(&_storageRc, _ptMouse) || PtInRect(&_statRc, _ptMouse)
        || PtInRect(&_craftRc, _ptMouse) || PtInRect(&_settingRc, _ptMouse) || PtInRect(&_exitRc, _ptMouse))
    {
        if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
        {
            if (PtInRect(&_storageRc, _ptMouse) && _menuPage != InvenPage)
            {
                SOUNDMANAGER->play("menuSelect", 0.5f);
                _currentMenuImg = _invenImg;
                _menuPage = InvenPage;

            }
            if (PtInRect(&_statRc, _ptMouse) && _menuPage != StatPage)
            {
                SOUNDMANAGER->play("menuSelect", 0.5f);
                _currentMenuImg = _statImg;
                _menuPage = StatPage;
            }
            if (PtInRect(&_craftRc, _ptMouse) && _menuPage != CraftPage)
            {
                SOUNDMANAGER->play("menuSelect", 0.5f);
                _currentMenuImg = _craftImg;
                _menuPage = CraftPage;
            }
            if (PtInRect(&_settingRc, _ptMouse) && _menuPage != SettingPage)
            {
                SOUNDMANAGER->play("menuSelect", 0.5f);
                _currentMenuImg = _settingImg;
                _menuPage = SettingPage;
            }
            if (PtInRect(&_exitRc, _ptMouse))
            {
                SOUNDMANAGER->play("menuSelect", 0.5f);
                _currentMenuImg = _exitImg;
                _menuPage = ExitPage;
            }
        }
    }
}

//나가기버튼 콜백함수
void inventory::Button(void* obj)
{
    inventory* invento = (inventory*)obj;

    if (invento->_buttonExit->getBtnDir() == BUTTONDIRECTION_UP) exit(1);
    if (invento->_buttonToMenu->getBtnDir() == BUTTONDIRECTION_UP) SCENEMANAGER->changeScene("mainMenuScene");
}

