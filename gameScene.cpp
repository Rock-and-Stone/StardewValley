#include "pch.h"
#include "gameScene.h"
#include "player.h"

HRESULT gameScene::init()
{
	_player = new player;
	_npcManager = new npcManager;
	_cameraManager = new CameraManager;
	_enemyManager = new EnemyManager;
	_uiManager = new UserInterface;


	_player->init(10, 15);
	_npcManager->init();
	_cameraManager->init(TILESIZEX, TILESIZEY);
	_enemyManager->init();
	_uiManager->init();


	
	
	_npcManager->setCameraAddressLink(_cameraManager);
	_npcManager->setMarnieCameraLink(_cameraManager);
	_npcManager->setWizardCameraLink(_cameraManager);
	_player->SetInventoryCameraMemoryLink(_cameraManager);
	RENDERMANAGER->addRender(_player);


    return S_OK;
}

void gameScene::update()
{
	_cameraManager->update(_player->getX(), _player->getY());
	_player->update();

	RENDERMANAGER->update();
}

void gameScene::release()
{
}

void gameScene::render()
{
	_player->setRenderX(_cameraManager->getRenderPosX());
	_player->setRenderY(_cameraManager->getRenderPosY());

	_npcManager->render();

	RENDERMANAGER->render(getMemDC());

}
