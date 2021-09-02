#pragma once
#include "gameNode.h"
#include "itemAxe.h"
#include "itemPickAxe.h"
class itemManager : public gameNode
{
private:
	itemAxe* _axe;
	itemPickAxe* _pickAxe;


public:
	itemManager();
	~itemManager();


	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();




	//======================= 접근자 & 설정자 ======================= //
	//
	//======================= ============== ======================= //

	//=======================   메모리 링크   ======================= //
	// 
	//======================= ============== ======================= //
};

