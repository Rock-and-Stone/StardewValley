#pragma once
#include "gameNode.h"

//전체아이템 
enum ALLITEMS
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

	//NONE;
	NONE
};
enum CRAFTITEMS
{
	BOX,
	FURNACE,
	SCARECROW1,
	SCARECROW2,
};
struct ITEMS
{
	//구조체로 집어넣자
	ALLITEMS    items;						//아이템이 뭔지
	CRAFTITEMS  craftItems;
	image*		itemImg;					//오브젝트 이미지

	//인벤토리에서 띄줄것들
	string			itemName;					//아이템 이름
	string			itemInfo;					//아이템 설명

	POINT		pos;

	//아이템이 가지는 정보
	int			frameX, frameY;			    //아이템이미지 위치
	int			buyPrice;					//아이템의 구매가
	int			sellPrice;					//아이템의 판매가격
	int			damage;						//공격력
	int			hP;							//체력을 채워준다.
	int			sP;							//스태미나를 채워준다.
	//int			amount;						//갯수

	int			needAmountToCraft;			//제작하는데 필요한 갯수
	int			itemNum;                    // 아이템 고유 넘버

	BOOL		isHandleAble;				//손에보여지는 물건?
	BOOL		isEatAble;					//먹을수 있는 물건
};


class item : public gameNode
{
protected:
	ITEMS _item;

public:
	item();
	~item();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(int x, int y);


	//void amountAdd() { _item.amount++; }

	//======================= 접근자 & 설정자 ======================= //
	ITEMS GetItemInfo() { return _item; }
	void  SetItemInfo(ITEMS item) { _item = item; }
	//======================= ============== ======================= //
	

	//=======================   메모리 링크   ======================= //
	// 
	//======================= ============== ======================= //

};

