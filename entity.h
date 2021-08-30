#pragma once
#include "gameNode.h"

#define TILEWIDTH 32
#define TILEHEIGHT 32

class entity : public gameNode
{
public : 
	entity();
	~entity();

	virtual HRESULT init();
	virtual HRESULT init(int indX, int indY);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual int getRenderPosY();
	virtual bool getReleased();
};