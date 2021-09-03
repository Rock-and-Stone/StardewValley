#pragma once
#include "object.h"
class sickle :
    public object
{
private:
public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void Draw();
};

