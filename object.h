#pragma once
#include "gameNode.h"


class CameraManager;

enum ALLOBJECTS
{
	//기본자원
	OBJ_WOOD,
	OBJ_STONE,

	//무기 WEAPON

	OBJ_SWORD,			//검
	OBJ_SLINGSHOT,		//새총

	//물꼬기 FISH

	OBJ_PUFFERFISH,		//황금뽂어
	OBJ_TUNA,			//참취
	OBJ_HALIBUT,		//꽝어

	//씨앗 SEED

	OBJ_CAULIFLOWERSEED,
	OBJ_PARSNIPSEED,
	OBJ_POTATOSEED,
	OBJ_KALESEED,

	//작물 CROPS
	
	OBJ_CAULIFLOWER,	//콜리플라워	350G	195Hp	87Sp	
	OBJ_PARSNIP,		//파스닙		220G	65Hp	29Sp
	OBJ_POTATO,			//감자		150G	65Hp	29Sp
	OBJ_KALE,			//케일		220G	130Hp	58Sp

	//광물 ORE
	OBJ_COPPER,			//구리		 5G
	OBJ_IRON,			//철			10G
	OBJ_GOLD,			//골드		25G
	
	//제작
	OBJ_BOX,
	OBJ_FURNACE,
	OBJ_SCARECROW1,
	OBJ_SCARECROW2,
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
	int			_objectNum;
	bool		_isdelete;

	CameraManager* _cm;


public:
	object();
	~object();

	virtual HRESULT init(ALLOBJECTS obj, const char* imageName, int framex, int framey, POINT pos, int objNum);
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void itemSetup();

	void Draw(int camX,int camY);



	//======================= 접근자 & 설정자 ======================= //
	ALLOBJECTS GetObjectType() { return _obj; }

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
	void SetCameraManagerMemoryLink(CameraManager* cm) { _cm = cm; }

	//======================= ============== ======================= //
};

