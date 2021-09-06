#include "pch.h"
#include "marnie.h"
#include "CameraManager.h"

marnie::marnie()
{
}

marnie::~marnie()
{
}

HRESULT marnie::init(int indX, int indY)
{

	_x = indX * TILESIZE + (TILESIZE / 2),
	_y = indY * TILESIZE + (TILESIZE / 2);

	_rc = RectMakeCenter(_x, _y, TILESIZE, TILESIZE);

	_img = IMAGEMANAGER->findImage("marnie");

	return S_OK;
}

void marnie::release()
{
}

void marnie::update()
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

void marnie::render()
{
	_img->frameRender(getMemDC(), _x - _cameraManager->getCamX(), _y - _cameraManager->getCamY());
}
