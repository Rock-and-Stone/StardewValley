#pragma once
#include "object.h"
class wood : public object
{
private:


public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();

};

