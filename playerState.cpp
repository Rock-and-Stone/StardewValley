#include "pch.h"
#include "playerState.h"
#include "player.h"

#pragma region playerState
playerState::playerState()
{
}

playerState::~playerState()
{
}

#pragma endregion

#pragma region leftWalk

leftWalk::leftWalk()
{
}

leftWalk::~leftWalk()
{
}

HRESULT leftWalk::init()
{
	_player = new player;

	return S_OK;
}

void leftWalk::release()
{
}

void leftWalk::update()
{
	_count++;

	if (_count % 5 == 0)
	{
		_frameX++;
		_player->setFrameX(_frameX);
	}

	if (_frameX >= 5) _frameX = 0;

}
void leftWalk::render(HDC hdc)
{
}
#pragma endregion

#pragma region rightWalk
rightWalk::rightWalk()
{
}

rightWalk::~rightWalk()
{
}

HRESULT rightWalk::init()
{
	_player = new player;

	return S_OK;
}

void rightWalk::release()
{
}

void rightWalk::update()
{
	_count++;

	if (_count % 5 == 0)
	{
		_frameX++;
		_player->setFrameX(_frameX);
	}

	if (_frameX >= 5) _frameX = 0;
}

void rightWalk::render(HDC hdc)
{
}

#pragma endregion

#pragma region upWalk

upWalk::upWalk()
{
}

upWalk::~upWalk()
{
}

HRESULT upWalk::init()
{
	return E_NOTIMPL;
}

void upWalk::release()
{
}

void upWalk::update()
{
	_count++;

	if (_count % 5 == 0)
	{
		_frameX++;
		_player->setFrameX(_frameX);
	}

	if (_frameX >= 5) _frameX = 0;
}

void upWalk::render(HDC hdc)
{
}
#pragma endregion

#pragma region downWalk

downWalk::downWalk()
{
}

downWalk::~downWalk()
{
}

HRESULT downWalk::init()
{
	return E_NOTIMPL;
}

void downWalk::release()
{
}

void downWalk::update()
{
	_count++;

	if (_count % 5 == 0)
	{
		_frameX++;
		_player->setFrameX(_frameX);
	}

	if (_frameX >= 5) _frameX = 0;
}

void downWalk::render(HDC hdc)
{
}
#pragma endregion
