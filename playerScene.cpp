#include "pch.h"
#include "playerScene.h"
#include "player.h"

HRESULT playerScene::init()
{
	_player = new player;
	_player->init(10,15);

	_npcManager = new npcManager;
	_npcManager->init();

	_homeMap = new homeMap;
	_homeMap->init();

	_cameraManager = new CameraManager;
	_cameraManager->init(TILESIZEX,TILESIZEY);

	_player->setMapAddressLink(_homeMap);
	_homeMap->setCameraLink(_cameraManager);
	_npcManager->setCameraAddressLink(_cameraManager);
	_npcManager->setMarnieCameraLink(_cameraManager);
	_npcManager->setWizardCameraLink(_cameraManager);

	RENDERMANAGER->addRender(_player);	

	return S_OK;
}

void playerScene::update()
{
	_cameraManager->update(_player->getX(), _player->getY());
	_player->update();
	_homeMap->update();
	_npcManager->update();
	RENDERMANAGER->update();
}

void playerScene::release()
{
}

void playerScene::render()
{
	IMAGEMANAGER->addImage("bg","source/Sprite/background.bmp",2560, 2080,true,MAGENTA)->render(getMemDC(),0,0, _cameraManager->getCamX(), _cameraManager->getCamY(),WINSIZEX,WINSIZEY);

	_player->setRenderX(_cameraManager->getRenderPosX());
	_player->setRenderY(_cameraManager->getRenderPosY());

	//_homeMap->render();
	_npcManager->render();

	RENDERMANAGER->render(getMemDC());

	char str[25];
	sprintf_s(str, "%d", _player->getRenderPosY());
	TextOut(getMemDC(), 300, 200, str, strlen(str));
}
