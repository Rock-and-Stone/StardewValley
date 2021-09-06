#pragma once
#include "gameNode.h"
#include <vector>

#include "axe.h"
#include "pickAxe.h"
#include "sickle.h"
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
	sickle*				_sickle;
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
	void SetAxe(float x,float y, int amount);
	void SetPickAxe(float x, float y, int amount);
	void SetHoe(float x, float y, int amount);
	void SetCan(float x, float y, int amount);
	void SetRod(float x, float y, int amount);
	void SetSickle(float x, float y, int amount);

	//무	기
	void SetSword(float x, float y, int amount);
	void SetSlingShot(float x, float y, int amount);

	//생	선
	void SetPufferFish(float x, float y, int amount);
	void SetTuna(float x, float y, int amount);
	void SetHaliBut(float x, float y, int amount);

	//씨	앗
	void SetCauliFlowerSeed(float x, float y, int amount);
	void SetParsnipSeed(float x, float y, int amount);
	void SetPotatoSeed(float x, float y, int amount);
	void SetKaleSeed(float x, float y, int amount);

	//작물
	void SetCauliFlower(float x, float y, int amount);
	void SetParsnip(float x, float y, int amount);
	void SetPotato(float x, float y, int amount);
	void SetKale(float x, float y, int amount);

	//광물
	void SetCopper(float x, float y, int amount);
	void SetIron(float x, float y, int amount);
	void SetGold(float x, float y, int amount);


	//======================= 접근자 & 설정자 ======================= //
	vector<object*> GetVObject() { return _vObject; }
	vector<object*>::iterator GetVIObject() { return _viObject; }

	//======================= ============== ======================= //
	//=======================   메모리 링크   ======================= //
	// 
	//======================= ============== ======================= //








};

