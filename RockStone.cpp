#include "pch.h"
#include "RockStone.h"

RockStone::RockStone()
{
}

RockStone::~RockStone()
{
}

HRESULT RockStone::InitVariables()
{
	
	_image = IMAGEMANAGER->findImage("RockStone");
	
	_enemyDirection = DOWN;

	return S_OK;
}

void RockStone::update()
{
	Move();
	if (_enemyDirection == LEFT)
	{
		_posX -= 1;
	}
	if (_enemyDirection == RIGHT)
	{
		_posX += 1;
	}
	if (_enemyDirection == UP)
	{
		_posY -= 1;
	}
	if (_enemyDirection == DOWN)
	{
		_posY += 1;
	}
}

void RockStone::render()
{
	Draw();
}

void RockStone::SwitchImage()
{
	
}
