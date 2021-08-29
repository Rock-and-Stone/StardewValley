#pragma once
#include "gameNode.h"
#include <vector>

#include "axe.h"
#include "pickAxe.h"
#include "hoe.h"
#include "can.h"
#include "rod.h"

#include "sword.h"
#include "slingShot.h"

#include "pufferFish.h"
#include "tuna.h"
#include "haliBut.h"

#include "cauliFlower.h"
#include "parsnip.h"
#include "potato.h"
#include "kale.h"

#include "cauliFlowerSeed.h"
#include "parsnipSeed.h"
#include "potatoSeed.h"
#include "kaleSeed.h"

#include "copper.h"
#include "iron.h"
#include "gold.h"


class objectManager : public gameNode
{
private:
	vector<object*>				_vObject;
	vector<object*>::iterator	_viObject;

private:
	//도구
	axe*				_axe;
	pickAxe*			_pickAxe;
	hoe*				_hoe;
	can*			    _can;
	rod*				_rod;
	//무기
	sword*				_sword;
	slingShot*			_slingShot;
	//생선
	pufferFish*			_pufferFish;
	tuna*				_tuna;
	haliBut*			_halibut;
	//씨앗
	cauliFlowerSeed*	_cauliFlowerSeed;
	parsnipSeed*		_parsnipSeed;
	potatoSeed*			_potatoSeed;
	kaleSeed*			_kaleSeed;
	//작물
	cauliFlower*		_cauliFlower;
	parsnip*			_parsnip;
	potato*				_potato;
	kale*				_kale;
	//광물
	copper*				_copper;
	iron*				_iron;
	gold*				_gold;

	


	int _objectNum;



public:
	objectManager();
	~objectManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//도구 
	void SetAxe();
	void SetPickAxe();
	void SetHoe();
	void SetCan();
	void SetRod();
	//무	기
	void SetSword();
	void SetSlingShot();
	//생	선
	void SetPufferFish();
	void SetTuna();
	void SetHaliBut();
	//씨	앗
	void SetCauliFlowerSeed();
	void SetParsnipSeed();
	void SetPotatoSeed();
	void SetKaleSeed();
	//작물
	void SetCauliFlower();
	void SetParsnip();
	void SetPotato();
	void SetKale();
	//광물
	void SetCopper();
	void SetIron();
	void SetGold();


	//======================= 접근자 & 설정자 ======================= //
	vector<object*> GetVObject() { return _vObject; }
	vector<object*>::iterator GetVIObject() { return _viObject; }

	//======================= ============== ======================= //
	//=======================   메모리 링크   ======================= //
	// 
	//======================= ============== ======================= //








};

