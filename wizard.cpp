#include "pch.h"
#include "wizard.h"
#include "CameraManager.h"

wizard::wizard()
{
}

wizard::~wizard()
{
}

HRESULT wizard::init(int indX, int indY)
{
	_x = indX * TILEWIDTH + (TILEWIDTH / 2),
	_y = indY * TILEHEIGHT + (TILEHEIGHT / 2);

	_rc = RectMakeCenter(_x + 16, _y + 32, TILEWIDTH, TILEHEIGHT);

	_img = IMAGEMANAGER->findImage("wizard");
	_dialogueNum = 4;
	return S_OK;
}

void wizard::release()
{
}

void wizard::update()
{

	_rc = RectMakeCenter(_x + 16, _y + 32, TILEWIDTH, TILEHEIGHT+32);
	_renderRc = RectMakeCenter(_x - _cameraManager->getCamX() + 16, _y - _cameraManager->getCamY() + 32, TILEWIDTH, TILEHEIGHT+32);
}

void wizard::render()
{
	_img->frameRender(getMemDC(), _x - _cameraManager->getCamX(), _y - _cameraManager->getCamY());

	if (KEYMANAGER->isToggleKey(VK_TAB)) 
	{
		Rectangle(getMemDC(), _renderRc);
	}
}

void wizard::dialogue()
{

	IMAGEMANAGER->findImage("dialogueBox")->render(getMemDC(), WINSIZEX / 2 - 300, WINSIZEY - 250);

	char str[256];

	switch (_dialogueNum)
	{
	case 4:
		sprintf_s(str, "%s", INIDATA->loadDataString("dialogue", "dialogue1", "wizard"));
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _dialogueNum--;

		break;
	case 3:
		sprintf_s(str, "%s", INIDATA->loadDataString("dialogue", "dialogue2", "wizard"));
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _dialogueNum--;

		break;
	case 2:
		sprintf_s(str, "%s", INIDATA->loadDataString("dialogue", "dialogue3", "wizard"));
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _dialogueNum--;

		break;
	case 1:
		sprintf_s(str, "%s", INIDATA->loadDataString("dialogue", "dialogue4", "wizard"));
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) _dialogueNum--;
		break;
	}


	TextOut(getMemDC(), WINSIZEX / 2 - 200, WINSIZEY - 200, str, strlen(str));
}
