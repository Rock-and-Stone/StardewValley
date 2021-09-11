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
	_objectManager = new objectManager;

	_homeMap->init();
	_player->init(10, 15);
	_npcManager->init();
	_objectManager->init();
	_cameraManager->init(TILESIZEX, TILESIZEY);
	_enemyManager->init();
	_uiManager->init();


	_objectManager->SetInventoryMemoryLink(_player->GetInventory());
	_player->SetPlayerObjectManagerMemoryLink(_objectManager);
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
	_homeMap->Movement(_player->getX(), _player->getY());
	_objectManager->update();
	if (KEYMANAGER->isOnceKeyDown(VK_F9)) _objectManager->SetWood(100, 100, 10);

	RENDERMANAGER->update();
	
}

void gameScene::release()
{
}

void gameScene::render()
{
	//_npcManager->render();
	_homeMap->render();
	_objectManager->render();
	_player->setRenderX(_cameraManager->getRenderPosX());
	_player->setRenderY(_cameraManager->getRenderPosY());

	RENDERMANAGER->render(getMemDC());

	_player->InventoryDraw();
	_uiManager->render();
	_npcManager->render();

}
