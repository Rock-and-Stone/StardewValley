#pragma once
#include "object.h"
class pickAxe : public object
{
private:
public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void Draw();
};

