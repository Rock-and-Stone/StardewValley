#include "pch.h"
#include "playerScene.h"
#include "player.h"

HRESULT playerScene::init()
{
	_player = new player;
	_player->init();
	return S_OK;
}

void playerScene::update()
{
	_player->update();
}

void playerScene::release()
{
}

void playerScene::render()
{
	_player->render();
}
