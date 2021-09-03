#pragma once
#include "gameNode.h"
#include "itemAxe.h"
#include "itemPickAxe.h"
#include "itemNull.h"

class itemManager : public gameNode
{
private:
	typedef vector<item*>			vitem;
	typedef vector<item*>::iterator viItem;


private:
	vitem	_vitem;
	viItem	_viItem;


	itemAxe* _axe;
	itemPickAxe* _pickAxe;
	itemNull* _null;


public:
	itemManager();
	~itemManager();


	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void SetNull();
	void SetAxe();
	void SetPickAxe();





	//======================= 접근자 & 설정자 ======================= //
	vector<item*>  Getvitem() { return _vitem; }
	vector<item*>::iterator GetviItem() { return _viItem; }



	//======================= ============== ======================= //

	//=======================   메모리 링크   ======================= //
	// 
	//======================= ============== ======================= //
};

