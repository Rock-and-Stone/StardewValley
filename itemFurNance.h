#pragma once
#include "item.h"
class itemFurNance :
    public item
{
private:
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(int x, int y);
};

