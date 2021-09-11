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
	_player->init(30, 30);
	_npcManager->init();
	_objectManager->init();
	_cameraManager->init(TILESIZEX, TILESIZEY);
	_enemyManager->init();
	_uiManager->init();


	_objectManager->SetObjectCameraManagerMemoryLink(_cameraManager);
	_objectManager->SetInventoryMemoryLink(_player->GetInventory());
	_objectManager->SetplayerMemoryLink(_player);

	_player->SetPlayerObjectManagerMemoryLink(_objectManager);
	_player->SetInventoryCameraMemoryLink(_cameraManager);
	_player->SetHomeMapMemoryLink(_homeMap);
	_player->setCameraMemoryLink(_cameraManager);
	_player->setObjectMemoryLink(_objectManager);
	_uiManager->SetMemoryAddressLink(_player);

	_npcManager->setCameraAddressLink(_cameraManager);
	_npcManager->setMarnieCameraLink(_cameraManager);
	_npcManager->setWizardCameraLink(_cameraManager);
	_npcManager->setPlayerMemAddressLink(_player);

	_homeMap->setCameraLink(_cameraManager);
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		//RENDERMANAGER->addRender()
	}

	RENDERMANAGER->addRender(_player);


    return S_OK;
}

void gameScene::update()
{
	if (!GAMEDATA->getIsPause())
	{
		_cameraManager->update(_player->getX(), _player->getY());
		_player->update();
		_objectManager->update();
		//_homeMap->Movement(_cameraManager->getCamX(), _cameraManager->getCamY());
		if (KEYMANAGER->isOnceKeyDown(VK_F9)) _objectManager->SetWood(100, 100, 10);
		RENDERMANAGER->update();
	}
	_npcManager->update();
}

void gameScene::release()
{
}

void gameScene::render()
{
	_homeMap->DrawTile(_cameraManager->getCamX(), _cameraManager->getCamY());
	//_npcManager->render();
	_homeMap->DrawObject(_cameraManager->getCamX(), _cameraManager->getCamY());
	_objectManager->render();
	_player->setRenderX(_cameraManager->getRenderPosX());
	_player->setRenderY(_cameraManager->getRenderPosY());

	RENDERMANAGER->render(getMemDC());

	_player->InventoryDraw();
	_uiManager->render();
	_npcManager->render();
}
