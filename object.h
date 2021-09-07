#pragma once
#include "gameNode.h"

enum ALLOBJECTS
{
	//기본자원
	WOOD,
	STONE,

	//도끼 TOOLS
	AXE,			//도끼
	PICKAXE,		//곡괭이
	HOE,			//호미
	SICKLE,			//낫
	CAN,			//물조리개	
	ROD,			//낚시대

	//무기 WEAPON

	SWORD,			//검
	SLINGSHOT,		//새총

	//물꼬기 FISH

	PUFFERFISH,		//황금뽂어
	TUNA,			//참취
	HALIBUT,		//꽝어

	//씨앗 SEED

	CAULIFLOWERSEED,
	PARSNIPSEED,
	POTATOSEED,
	KALESEED,

	//작물 CROPS

	CAULIFLOWER,	//콜리플라워	350G	195Hp	87Sp	
	PARSNIP,		//파스닙		220G	65Hp	29Sp
	POTATO,			//감자		150G	65Hp	29Sp
	KALE,			//케일		220G	130Hp	58Sp

	//광물 ORE
	COPPER,			//구리		 5G
	IRON,			//철			10G
	GOLD,			//골드		25G

	//제작
	BOX,
	FURNACE,
	SCARECROW1,
	SCARECROW2,
};

class object : public gameNode
{
protected:
	ALLOBJECTS	_obj;
	RECT		_objectRc;
	image*		_objectImg;
	int			_frameX, _frameY;
	float		_posX, _posY;
	float		_speed;
	
	bool		_isdelete;




public:
	object();
	~object();

	virtual HRESULT init(ALLOBJECTS obj, const char* imageName, int framex, int framey, POINT pos);
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void itemSetup();

	void Draw();



	//======================= 접근자 & 설정자 ======================= //
	RECT GetObjectRect() { return _objectRc; }
	void SetObjectRect(RECT rc) { _objectRc = rc; }

	float GetObjectPosX() { return _posX; }
	void SetObjectPosX(float posx) { _posX = posx; }

	float GetObjectPosY() { return _posY; }
	void SetObjectPosY(float posy) { _posY = posy; }

	float GetObjectSpeed() { return _speed; }
	void SetObjectSpeed(float spd) { _speed = spd; }

	bool GetObjectDelete() { return _isdelete; }
	void SetObjectDelete(bool del) { _isdelete = del; }
	//======================= ============== ======================= //
	
	//=======================   메모리 링크   ======================= //
	// 
	//======================= ============== ======================= //
};

