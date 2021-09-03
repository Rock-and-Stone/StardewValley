#pragma once
#include "item.h"

class itemPickAxe : public item
{
private:
public:
	itemPickAxe();
	~itemPickAxe();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(int x, int y);
};



