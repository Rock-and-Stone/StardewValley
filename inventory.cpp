#include "pch.h"
#include "inventory.h"

HRESULT inventory::init()
{
    //퀵슬롯 이미지
    _quickSlot = IMAGEMANAGER->findImage("quickSlot");
    
    //메뉴판 이미지 초기화
    _invenImg = IMAGEMANAGER->findImage("itemInventory");
    _statImg = IMAGEMANAGER->findImage("statMenu");
    _craftImg = IMAGEMANAGER->findImage("craftMenu");
    _settingImg = IMAGEMANAGER->findImage("settingMenu");
    //_exitImg = IMAGEMANAGER->findImage("e");

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
    //exitRc=
    
   

    _isMenuOpen = false;

    return S_OK;
}

void inventory::release()
{
}

void inventory::update()
{
    //카메라에 따라서 퀵슬롯위치 변경
  ////if(camx)
  //{

  //}

  //인벤토리에서 직사각형으로 만들기
    for (int i = 0; i < INVENTORYSIZE; i++)
  {
 
     //   _rc = RectMakeCenter
      
  }


    MenuOpen();
}

void inventory::render()
{
    char str[128];
    sprintf_s(str, "Menu : %d", _isMenuOpen);
    TextOut(getMemDC(), 10, 80, str, strlen(str));


    sprintf_s(str, "inven : %d", _isInvenOpen);
    TextOut(getMemDC(), 10, 100, str, strlen(str));
    sprintf_s(str, "StatOpen : %d", _isStatOpen);
    TextOut(getMemDC(), 10, 120, str, strlen(str));
    sprintf_s(str, "CraftOpen : %d", _isCraftOpen);
    TextOut(getMemDC(), 10, 140, str, strlen(str));
    sprintf_s(str, "SettingOpen : %d", _isSettingOpen);
    TextOut(getMemDC(), 10, 160, str, strlen(str));
    sprintf_s(str, "isExitOpen : %d", _isExitOpen);
    TextOut(getMemDC(), 10, 180, str, strlen(str));



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
    }
    else if (!_isMenuOpen)
    {
        _quickSlot->render(getMemDC(), _quickSlotRc.left, _quickSlotRc.top);

    }
    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < 12; ++i)
        {
            Rectangle(getMemDC(), _items[i].rc);
        }
    }


}

void inventory::MenuOpen()
{
    //메뉴 키고 끄는 버튼
    if (KEYMANAGER->isOnceKeyDown('E')) 
    { 
        _isMenuOpen = !_isMenuOpen; 
        _isInvenOpen = true; 
        if (!_isMenuOpen)
            SOUNDMANAGER->play("menuClose", 0.5f);
        else
            SOUNDMANAGER->play("menuOpen", 0.5f);
    }

    if (_isMenuOpen)
    {
        SelectMenu();
    }
    else if (!_isMenuOpen)
    {
        _isInvenOpen = false;
        _isStatOpen = false;
        _isCraftOpen = false;
        _isSettingOpen = false;
      //_isExitOpen = false;
    }

}

void inventory::InvetoryOpen()
{
    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < 12; ++i)
        {
            _items[i].rc = RectMake(_menuRc.left + 42 + (i * 4) , _menuRc.top + 93 + (j * 10), 50, 45);
        }
    }
}

void inventory::StatOpen()
{

}

void inventory::CraftOpen()
{

}

void inventory::SettingOpen()
{

}

void inventory::ExitOpen()
{

}

void inventory::SelectMenu()
{
    if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
    {
        if (PtInRect(&_storageRc, _ptMouse)&&!_isInvenOpen)
        {
            SOUNDMANAGER->play("menuSelect", 0.5f);
            _currentMenuImg = _invenImg;
            _isInvenOpen = true;
            _isStatOpen = false;
            _isCraftOpen = false;
            _isSettingOpen = false;
           // _isExitOpen = false;
        }
        if (PtInRect(&_statRc, _ptMouse) && !_isStatOpen)
        {
            SOUNDMANAGER->play("menuSelect", 0.5f);
            _currentMenuImg = _statImg;
            _isInvenOpen = false;
            _isStatOpen = true;
            _isCraftOpen = false;
            _isSettingOpen = false;
            _isExitOpen = false;
        }
        if (PtInRect(&_craftRc, _ptMouse) && !_isCraftOpen)
        {
            SOUNDMANAGER->play("menuSelect", 0.5f);
            _currentMenuImg = _craftImg;
            _isInvenOpen = false;
            _isStatOpen = false;
            _isCraftOpen = true;
            _isSettingOpen = false;
            _isExitOpen = false;
        }
        if (PtInRect(&_settingRc, _ptMouse) && !_isSettingOpen)
        {
            SOUNDMANAGER->play("menuSelect", 0.5f);
            _currentMenuImg = _settingImg;
            _isInvenOpen = false;
            _isStatOpen = false;
            _isCraftOpen = false;
            _isSettingOpen = true;
            _isExitOpen = false;
        }
        /*if (PtInRect(&_exitRc, _ptMouse))
        {
            _currentMenuImg = _exitImg;
            _isInvenOpen = false;
            _isStatOpen = false;
            _isCraftOpen = false;
            _isSettingOpen = false;
            _isExitOpen = true;
        }*/
    }


}
//      메뉴창에서 상호작용
void inventory::ClickObject()
{
}

void inventory::DragObject()
{
}

void inventory::DragObjectToSwap()
{
}
