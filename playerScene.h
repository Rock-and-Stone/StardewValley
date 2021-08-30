#pragma once
#include "gameNode.h"
#include "entity.h"
#include "npcManager.h"

class playerScene : public gameNode
{
private:
	entity* _player;
	npcManager* _npcManager;

public:
	virtual HRESULT init();
	virtual void update();
	virtual	void release();
	virtual	void render();
};