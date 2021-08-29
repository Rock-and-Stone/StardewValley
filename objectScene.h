#pragma once
#include "gameNode.h"


class objectScene : public gameNode
{
private:

public:
	HRESULT init();
	void release();
	void update();
	void render();

};

