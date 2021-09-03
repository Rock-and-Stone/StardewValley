#include "item.h"

class itemNull :public item
{
private:
public:
	itemNull();
	~itemNull ();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(int x, int y);
};
