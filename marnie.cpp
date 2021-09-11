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
	
	_rc = RectMakeCenter(_x + 16, _y + 32, TILEWIDTH, TILEHEIGHT + 32);

	_img = IMAGEMANAGER->findImage("marnie");

	return S_OK;
}

void marnie::release()
{
}

void marnie::update()
{
	_rc = RectMakeCenter(_x + 16, _y + 32, TILEWIDTH, TILEHEIGHT + 32);

	_renderRc = RectMakeCenter(_x - _cameraManager->getCamX() + 16, _y - _cameraManager->getCamY() + 32, TILEWIDTH, TILEHEIGHT + 32);
}

void marnie::render()
{
	_img->frameRender(getMemDC(), _x - _cameraManager->getCamX(), _y - _cameraManager->getCamY());

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _renderRc);
	}
}

void marnie::dialogue()
{
	IMAGEMANAGER->findImage("dialogueBox")->render(getMemDC(), WINSIZEX / 2 - 300, WINSIZEY - 250);
}
