#pragma once
#include "item.h"
class itemSickle :
    public item
{
private:
public:
	itemSickle();
	~itemSickle();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(int x, int y);
};

