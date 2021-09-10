#include "pch.h"
#include "gameScene.h"
#include "player.h"

HRESULT gameScene::init()
{
	_homeMap = new homeMap;
	_player = new player;
	_npcManager = new npcManager;
	_cameraManager = new CameraManager;
	_enemyManager = new EnemyManager;
	_uiManager = new UserInterface;

	_homeMap->init();
	_player->init(10, 15);
	_npcManager->init();
	_cameraManager->init(TILESIZEX, TILESIZEY);
	_enemyManager->init();
	_uiManager->init();
	_uiManager->SetMemoryAddressLink(_player);
	
	_npcManager->setCameraAddressLink(_cameraManager);
	_npcManager->setMarnieCameraLink(_cameraManager);
	_npcManager->setWizardCameraLink(_cameraManager);
	_npcManager->setPlayerMemAddressLink(_player);
	_player->SetInventoryCameraMemoryLink(_cameraManager);
	
	RENDERMANAGER->addRender(_player);


    return S_OK;
}

void gameScene::update()
{
	_cameraManager->update(_player->getX(), _player->getY());
	_player->update();
	_homeMap->Movement(_cameraManager->getCamX(), _cameraManager->getCamY());
	_npcManager->update();
	RENDERMANAGER->update();
}

void gameScene::release()
{
}

void gameScene::render()
{
	//_npcManager->render();
	_homeMap->render();
	_player->setRenderX(_cameraManager->getRenderPosX());
	_player->setRenderY(_cameraManager->getRenderPosY());
	RENDERMANAGER->render(getMemDC());
	_player->InventoryDraw();
	_uiManager->render();
	_npcManager->render();
}
