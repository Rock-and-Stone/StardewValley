#include "pch.h"
#include "loadingScene.h"
#include "progressBar.h"

loadingScene::loadingScene()
	: _background(nullptr), 
	_loadingBar(nullptr),
	_currentCount(0)
{
}


loadingScene::~loadingScene()
{
}

HRESULT loadingScene::init()
{
	_background = IMAGEMANAGER->addImage("배경", "source/Images/loadingScene/blackWindow.bmp", WINSIZEX, WINSIZEY, true, MAGENTA);

	/*_loadingBar = new progressBar;
	_loadingBar->init(0, WINSIZEY - 50, WINSIZEX, 50);
	_loadingBar->setGauge(0, 0);*/

	IMAGEMANAGER->addFrameImage("loading", "source/Images/loadingScene/loading.bmp", 822, 62, 3, 1, true, MAGENTA);
	_loadingImg = IMAGEMANAGER->findImage("loading");
	_frameX = 0;
	_count = 0;

	CreateThread(
		NULL,				//스레드 보안속성(자식윈도우 존재할때)
		NULL,				//스레드의 스택크기(0이면 메인쓰레드 동일)
		threadFunction,		//사용할 함수
		this,				//스레드 매개변수(this 로 뒀으니 본 클래스)
		NULL,				//스레드 특성
		NULL);				//스레드 ID

	return S_OK;
}

void loadingScene::release()
{
	SAFE_DELETE(_loadingBar);
}

void loadingScene::update()
{
 /* _loadingBar->update();
  _loadingBar->setGauge(_currentCount, LOADINGMAX);*/

	if (_currentCount == LOADINGMAX)
	{
		//이동할 씬 으로 변경
		SCENEMANAGER->changeScene("gameScene");
	}

	_count++;

	if (_count % 30 == 0)
	{
		_frameX++;
	}
	if (_frameX >= 3) _frameX = 0;
}
  
void loadingScene::render()
{
	_background->render(getMemDC());
	//_loadingBar->render();
	_loadingImg->frameRender(getMemDC(), 50, WINSIZEY - 100, _frameX, 0);
}

