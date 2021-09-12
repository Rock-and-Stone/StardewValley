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
                _boxInven[12 * j + i].rc = RectMake(307 + (i * 55.3), 448 + (j * 55.2), 49, 45);
                _invens[12 * j + i].rc = RectMake(307 + (i * 55.3), 500+ (j * 55.2), 49, 45);
            }
        }



    }
    else
    {

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

    if (_boxOpen&&!_inven->GetIsMenuOpen())
    {
       
        _boxUi->render(getMemDC(), _boxUiRc.left, _boxUiRc.top);

        for (int i = 0; i < INVENTORYSIZE; i++)
        {
            Rectangle(getMemDC(), _boxInven[i].rc);
            Rectangle(getMemDC(), _invens[i].rc);
            //그림인쇄
            _vBox[i]->render(_boxInven[i].rc.left, _boxInven[i].rc.top);
            _inven->GetvInven()[i]->render(_invens[i].rc.left, _invens[i].rc.top);
            
            sprintf_s(str, "%d", _inven->GetInven()[i].amount);
            TextOut(getMemDC(), _invens[i].rc.right - 20, _invens[i].rc.bottom - 20, str, strlen(str));

        }
    }
    
    SelectObject(getMemDC(), oldFont2);
    DeleteObject(font2);
}
