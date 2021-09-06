#pragma once
#include "gameNode.h"
#include "entity.h"
#include "npcManager.h"
#include "homeMap.h"
#include "CameraManager.h"
#include <vector>

class playerScene : public gameNode
{
private:
	entity* _player;
	npcManager* _npcManager;
	homeMap* _homeMap;
	CameraManager* _cameraManager;

	typedef vector<entity*>				_vRender;
	typedef vector<entity*>::iterator   _viRender;

public:
	virtual HRESULT init();
	virtual void update();
	virtual	void release();
	virtual	void render();

};