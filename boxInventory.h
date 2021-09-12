#pragma once
#include "gameNode.h"
#include <vector>
#include "item.h"

class inventory;


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

	tagInven	_boxInven[36];
	tagInven	_invens[36];
	image* _boxUi;
	RECT   _boxUiRc;


	int _upItem;
	int _downItem;

	RECT _rc; //플레이어와 충돌 체크용

	BOOL _drag;
	BOOL _boxOpen;
	

public:
	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();

	BOOL GetBoxOpen() { return _boxOpen; }
	void setBoxOpen(BOOL open) { _boxOpen = open; }


	RECT getRC() { return _rc; }
	void setRC(RECT rc) { _rc = rc; }

	//=======================   메모리 링크   ======================= //

	void Setinventory(inventory* iv) { _inven = iv; }

	//======================= ============== ======================= //
};

