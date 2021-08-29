#pragma once
#include "gameNode.h"
#include <vector>
#include "object.h"

#define INVENTORYSIZE 36
#define QUICKSLOTSIZE 12




struct ItemInfo
{
	image* itemImg;
	string itemName;
	string type;

	//메뉴 칸마다 있을 칸들
	RECT	rc;
};

class inventory : public gameNode
{
private:
	vector <object*>			_vItems;
	vector <object*>::iterator  _viItems;


	ItemInfo _items[INVENTORYSIZE];

	//현재 보고있는 메뉴 이미지
	image* _currentMenuImg;

	//퀵슬롯
	image* _quickSlot;

	//퀵슬롯창
	RECT	_quickSlotRc;

	//메인 메뉴창
	RECT	_menuRc;

	//메뉴 이미지스
	image* _invenImg;
	image* _statImg;
	image* _craftImg;
	image* _settingImg;
	image* _exitImg;

	//메뉴바꾸는 버튼스?
	RECT	_storageRc;
	RECT	_statRc;
	RECT	_craftRc;
	RECT	_settingRc;
	RECT	_exitRc;



	//창활성화용 

	BOOL	_isMenuOpen;				//메뉴창
	BOOL	_isInvenOpen;				//인벤창
	BOOL	_isStatOpen;				//스탯창
	BOOL	_isCraftOpen;				//제작창
	BOOL	_isSettingOpen;				//설정창
	BOOL	_isExitOpen;				//탈출창







public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	void MenuOpen();
	void InvetoryOpen();
	void StatOpen();
	void CraftOpen();
	void SettingOpen();
	void ExitOpen();
	void SelectMenu();




	void ClickObject();
	void DragObject();
	void DragObjectToSwap();
};

