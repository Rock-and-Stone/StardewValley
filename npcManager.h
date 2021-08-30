#pragma once
#include "gameNode.h"
#include "entity.h"

class npcManager : public gameNode
{
private:
	entity* _marnie;
	entity* _wizard;

public:
	npcManager();
	~npcManager();

	HRESULT init();
	void release();
	void update();
	void render();
};

