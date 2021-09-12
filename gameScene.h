#pragma once
#include "gameNode.h"
#include "homeMap.h"
//#include "player.h" //<- inventory 포함
#include "npcManager.h"
#include "EnemyManager.h"
#include "objectManager.h"
#include "entity.h"
#include "UserInterface.h"
#include "boxInventory.h"


class gameScene : public gameNode
{
private:
	entity* _player;	//플레이어
	npcManager* _npcManager; //NPC 매니져
	EnemyManager* _enemyManager; //에너미 매니져
	homeMap* _homeMap;
	CameraManager* _cameraManager; //카메라매니져
	objectManager* _objectManager; //오브젝트 매니져
	UserInterface* _uiManager;
	boxInventory* _boxIv;



public:
	virtual HRESULT init();
	virtual void update();
	virtual	void release();
	virtual	void render();
};

