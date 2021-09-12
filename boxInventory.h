#pragma once
#include "gameNode.h"
#include <vector>
#include "item.h"

class inventory;

struct tagBoxInven
{
	int amount;
	bool itemExist;
	RECT rc;
};
struct tagInven
{
	int amount;
	bool itemExist;
	RECT rc;
};


class boxInventory : public gameNode
{
private:
	vector<item*>			_vBox;
	vector<item*>::iterator _viBox;

	inventory* _inven;

	tagBoxInven _boxInven[36];
	tagInven	_invens[36];
	image* _boxUi;
	RECT   _boxUiRc;


	


	BOOL _boxOpen;
	


public:
	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();
	//=======================   메모리 링크   ======================= //

	void Setinventory(inventory* iv) { _inven = iv; }
	//======================= ============== ======================= //
};

