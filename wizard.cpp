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

	_rc = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);

	_img = IMAGEMANAGER->findImage("wizard");

	return S_OK;
}

void wizard::release()
{
}

void wizard::update()
{
	_rc = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);

	int tileX, tileY;

	RECT rcCollision;
	rcCollision = _rc;

	rcCollision.left += 2;
	rcCollision.top += 2;
	rcCollision.right -= 2;
	rcCollision.bottom -= 2;

	tileX = rcCollision.left / TILEWIDTH;
	tileY = rcCollision.top / TILEHEIGHT;

	_idX = tileX;
	_idY = tileY;
}

void wizard::render()
{
	_img->frameRender(getMemDC(), _x - _cameraManager->getCamX(), _y - _cameraManager->getCamY());
}

