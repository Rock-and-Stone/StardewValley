#include "pch.h"
#include "player.h"
#include "playerState.h"

player::player()
{
}

player::~player()
{
}

HRESULT player::init(int indX, int indY)
{
	
	_x = indX * TILEWIDTH + (TILEWIDTH / 2),
	_y = indY * TILEHEIGHT + (TILEHEIGHT / 2);

	_frameX = _frameY = 0;

	_leftwalk = new leftWalk;
	_rightWalk = new rightWalk;
	_upWalk = new upWalk;
	_downWalk = new downWalk;

	_leftwalk->setPlayer(this);
	_rightWalk->setPlayer(this);
	_upWalk->setPlayer(this);
	_downWalk->setPlayer(this);

	_img = IMAGEMANAGER->findImage("player");

	_rc = RectMakeCenter(_x,_y,TILEWIDTH,TILEHEIGHT);

	_tileX = 20;

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	
	move();
	setPlayer();
	tileSearch();

	_rc = RectMakeCenter(_x, _y, TILEWIDTH, TILEHEIGHT);

}

void player::render()
{
	_img->frameRender(getMemDC(), _x, _y,_frameX,_frameY);
}

void player::move()
{
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_x -= 5;
		_leftwalk->update();
	}
	if (KEYMANAGER->isStayKeyDown('D')) 
	{
		_x += 5; 
		_rightWalk->update();
	}
	if (KEYMANAGER->isStayKeyDown('W')) 
	{
		_y -= 5;
		_upWalk->update();

	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		_y += 5; 
		_downWalk->update();
	}
}

void player::setPlayer()
{
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		_frameY = 1;
	}

	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		_frameX = 0;
	}

	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		_frameY = 0;
	}

	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		_frameX = 0;
	}

	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		_frameY = 2;
	}

	if (KEYMANAGER->isOnceKeyUp('W'))
	{
		_frameX = 0;
	}

	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		_frameY = 3;
	}

	if (KEYMANAGER->isOnceKeyUp('S'))
	{
		_frameX = 0;
	}

}

void player::tileSearch()
{
	RECT rcCollision;	

	int tileIndex[2];	
	int tileX, tileY;

	rcCollision = _rc;


	rcCollision.left += 2;
	rcCollision.top += 2;
	rcCollision.right -= 2;
	rcCollision.bottom -= 2;

	tileX = rcCollision.left / TILEWIDTH;
	tileY = rcCollision.top / TILEHEIGHT;


	switch (_direction)
	{
	case PLAYERDIRECTION_LEFT:	
		tileIndex[0] = tileX + (tileY * _tileX);
		tileIndex[1] = tileX + (tileY + 1) * _tileX;
		break;
	case PLAYERDIRECTION_UP:
		tileIndex[0] = tileX + (tileY * _tileX);
		tileIndex[1] = (tileX + 1) + tileY * _tileX;
		break;
	case PLAYERDIRECTION_RIGHT:
		tileIndex[0] = (tileX + tileY * _tileX) + 1;
		tileIndex[1] = (tileX + (tileY + 1) * _tileX) + 1;
		break;
	case PLAYERDIRECTION_DOWN:
		tileIndex[0] = (tileX + tileY * _tileX) + _tileX;
		tileIndex[1] = (tileX + 1 + tileY * _tileX) + _tileX;
		break;
	}
	_rc = rcCollision;

	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
}