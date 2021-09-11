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

void wizard::dialog()
{
	GAMEDATA->setIsPause(true);
}

