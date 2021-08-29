#include "pch.h"
#include "UserInterface.h"

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
}
