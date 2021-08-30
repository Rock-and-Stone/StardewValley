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
}

void RockStone::SwitchImage()
{
}
