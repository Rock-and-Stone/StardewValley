#pragma once
#include "item.h"
class itemScareCrow2 :
    public item
{
private:
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(int x, int y);
};

