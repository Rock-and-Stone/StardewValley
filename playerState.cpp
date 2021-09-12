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
	_player->setFrameY(1);
}
void leftWalk::render(HDC hdc)
{
}

void leftWalk::setFrameY()
{
	_player->setFrameY(1);
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

	_player->setFrameY(0);
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
	_player->setFrameY(2);
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
	_player->setFrameY(3);
}

void downWalk::render(HDC hdc)
{
}
#pragma endregion

#pragma region Sword
playerSword::playerSword()
{
}

playerSword::~playerSword()
{
}

HRESULT playerSword::init()
{

	_player = new player;
	return S_OK;
}

void playerSword::release()
{
}

void playerSword::update()
{
	SOUNDMANAGER->play("hitPlayer", 1.0f);
	switch (_player->getDir())
	{
	case 0:
		_player->setFrameY(29);
		_player->setMaxFrameX(6);
		break;
	case 1:
		_player->setFrameY(30);
		_player->setMaxFrameX(6);

		break;
	case 2:
		_player->setFrameY(31);
		_player->setMaxFrameX(3);
		break;
	case 3:
		_player->setFrameY(28);
		_player->setMaxFrameX(6);
		break;
	}
}

void playerSword::render(HDC hdc)
{
}
#pragma endregion

#pragma region Hoe 
playerHoe::playerHoe()
{
}

playerHoe::~playerHoe()
{
}

HRESULT playerHoe::init()
{
	_player = new player;
	return S_OK;
}

void playerHoe::release()
{
}

void playerHoe::update()
{
	switch (_player->getDir())
	{
	case 0:
		_player->setFrameY(10);
		_player->setMaxFrameX(5);
		break;
	case 1:
		_player->setFrameY(11);
		_player->setMaxFrameX(5);

		break;
	case 2:
		_player->setFrameY(9);
		_player->setMaxFrameX(4);
		break;
	case 3:
		_player->setFrameY(8);
		_player->setMaxFrameX(3);
		break;
	}
}

void playerHoe::render(HDC hdc)
{
}
#pragma endregion

#pragma region Axe
playerAxe::playerAxe()
{
}

playerAxe::~playerAxe()
{
}

HRESULT playerAxe::init()
{
	_player = new player;
	return S_OK;
}

void playerAxe::release()
{
}

void playerAxe::update()
{
	
	switch (_player->getDir())
	{
	case 0:
		_player->setFrameY(5);
		_player->setMaxFrameX(5);
		break;
	case 1:
		_player->setFrameY(6);
		_player->setMaxFrameX(5);

		break;
	case 2:
		_player->setFrameY(7);
		_player->setMaxFrameX(4);
		break;
	case 3:
		_player->setFrameY(4);
		_player->setMaxFrameX(6);
		break;
	}
}

void playerAxe::render(HDC hdc)
{
}
#pragma endregion

#pragma region Can
playerCan::playerCan()
{
}

playerCan::~playerCan()
{
}

HRESULT playerCan::init()
{
	_player = new player;
	return S_OK;
}

void playerCan::release()
{
}

void playerCan::update()
{
	switch (_player->getDir())
	{
	case 0:
		_player->setFrameY(16);
		_player->setMaxFrameX(5);
		break;
	case 1:
		_player->setFrameY(17);
		_player->setMaxFrameX(5);

		break;
	case 2:
		_player->setFrameY(19);
		_player->setMaxFrameX(3);
		break;
	case 3:
		_player->setFrameY(18);
		_player->setMaxFrameX(6);
		break;
	}
}

void playerCan::render(HDC hdc)
{
}
#pragma endregion

#pragma region PickAxe
playerPickAxe::playerPickAxe()
{
}

playerPickAxe::~playerPickAxe()
{
}

HRESULT playerPickAxe::init()
{
	_player = new player;
	return S_OK;
}

void playerPickAxe::release()
{
}

void playerPickAxe::update()
{
	
	switch (_player->getDir())
	{
	case 0:
		_player->setFrameY(26);
		_player->setMaxFrameX(5);
		break;
	case 1:
		_player->setFrameY(27);
		_player->setMaxFrameX(5);

		break;
	case 2:
		_player->setFrameY(25);
		_player->setMaxFrameX(5);
		break;
	case 3:
		_player->setFrameY(24);
		_player->setMaxFrameX(7);
		break;
	}
}

void playerPickAxe::render(HDC hdc)
{
}
#pragma endregion

#pragma region Rod
playerRod::playerRod()
{
}

playerRod::~playerRod()
{
}

HRESULT playerRod::init()
{
	_player = new player;
	return S_OK;
}

void playerRod::release()
{
}

void playerRod::update()
{
}

void playerRod::render(HDC hdc)
{
}
#pragma endregion

#pragma region Sickle
playerSickle::playerSickle()
{
}

playerSickle::~playerSickle()
{
}

HRESULT playerSickle::init()
{
	_player = new player;
	return S_OK;
}

void playerSickle::release()
{
}

void playerSickle::update()
{
	SOUNDMANAGER->play("hitGrass", 1.0f);
	switch (_player->getDir())
	{
	case 0:
		_player->setFrameY(13);
		_player->setMaxFrameX(6);
		break;
	case 1:
		_player->setFrameY(14);
		_player->setMaxFrameX(6);

		break;
	case 2:
		_player->setFrameY(15);
		_player->setMaxFrameX(3);
		break;
	case 3:
		_player->setFrameY(12);
		_player->setMaxFrameX(6);
		break;
	}
}

void playerSickle::render(HDC hdc)
{
}
#pragma endregion


