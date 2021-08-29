#include "pch.h"
#include "player.h"
#include "playerState.h"

player::player()
{
}

player::~player()
{
}

HRESULT player::init()
{
	
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

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	
	move();
	setPlayer();

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
