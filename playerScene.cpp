#include "pch.h"
#include "playerScene.h"
#include "player.h"

HRESULT playerScene::init()
{
	_player = new player;
	_player->init(5,5);

	_npcManager = new npcManager;
	_npcManager->init();

	return S_OK;
}

void playerScene::update()
{
	_player->update();
	_npcManager->update();
}

void playerScene::release()
{
}

void playerScene::render()
{
	_player->render();
	_npcManager->render();
}
