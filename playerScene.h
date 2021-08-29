#pragma once
#include "gameNode.h"
#include "entity.h"

class playerScene : public gameNode
{
private:
	entity* _player;

public:
	virtual HRESULT init();
	virtual void update();
	virtual	void release();
	virtual	void render();
};