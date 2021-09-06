#pragma once
#include "gameNode.h"
#include <vector>


#include "itemAxe.h"
#include "itemCan.h"
#include "itemHoe.h"
#include "itemRod.h"
#include "itemSickle.h"
#include "itemPickAxe.h"
#include "itemNull.h"




#define INVENTORYSIZE 36
#define QUICKSLOTSIZE 36

class button;

enum MenuPage
{
	InvenPage,
	StatPage,
	CraftPage,
	SettingPage,
	ExitPage,
};

struct tagInventory
{
	int		amount;
	bool	itemExist;
	RECT	rc;				//메뉴 칸마다 있을 칸들	
};

class inventory : public gameNode
{
private:
	vector<item*>				_vInven;
	vector<item*>::iterator		_viInven;

	vector<item*>				_vItemInfo;
	vector<item*>::iterator		_viItemInfo;


	//아이템 정보들
	itemAxe* _axe;
	itemPickAxe* _pickAxe;
	itemCan* _can;
	itemHoe* _hoe;
	itemRod* _rod;
	itemSickle* _sickle;

	itemNull* _null;


	//itemManager* _itemManager;

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

	int _quickSlotMin;
	int _quickSlotMax;

	BOOL	_invenIsFull;

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

	void QuickSlot();
	void MenuInvetoryOpen();
	void MenuStatOpen();
	void MenuCraftOpen();
	void MenuSettingOpen();
	void MenuExitOpen();

	//NULL값 있는 벡터는 지우고 값넣는 
	void AddItem(item* item);
	
	void AddAmount();

	static void Button(void* obj);

	//======================= 접근자 & 설정자 ======================= //
	//		
	//======================= ============== ======================= //

	//=======================   메모리 링크   ======================= //
	// 
	//======================= ============== ======================= //
};







