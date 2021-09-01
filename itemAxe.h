#pragma once
#include "item.h"
class itemAxe : public item
{
	itemAxe();
	~itemAxe();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

