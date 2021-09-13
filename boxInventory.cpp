#include "pch.h"
#include "boxInventory.h"
#include "inventory.h"

HRESULT boxInventory::init()
{
    _boxUi = IMAGEMANAGER->findImage("Storage");
    _boxUiRc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, _boxUi->getWidth(), _boxUi->getHeight());

    //박스에는 다널값으로 넣어준다
    for (int i = 0; i < INVENTORYSIZE; i++)
    {
        _vBox.push_back(_inven->GetNull());
        _boxInven[i].amount = 0;
        _boxInven[i].itemExist = false;

        _invens[i].amount = _inven->GetInven()[i].amount;
        _invens[i].itemExist = _inven->GetInven()[i].itemExist;

    }
 
    return S_OK;
}
            
void boxInventory::update()
{

    if (KEYMANAGER->isOnceKeyDown(VK_F7))
    {
        _boxOpen = !_boxOpen;
    }

    if (_boxOpen)
    {
        //박스 생성
        for (int j = 0; j < 3; ++j)
        {
            for (int i = 0; i < 12; ++i)
            {
                //12X3 나열순으로 rc 생성
                _boxInven[12 * j + i].rc = RectMake(_boxUiRc.left + 75 + (i * 46), _boxUiRc.top + 38 + (j * 46.5), 43, 43);
                _invens[12 * j + i].rc = RectMake(_boxUiRc.left + 75 + (i * 46), _boxUiRc.bottom - 160 + (j * 46.5), 43, 43);
            }
        }
        for (int i = 0; i < INVENTORYSIZE; i++)
        {
            _invens[i].amount = _inven->GetInven()[i].amount;
            _invens[i].itemExist = _inven->GetInven()[i].itemExist;
        }

        if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
        {
            SOUNDMANAGER->play("pickUpItem", 1.0f);

            for (int i = 0; i < INVENTORYSIZE; i++)
            {
                if (PtInRect(&_invens[i].rc, _ptMouse))
                {
                    _downItem = i;
                }
                if (PtInRect(&_boxInven[i].rc, _ptMouse))
                {
                    _downItem = i;
                }
            }
        }
    
        if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
        {
            _drag = true;
        }

        for (int i = 0; i < INVENTORYSIZE; i++)
        {
            if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
            {
                SOUNDMANAGER->play("pickUpItem", 1.0f);
                _drag = false;
                for (int i = 0; i < INVENTORYSIZE; i++)
                {
                    if (PtInRect(&_boxInven[i].rc, _ptMouse))
                    {
                        _vBox[i] = _inven->GetvInven()[_downItem];
                        _boxInven[i].amount = _invens[_downItem].amount;
                        _boxInven[i].itemExist = _invens[_downItem].itemExist;


                        _inven->SetInventory(_inven->GetNull(), _downItem);
               

                    }

                    if (PtInRect(&_invens[i].rc, _ptMouse))
                    {
                        for (int i = 0; i < _boxInven[_downItem].amount; i++)
                        {
                            if (_vBox[_downItem] == _inven->GetNull())continue;
                            _inven->AddItem(_vBox[_downItem]);
                        }  
                        _invens[i].amount = _boxInven[_downItem].amount;
                        _invens[i].itemExist = _boxInven[_downItem].itemExist;

                        _vBox[_downItem] = _inven->GetNull();
                        _boxInven[_downItem].amount = 0;
                        _boxInven[_downItem].itemExist = false;

                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
      


     }


}


void boxInventory::release()
{
}

void boxInventory::render()
{
    char str[256];
    SetBkMode(getMemDC(), TRANSPARENT);
    HFONT oldFont, font1;
    SetTextColor(getMemDC(), RGB(0, 0, 0));
    HFONT font2 = CreateFont(30, 0, 0, 0, 400, true, false, false,
        DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
        PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("sandoll 미생"));
    HFONT oldFont2 = (HFONT)SelectObject(getMemDC(), font2);

    if (_boxOpen)
    {
        _boxUi->render(getMemDC(), _boxUiRc.left, _boxUiRc.top);

        for (int i = 0; i < INVENTORYSIZE; i++)
        {
            //그림인쇄

            if (_drag)
            {
                _vBox[_downItem]->render(_ptMouse.x-10, _ptMouse.y-10);
                _inven->GetvInven()[_downItem]->render(_ptMouse.x - 10, _ptMouse.y - 10);
            }
       
                _vBox[i]->render(_boxInven[i].rc.left, _boxInven[i].rc.top);
                _inven->GetvInven()[i]->render(_invens[i].rc.left, _invens[i].rc.top);
            



            if (_boxInven[i].amount != 0 && _boxInven[i].amount > 1 
                && _inven->GetInven()[i].amount != 0 && _inven->GetInven()[i].amount > 1);
            {
                sprintf_s(str, "%d", _boxInven[i].amount);
                TextOut(getMemDC(), _boxInven[i].rc.right - 20, _boxInven[i].rc.bottom - 20, str, strlen(str));
                sprintf_s(str, "%d", _inven->GetInven()[i].amount);
                TextOut(getMemDC(), _invens[i].rc.right - 20, _invens[i].rc.bottom - 20, str, strlen(str));
            }
        }
    }
    
    SelectObject(getMemDC(), oldFont2);
    DeleteObject(font2);
}
