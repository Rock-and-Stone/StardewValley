#pragma once
#include "gameNode.h"
#include <vector>
#include "object.h"
#include "button.h"

#define INVENTORYSIZE 36
#define QUICKSLOTSIZE 12


enum MenuPage
{
	InvenPage,
	StatPage,
	CraftPage,
	SettingPage,
	ExitPage,
};

struct tagItemInfo
{
	image* itemImg;
	string  itemName;
	int	   count;			 //각물체의 개수
	int    currentFrameX;
	int	   currentFrameY;
};

struct tagInventory
{
	tagItemInfo itemInfo;
	RECT	rc;				//메뉴 칸마다 있을 칸들	
};

class inventory : public gameNode
{
private:

	MenuPage _menuPage;

	tagInventory _inven[INVENTORYSIZE];

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

	//메뉴가 열렷는지
	BOOL _isMenuOpen;

	//드래그 중인지
	BOOL _dragActivate;

	//집었을때 인덱스
	int _downPtItem;
	//놓았을때 인덱스
	int _upPtItem;

	//버튼스
	button* _buttonToMenu;
	button* _buttonExit;
	




public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	void MenuOpen();
	void SelectMenu();

	void MenuInvetoryOpen();
	void MenuStatOpen();
	void MenuCraftOpen();
	void MenuSettingOpen();
	void MenuExitOpen();


	static void Button(void* obj);
};

