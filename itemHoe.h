#pragma once
#include "item.h"
class itemHoe :
    public item
{
private:
public:
	itemHoe();
	~itemHoe();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(int x, int y);
};

