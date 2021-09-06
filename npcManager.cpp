#include "pch.h"
#include "npcManager.h"
#include "marnie.h"
#include "wizard.h"
#include "CameraManager.h"

npcManager::npcManager()
{
}

npcManager::~npcManager()
{
}

HRESULT npcManager::init()
{
	_marnie = new marnie;
	_wizard = new wizard;

	_marnie->init(10, 10);
	_wizard->init(10, 20);

	RENDERMANAGER->addRender(_marnie);
	RENDERMANAGER->addRender(_wizard);

	return S_OK;
}

void npcManager::release()
{
}

void npcManager::update()
{
}

void npcManager::render()
{
	char str[25];
	sprintf_s(str, "%d, %d", _marnie->getRenderPosY(), _wizard->getRenderPosY());
	TextOut(getMemDC(), 200, 300, str, strlen(str));
}
