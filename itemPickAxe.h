#pragma once
#include "item.h"

class itemPickAxe : public item
{
private:
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

