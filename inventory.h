#pragma once
#include "gameNode.h"
#include <vector>
#include "object.h"

#define INVENTORYSIZE 36
#define QUICKSLOTSIZE 12

class button;

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
	string	itemInfo;
	

	int    currentFrameX;
	int	   currentFrameY;

	int	   price;
	int    damage;
	int	   hp;
	int	   sp;
	bool   isbarriable;

	int	   count;			 //각물체의 개수

};

struct tagInventory
{
	tagItemInfo itemInfo;
	RECT	rc;				//메뉴 칸마다 있을 칸들	
};

class inventory : public gameNode
{
private:
	vector<tagItemInfo>				_vInven;
	vector<tagItemInfo>::iterator	_viInven;

	MenuPage _menuPage;

	tagInventory _inven[INVENTORYSIZE];
	tagInventory _quick[QUICKSLOTSIZE];

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
	image* _itemInfoImg;

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
	
	object* _axe;



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

	void SetItems();

	static void Button(void* obj);

	//======================= 접근자 & 설정자 ======================= //
	//		
	//======================= ============== ======================= //

	//=======================   메모리 링크   ======================= //
	// 
	//======================= ============== ======================= //
};







