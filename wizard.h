#pragma once
#include "entity.h"

class wizard : public entity
{
private:
	RECT _rc;
	image* _img;
	int _x, _y;   //ÁßÁ¡

public:
	wizard();
	~wizard();
	HRESULT init(int indX, int indY);
	void release();
	void update();
	void render();
};

