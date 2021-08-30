#include "pch.h"
#include "wizard.h"

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
}

void wizard::render()
{
	_img->frameRender(getMemDC(), _x, _y);
}
