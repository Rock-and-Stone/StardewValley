#pragma once
#include "gameNode.h"

enum ALLOBJECTS
{
	//±âº»ÀÚ¿ø
	WOOD,
	STONE,

	//µµ³¢ TOOLS
	AXE,			//µµ³¢
	PICKAXE,		//°î±ªÀÌ
	HOE,			//È£¹Ì
	SICKLE,			//³´
	CAN,			//¹°Á¶¸®°³	
	ROD,			//³¬½Ã´ë

	//¹«±â WEAPON

	SWORD,			//°Ë
	SLINGSHOT,		//»õÃÑ

	//¹°²¿±â FISH

	PUFFERFISH,		//È²±Ý–Ã¾î
	TUNA,			//ÂüÃë
	HALIBUT,		//²Î¾î

	//¾¾¾Ñ SEED

	CAULIFLOWERSEED,
	PARSNIPSEED,
	POTATOSEED,
	KALESEED,

	//ÀÛ¹° CROPS

	CAULIFLOWER,	//ÄÝ¸®ÇÃ¶ó¿ö	350G	195Hp	87Sp	
	PARSNIP,		//ÆÄ½º´Õ		220G	65Hp	29Sp
	POTATO,			//°¨ÀÚ		150G	65Hp	29Sp
	KALE,			//ÄÉÀÏ		220G	130Hp	58Sp

	//±¤¹° ORE
	COPPER,			//±¸¸®		 5G
	IRON,			//Ã¶			10G
	GOLD,			//°ñµå		25G

	//NONE;
	NONE
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



	//======================= Á¢±ÙÀÚ & ¼³Á¤ÀÚ ======================= //
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
	
	//=======================   ¸Þ¸ð¸® ¸µÅ©   ======================= //
	// 
	//======================= ============== ======================= //
};

