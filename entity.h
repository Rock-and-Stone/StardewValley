#pragma once
#include "gameNode.h"

class entity : public gameNode
{
public : 
	entity();
	~entity();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual int getRenderPosY();
	virtual bool getReleased();
};