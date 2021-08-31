#include "pch.h"
#include "inventory.h"
#include "button.h"


HRESULT inventory::init()
{
    //버튼용이미지
    IMAGEMANAGER->addFrameImage("ExitButton", "source/Images/inventory/ExitButton.bmp", 185, 292, 1, 2, true, MAGENTA);
    IMAGEMANAGER->addFrameImage("MenuButton", "source/Images/inventory/MenuButton.bmp", 185, 292, 1, 2, true, MAGENTA);
   
    //버튼new
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
    _buttonToMenu->init("MenuButton", WINSIZEX/2, WINSIZEY/2-100, PointMake(0, 1), PointMake(0, 0), Button, this);
    _buttonExit->init("ExitButton", WINSIZEX/2, WINSIZEY/2+100, PointMake(0, 1), PointMake(0, 0), Button, this);


    //일단 다 빈공간으로 집어넣는다
    for (int i = 0; i <INVENTORYSIZE; i++)
    {

        _inven[i].itemInfo.itemImg =        NULL;
        _inven[i].itemInfo.count =          NULL;
        _inven[i].itemInfo.currentFrameX =  NULL;
        _inven[i].itemInfo.currentFrameY =  NULL;
        _inven[i].itemInfo.itemName = "";
        _inven[i].itemInfo.itemInfo = "";
        _inven[i].itemInfo.damage         = NULL;
        _inven[i].itemInfo.hp             = NULL;
        _inven[i].itemInfo.sp             = NULL;

    }

    //테스트 아이템 집어넣기
  
    
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


    }
   
}

void inventory::render()
{
    //디버깅 테스트
    char str[128];
 
    sprintf_s(str, "isMenuOP : %d", _isMenuOpen);
    TextOut(getMemDC(), 10, 60, str, strlen(str));
    sprintf_s(str, "MenuPage : %d", _menuPage);
    TextOut(getMemDC(), 10, 80, str, strlen(str));
    sprintf_s(str, "draging : %d", _dragActivate);
    TextOut(getMemDC(), 10, 100, str, strlen(str));
    sprintf_s(str, "downpt : %d", _downPtItem);
    TextOut(getMemDC(), 10, 120, str, strlen(str));
    sprintf_s(str, "upPt : %d", _upPtItem);
    TextOut(getMemDC(), 10, 140, str, strlen(str));

 
   //직사각형 위치 테스트
    if (KEYMANAGER->isToggleKey(VK_TAB))
    {
        Rectangle(getMemDC(), _quickSlotRc);
        Rectangle(getMemDC(), _menuRc);
        Rectangle(getMemDC(), _storageRc);
        Rectangle(getMemDC(), _statRc);
        Rectangle(getMemDC(), _craftRc);
        Rectangle(getMemDC(), _settingRc);
        Rectangle(getMemDC(), _exitRc);
    
 
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
            //
            for (int i = 0; i < INVENTORYSIZE; i++)
            {   
                if (_inven[i].itemInfo.itemImg = NULL) continue;
                    _inven[i].itemInfo.itemImg->frameRender(getMemDC(), _inven[i].rc.left, _inven[i].rc.top, _inven[i].itemInfo.currentFrameX, _inven[i].itemInfo.currentFrameY);
                    if (_dragActivate)
                    {
                        _inven[_downPtItem].itemInfo.itemImg->frameRender(getMemDC(), _ptMouse.x - 30, _ptMouse.y - 30, _inven[_downPtItem].itemInfo.currentFrameX, _inven[i].itemInfo.currentFrameY);
                    }

                if (PtInRect(&_inven[i].rc, _ptMouse))
                { 
               
                    _itemInfoImg->render(getMemDC(), _ptMouse.x, _ptMouse.y);

                    sprintf_s(str, "%s", _inven[i].itemInfo.itemName.c_str());
                    TextOut(getMemDC(), _ptMouse.x + 10, _ptMouse.y + 20, str, strlen(str));

                }

            }
            break;
        case StatPage:
            break;
        case CraftPage:
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
        _quickSlot->render(getMemDC(), _quickSlotRc.left, _quickSlotRc.top);
    }

   

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
    
    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        if (PtInRect(&_inven[i].rc, _ptMouse))
        {
            if (KEYMANAGER->isStayKeyDown(VK_LBUTTON)) _dragActivate = true;
            else _dragActivate = false;
                
            if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
            {
                
                  _downPtItem = i;   
            }
            if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
            {
                for (int j = 0; j < INVENTORYSIZE; j++)
                {
                    if (PtInRect(&_inven[j].rc, _ptMouse))
                    {
                        _upPtItem = j;
                    }

                }


                swap(_inven[_downPtItem].itemInfo, _inven[_upPtItem].itemInfo);

            }
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

}
//세팅창
void inventory::MenuSettingOpen()
{

}
//나가는창
void inventory::MenuExitOpen()
{

}

//버튼용
void inventory::SelectMenu()
{
    if(PtInRect(&_storageRc,_ptMouse)||PtInRect(&_statRc,_ptMouse)
       || PtInRect(&_craftRc, _ptMouse)|| PtInRect(&_settingRc, _ptMouse)|| PtInRect(&_exitRc,_ptMouse))
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
void inventory::Button(void* obj)
{
    inventory* invento = (inventory*)obj;

    if (invento->_buttonExit->getBtnDir() == BUTTONDIRECTION_UP) exit(1);
    if (invento->_buttonToMenu->getBtnDir() == BUTTONDIRECTION_UP) SCENEMANAGER->changeScene("mainMenuScene");
}

