#include "pch.h"
#include "player.h"
#include "playerState.h"
#include "homeMap.h"

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

	_leftWalk = new leftWalk;
	_rightWalk = new rightWalk;
	_upWalk = new upWalk;
	_downWalk = new downWalk;

	_leftWalk->setPlayer(this);
	_rightWalk->setPlayer(this);
	_upWalk->setPlayer(this);
	_downWalk->setPlayer(this);

	_homeMap = new homeMap;

	_img = IMAGEMANAGER->findImage("player");

	_rc = RectMakeCenter(_x,_y,TILEWIDTH,TILEHEIGHT);

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		_upWalk->update();
		move();
	}

	if (KEYMANAGER->isStayKeyDown('S'))
	{
		_downWalk->update();
		move();
	}

	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_leftWalk->update();
		move();
	}

	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_rightWalk->update();
		move();
	}
	//////////////////////////////////////////////

	if (KEYMANAGER->isOnceKeyUp('A'))  _frameX = 0;
	if (KEYMANAGER->isOnceKeyUp('D'))  _frameX = 0;
	if (KEYMANAGER->isOnceKeyUp('W'))  _frameX = 0;
	if (KEYMANAGER->isOnceKeyUp('S'))  _frameX = 0;

	_rc = RectMakeCenter(_x + 32, _y + 32, TILEWIDTH, TILEHEIGHT);

}

void player::render()
{
	_img->frameRender(getMemDC(), _rendX ,  _rendY ,_frameX,_frameY);

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		_renderRC = RectMakeCenter(_rendX + 32, _rendY + 32, TILEWIDTH, TILEWIDTH);
		Rectangle(getMemDC(), _renderRC);
	}
}

void player::move()
{
	RECT rcCollision;

	float moveSpeed = 5;


	int tileIndex[2];
	int tileX, tileY;

	rcCollision = _rc;

	switch (_direction)
	{
	case PLAYERDIRECTION_LEFT:
		_frameY = 1;
		_x -= moveSpeed;
		rcCollision = RectMakeCenter(_x, _y, TILESIZE, TILESIZE);

		break;

	case PLAYERDIRECTION_DOWN:
		_frameY = 3;

		_y += moveSpeed;

		rcCollision = RectMakeCenter(_x, _y, TILESIZE, TILESIZE);
		break;

	case PLAYERDIRECTION_RIGHT:
		_frameY = 0;

		_x += moveSpeed;

		rcCollision = RectMakeCenter(_x, _y, TILESIZE, TILESIZE);
		break;
	case PLAYERDIRECTION_UP:
		_img->setFrameX(0);
		_frameY = 2;

		_y -= moveSpeed;

		rcCollision = RectMakeCenter(_x, _y, TILESIZE, TILESIZE);
		break;
	}


	rcCollision.left += 2;
	rcCollision.top += 2;
	rcCollision.right -= 2;
	rcCollision.bottom -= 2;

	tileX = rcCollision.left / TILEWIDTH;
	tileY = rcCollision.top / TILEHEIGHT;

	_idX = tileX;
	_idY = tileY;

	switch (_direction)
	{
	case PLAYERDIRECTION_LEFT:
		tileIndex[0] = tileX + (tileY * TILEX);
		tileIndex[1] = tileX + (tileY + 1) * TILEX;
		break;
	case PLAYERDIRECTION_UP:
		tileIndex[0] = tileX + (tileY * TILEX);
		tileIndex[1] = (tileX + 1) + tileY * TILEX;
		break;
	case PLAYERDIRECTION_RIGHT:
		tileIndex[0] = (tileX + tileY * TILEX) + 1;
		tileIndex[1] = (tileX + (tileY + 1) * TILEX) + 1;
		break;
	case PLAYERDIRECTION_DOWN:
		tileIndex[0] = (tileX + tileY * TILEX) + TILEX;
		tileIndex[1] = (tileX + 1 + tileY * TILEX) + TILEX;
		break;
	}

	for (int i = 0; i < 2; ++i)
	{
		RECT rc;

		if ((((_homeMap->getAttribute()[tileIndex[i]]) & ATTR_UNMOVE) == ATTR_UNMOVE) &&
			IntersectRect(&rc, &_homeMap->getTile()[tileIndex[i]].rc, &rcCollision))
		{
			switch (_direction)
			{
			case PLAYERDIRECTION_LEFT:
				_rc.left = _homeMap->getTile()[tileIndex[i]].rc.right;
				_rc.right = _rc.left + 30;

				_x = (_rc.left + _rc.right) / 2;
				break;
			case PLAYERDIRECTION_UP:
				_rc.top = _homeMap->getTile()[tileIndex[i]].rc.bottom -10;
				_rc.bottom = _rc.top + 32;

				_y = (_rc.top + _rc.bottom) / 2;

				break;

			case PLAYERDIRECTION_RIGHT:
				_rc.right = _homeMap->getTile()[tileIndex[i]].rc.left;
				_rc.left = _rc.right - 30;

				_x = (_rc.left + _rc.right) / 2;
				break;
			case PLAYERDIRECTION_DOWN:
				_rc.bottom = _homeMap->getTile()[tileIndex[i]].rc.top;
				_rc.top = _rc.bottom - 32;

				_y = (_rc.top + _rc.bottom) / 2;
				break;
			}

			return;
		}
	}


	_rc = rcCollision;

	_rc = RectMakeCenter(_x, _y, TILESIZE, TILESIZE);
}