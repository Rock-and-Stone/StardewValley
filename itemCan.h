#pragma once
#include "item.h"
class itemCan :
    public item
{
private:

public:
	itemCan();
	~itemCan();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(int x, int y);
};

