#pragma once

#include "entity.h"

class marnie : public entity
{
private:
	RECT _rc;
	image* _img;
	int _x, _y;   //ÁßÁ¡


public:
	marnie();
	~marnie();

	HRESULT init(int indX, int indY);
	void release();
	void update();
	void render();
};

