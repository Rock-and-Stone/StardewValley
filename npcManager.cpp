#include "pch.h"
#include "npcManager.h"
#include "marnie.h"
#include "wizard.h"

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

	_marnie->init(3, 4);
	_wizard->init(5, 5);

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
	_marnie->render();
	_wizard->render();
}
