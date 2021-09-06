#pragma once
#include "item.h"
class itemRod : public item
{
private:
public:
	itemRod();
	~itemRod();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(int x, int y);
};