DWORD CALLBACK threadFunction(LPVOID lpParameter)
{
	loadingScene* loadingHelper = (loadingScene*)lpParameter;


	while (loadingHelper->_currentCount != LOADINGMAX)
	{
		//소스 파일 추가	
		IMAGEMANAGER->addFrameImage("player", "source/Images/플레이어이미지3.bmp", 1152, 4352, 12, 34, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("marnie", "source/Images/NPC/npc_item.bmp", 128, 256, 4, 4, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("wizard", "source/Images/NPC/npc_skill.bmp",128, 256, 4, 4, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("fisher", "source/Images/NPC/할아버지.bmp", 64, 128, 4, 4, true, MAGENTA);
		IMAGEMANAGER->addImage("dialogueBox", "source/Images/초상화대화.bmp", 720, 278, true, MAGENTA);
		IMAGEMANAGER->addImage("shopBox", "source/Images/shop_itemslot.bmp", 640, 64, true, MAGENTA);
		//소스 파일 추가
		//
		// 인벤토리 UI
		IMAGEMANAGER->addImage("itemInventory",		"source/Images/inventory/itemInventory.bmp", 750, 550, true, MAGENTA);
		// 퀵슬롯 UI
		IMAGEMANAGER->addImage("quickSlot",			"source/Images/inventory/playerQuickslot.bmp", 565, 69, true, MAGENTA);
		// 제작메뉴
		IMAGEMANAGER->addImage("craftMenu",			"source/Images/inventory/Craftinven.bmp", 750, 550, true, MAGENTA);
		// 스탯메뉴
		IMAGEMANAGER->addImage("statMenu",			"source/Images/inventory/skill.bmp", 750, 550, true, MAGENTA);
		// 설정메뉴
		IMAGEMANAGER->addImage("settingMenu",		"source/Images/inventory/setting.bmp", 750, 550, true, MAGENTA);
		// 나가기메뉴
		IMAGEMANAGER->addImage("exitMenu",			"source/Images/inventory/exit.bmp", 750, 550, true, MAGENTA);
		// 아이템 정보
		IMAGEMANAGER->addImage("itemInfo",			"source/Images/shop/item_info.bmp", 210, 210, true, MAGENTA);
		//닫기 아이콘
		IMAGEMANAGER->addImage("closeButton",		"source/Images/inventory/닫기버튼.bmp", 44, 44, true, MAGENTA);
		
		IMAGEMANAGER->addImage("Storage", "source/Images/inventory/playerStorage.bmp", 653, 430, true, MAGENTA);

		//모든 오브젝트
		IMAGEMANAGER->addFrameImage("springObjectsItem", "source/Images/springobjects4.bmp", 768,1088, 24, 34, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("springObjects", "source/Images/springobjects2.bmp", 960, 1360, 24, 34, true, MAGENTA);
		////도구 인벤토리
		IMAGEMANAGER->addFrameImage("playerTool",	"source/Images/playerInventory/playerTool.bmp", 280, 40, 7, 1, true, MAGENTA); // 플레이어 도구
		//씨앗 아이템
		IMAGEMANAGER->addFrameImage("seedItem",		"source/Images/BMP/씨앗아이템(original).bmp", 360, 160, 9, 4, true, MAGENTA);
		//씨앗 아이템아이콘용
		IMAGEMANAGER->addFrameImage("seedItemSmall","source/Images/BMP/small씨앗아이템(original).bmp", 144, 64, 9, 4, true, MAGENTA);
		//작물
		IMAGEMANAGER->addFrameImage("crops",		"source/Images/BMP/열매(ori).bmp", 640, 120, 16, 3, true, MAGENTA);
		//작물 아이콘
		IMAGEMANAGER->addFrameImage("cropsSmall",	"source/Images/BMP/열매small(ori).bmp", 256, 48, 16, 3, true, MAGENTA);

		//광물 
		IMAGEMANAGER->addFrameImage("ores",			"source/Images/BMP/oreItem.bmp", 640, 200, 16, 5, true, MAGENTA);


		//오브젝트아이템
		IMAGEMANAGER->addFrameImage("craftItems",	 "source/Images/inventory/craftItem3.bmp", 160, 40, 4, 1, true, MAGENTA);

		//오브젝트
		IMAGEMANAGER->addFrameImage("craftObject",	 "source/Images/inventory/craftObject2.bmp", 160, 80, 4, 1, true, MAGENTA);
		//오브젝트알파
		IMAGEMANAGER->addFrameImage("craftObjectAlpha", "source/Images/inventory/craftObjectAlpha2.bmp", 160, 80, 4, 1, true, MAGENTA);

		//배치용 오브젝트
		IMAGEMANAGER->addFrameImage("craftObjectSmall", "source/Images/inventory/craftObjectSmall1.bmp", 176, 32, 11, 1, true, MAGENTA);

		
			
		//==================몬스터 부분 파일 추가 본=====================
		//이미지
		IMAGEMANAGER->addFrameImage("RockStone", "source/Images/monster/RockStone.bmp", 52, 60, 4, 4, true, MAGENTA);

		//==================UI 부분 파일 추가 본=====================
		//이미지
		IMAGEMANAGER->addImage("title",			"source/Images/mainScene/title.bmp", 690, 318, true, MAGENTA);
		IMAGEMANAGER->addImage("mainScene",		"source/Images/mainScene/mainScene.bmp", WINSIZEX, WINSIZEY, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("start",	"source/Images/mainScene/start.bmp", 185, 292, 1, 2, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("load",		"source/Images/mainScene/load.bmp", 185, 292, 1, 2, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("mapTool",  "source/Images/mainScene/mapTool.bmp", 185, 292, 1, 2, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("exit",		"source/Images/mainScene/exit.bmp", 185, 292, 1, 2, true, MAGENTA);
		IMAGEMANAGER->addFrameImage("back",		"source/Images/mainScene/back.bmp", 198, 162, 1, 2, true, MAGENTA);
		

		//사운드
		//SOUNDMANAGER->addSound("bugCave", "source/Sounds/bugCave.mp3", true, true);				//동굴 소리
		//SOUNDMANAGER->addSound("character", "source/Sounds/character.mp3", true, false);		//띠링 띠리리리리링 소리
		SOUNDMANAGER->addSound("death", "source/Sounds/death.mp3", true, false);				//죽을 때 나는 소리
		SOUNDMANAGER->addSound("doorOpen", "source/Sounds/doorOpen.mp3", true, false);			//문열 때 나는 소리
		SOUNDMANAGER->addSound("springBGM", "source/Sounds/springBGM.mp3", true, true);			//인게임 배경 음악
		//SOUNDMANAGER->addSound("fireSpell", "source/Sounds/fireSpell.mp3", true, false);		//용광로 불지피는 소리
		SOUNDMANAGER->addSound("getItem", "source/Sounds/getItem.mp3", true, false);			//아이템 주울 때 나는 소리
		SOUNDMANAGER->addSound("hitGrass", "source/Sounds/hitGrass.mp3", true, false);			//낫으로 풀 벨 때 나는 효과음
		SOUNDMANAGER->addSound("hitRock", "source/Sounds/hitRock.mp3", true, false);			//곡괭이로 돌 때릴 때 나는 효과음
		SOUNDMANAGER->addSound("hitTree", "source/Sounds/hitTree.mp3", true, false);			//도끼로 나무 때릴 때 나는 효과음
		SOUNDMANAGER->addSound("hitPlayer", "source/Sounds/hitPlayer.mp3", true, false);		//공격 할 때 나는 소리
		SOUNDMANAGER->addSound("hoe", "source/Sounds/hoe.mp3", true, false);					//밭 갈때 나는 소리
		SOUNDMANAGER->addSound("menuClose", "source/Sounds/menuClose.mp3", true, false);		//메뉴 닫는 소리
		SOUNDMANAGER->addSound("menuOpen", "source/Sounds/menuOpen.mp3", true, false);			//메뉴 여는 소리
		SOUNDMANAGER->addSound("menuSelect", "source/Sounds/menuSelect.mp3", true, false);		//메뉴 선택 소리
		//SOUNDMANAGER->addSound("monsterDead", "source/Sounds/monsterDead.mp3", true, false);	//몬스터 죽는 소리
		SOUNDMANAGER->addSound("moveGrass", "source/Sounds/moveGrass.mp3", true, false);		//풀밭을 걸을 때
		SOUNDMANAGER->addSound("moveRock", "source/Sounds/moveRock.mp3", true, false);			//돌길을 걸을 때
		SOUNDMANAGER->addSound("moveSoil", "source/Sounds/moveSoil.mp3", true, false);			//땅을 걸을 때
		//SOUNDMAMNAGER->addSound("day", "source/Sounds/day.mp3", true, true);						//아침이 될 때 나는 소리
		//SOUNDMANAGER->addSound("night", "source/Sounds/night.mp3", true, true);					//밤이 될 때 나는 소리
		SOUNDMANAGER->addSound("opening", "source/Sounds/opening.mp3", true, true);				//오프닝 소리
		SOUNDMANAGER->addSound("pickUpItem", "source/Sounds/pickUpItem.mp3", true, false);		//픽업 아이템(?)
		//SOUNDMANAGER->addSound("purchase", "source/Sounds/purchase.mp3", true, false);			//상점 구매 소리
		SOUNDMANAGER->addSound("removeGrass", "source/Sounds/removeGrass.mp3", true, false);	//풀 베는 소리
		SOUNDMANAGER->addSound("removeRock", "source/Sounds/removeRock.mp3", true, false);		//돌 깨는 소리
		SOUNDMANAGER->addSound("removeTree", "source/Sounds/removeTree.mp3", true, false);		//나무 베는 소리
		//SOUNDMANAGER->addSound("seeds", "source/Sounds/seeds.mp3", true, false);				//씨앗 심는 소리
		//SOUNDMANAGER->addSound("slime", "source/Sounds/slime.mp3", true, false);				//슬라임이 공격할 때 나는 소리
		SOUNDMANAGER->addSound("toolSwap", "source/Sounds/toolSwap.mp3", true, false);			//탭누르면 나는 소리
		SOUNDMANAGER->addSound("watering", "source/Sounds/watering.mp3", true, false);			//물을 담거나 물을 줄 때 나는 소리

		loadingHelper->_currentCount++;
	}
	return 0;
}
