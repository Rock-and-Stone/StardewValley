#pragma once
#include "item.h"

class itemAxe : public item
{
private:

public:
	itemAxe();
	~itemAxe();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(int x, int y);
};

