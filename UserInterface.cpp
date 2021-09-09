#include "pch.h"
#include "UserInterface.h"
#include "player.h"

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
}

HRESULT UserInterface::init()
{
	_clock = new Clock;
	_clock->init();

	_mouse = new MouseSetting;
	_mouse->init();

	IMAGEMANAGER->addFrameImage("goldNum", "source/Images/mainScene/goldNumber.bmp", 224, 26, 10, 1, true, MAGENTA);
	_gold10000000 = IMAGEMANAGER->findImage("goldNum");
	_gold1000000 = IMAGEMANAGER->findImage("goldNum");
	_gold100000 = IMAGEMANAGER->findImage("goldNum");
	_gold10000 = IMAGEMANAGER->findImage("goldNum");
	_gold1000 = IMAGEMANAGER->findImage("goldNum");
	_gold100 = IMAGEMANAGER->findImage("goldNum");
	_gold10 = IMAGEMANAGER->findImage("goldNum");
	_gold1 = IMAGEMANAGER->findImage("goldNum");
	return S_OK;
}

void UserInterface::release()
{
}

void UserInterface::update()
{
	_clock->update();
	_mouse->update();
}

void UserInterface::render()
{
	_clock->render();
	_mouse->render();

	_gold10000000->frameRender(getMemDC(), 1045, 212, _player->getGold() / 10000000, 0);
	_gold1000000->frameRender(getMemDC(), 1069, 212, _player->getGold() % 10000000/1000000, 0);
	_gold100000->frameRender(getMemDC(), 1093, 212, _player->getGold() % 1000000 / 100000, 0);
	_gold10000->frameRender(getMemDC(), 1117, 212, _player->getGold() % 100000 / 10000, 0);
	_gold1000->frameRender(getMemDC(), 1141, 212, _player->getGold() % 10000 / 1000, 0);
	_gold100->frameRender(getMemDC(), 1165, 212, _player->getGold() % 1000 / 100, 0);
	_gold10->frameRender(getMemDC(), 1189, 212, _player->getGold() % 100 / 10, 0);
	_gold1->frameRender(getMemDC(), 1213, 212, _player->getGold() % 10, 0);

	char str[256];
	sprintf_s(str, "%d %d", _ptMouse.x, _ptMouse.y);
	TextOut(getMemDC(), _ptMouse.x, _ptMouse.y, str, strlen(str));
}
