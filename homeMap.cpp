#include "pch.h"
#include "homeMap.h"
#include "CameraManager.h"
homeMap::homeMap()
{
}

homeMap::~homeMap()
{
}

HRESULT homeMap::init()
{
	IMAGEMANAGER->addFrameImage("Home_TileSheet", "source/Sprite/Home_TileSheet.bmp", 416, 576, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Home_ObjectSheet", "source/Sprite/Home_ObjectSheet.bmp", 416, 576, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Mine_TileSheet", "source/Sprite/Mine_TileSheet.bmp", 416, 576, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Mine_ObjectSheet", "source/Sprite/Mine_ObjectSheet.bmp", 416, 576, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BuildingSheet", "source/Sprite/BuildingSheet.bmp", 416, 576, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("2xObjectSheet", "source/Sprite/2xObjectSheet.bmp", 416, 256, SAMPLE2XOBJECTX, SAMPLE2XOBJECTY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("TreeSheet", "source/Sprite/TreeSheet.bmp", 288, 384, SAMPLETREEX, SAMPLETREEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BuildObject", "source/Sprite/BuildObject.bmp", 128, 64, 4, 1, true, RGB(255, 0, 255));

	load();

	return S_OK;
}

void homeMap::release()
{
}

void homeMap::update()
{
}

void homeMap::render()
{
}


void homeMap::load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("tileMapSave.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	ReadFile(file, _pos, sizeof(int) * 2, &read, NULL);

	memset(_attribute, 0, sizeof(DWORD) * TILEX * TILEY);
	memset(_pos, 0, sizeof(int) * 2);

	//STEP 1
	//타일을 불러와서 해당 타일에 속성값을 부여한다
	//물 타일, 또는 오브젝트 등은 갈수없는 타일이다

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		_tiles[i].rc = RectMake(_tiles[i].posX, _tiles[i].posY, 32, 32);

		if (_tiles[i].terrain == TR_WATER) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_WALL) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_GRASS) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_BUILD) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_TREE) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_ROCK) _attribute[i] |= ATTR_UNMOVE;
	}


	CloseHandle(file);
}


void homeMap::DrawTile(float posX , float posY)
{
	RECT rendRect;

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		rendRect = RectMake(_tiles[i].posX - posX, _tiles[i].posY - posY, TILESIZE, TILESIZE);

		char tileStr[128];

 		if (rendRect.left > WINSIZEX || rendRect.top > WINSIZEY) continue;
		if (rendRect.left + 32 < 0 || rendRect.top + 32 < 0) continue;

		switch (_tiles[i].tilePage)
		{
		case 0:
			sprintf_s(tileStr, "Home_TileSheet");
			break;
		case 1:
			sprintf_s(tileStr, "Mine_TileSheet");
			break;
		default:
			sprintf_s(tileStr, "Home_TileSheet");
			break;
		}

		IMAGEMANAGER->frameRender(tileStr, getMemDC(),	rendRect.left, rendRect.top , _tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
	}
}

void homeMap::DrawObject(float posX, float posY, int pT)
{
	RECT rendRect; 
	RECT tempRect;
	bool isin = false;

	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		rendRect = RectMake(_tiles[i].posX - posX, _tiles[i].posY - posY, TILESIZE, TILESIZE);
		tempRect = RectMake(_tiles[pT].posX - posX, _tiles[pT].posY - posY, TILESIZE, TILESIZE);

		char tileStr[128];
		int  tileReposX = 0;
		int  tileReposY = 0;

		//오브젝트 속성이 아니면 그리지마라 (지우개로 지울때 쓰려고)
		if (_tiles[i].obj == OBJ_NONE) continue;

		switch (_tiles[i].objPage) //오브젝트가 어느 이미지에서 가져오고 있는지 구분, 이미지의 크기에따라 이미지 위치 조정
		{
		case 0:
			sprintf_s(tileStr, "Home_ObjectSheet");
			break; 
		case 1:
			sprintf_s(tileStr, "Mine_ObjectSheet");
			break;
		case 2:
			sprintf_s(tileStr, "2xObjectSheet");
			tileReposY = 32;
			break;
		case 3:
			sprintf_s(tileStr, "TreeSheet");
			tileReposX = 32;
			tileReposY = 160;
			break;
		case 4:
			sprintf_s(tileStr, "BuildingSheet");
			break;
		case 5:
			sprintf_s(tileStr, "BuildObject");
			tileReposY = 32;
			break;
		default:
			sprintf_s(tileStr, "Home_ObjectSheet");
			break;
		}

		//화면을 넘어갈경우 렌더를 생략함으로써 프레임드랍을 방지합니다.
		if (rendRect.left - tileReposX > WINSIZEX || rendRect.top - tileReposY > WINSIZEY) continue;
		if (rendRect.left + 32 + tileReposX < 0 || rendRect.top + 32 < 0) continue;


		
		if (rendRect.top > tempRect.top)
		{
			if (!isin)
			{
				RENDERMANAGER->render(getMemDC());
				isin = true;
			}
	
			IMAGEMANAGER->frameRender(tileStr, getMemDC(), rendRect.left - tileReposX, rendRect.top - tileReposY, _tiles[i].objFrameX, _tiles[i].objFrameY);
		}
		else
		{		
			IMAGEMANAGER->frameRender(tileStr, getMemDC(), rendRect.left - tileReposX, rendRect.top - tileReposY, _tiles[i].objFrameX, _tiles[i].objFrameY);
			if (!isin)
			{
				RENDERMANAGER->render(getMemDC());
				isin = true;
			}
		}
		
	}
}

void homeMap::CultivateTile(int num)
{
	if (_tiles[num].terrain != TR_DIRT || _tiles[num].terrain == TR_HOE || _tiles[num].obj != OBJ_NONE) return;
	
	_tiles[num].terrain = TR_HOE;
	_tiles[num].tilePage = 0;
	_tiles[num].terrainFrameX = 5;
	_tiles[num].terrainFrameY = 2;
}

void homeMap::PlaceObject(ALLOBJECTS object, int num) //오브젝트 설치 (설치한 오브젝트 enum, 설치한 타일 번호)
{
	if (_tiles[num].obj != OBJ_NONE) return;

	int frameX = 0;
	int frameY = 0;

	switch (object)
	{
	case OBJ_BOX:
		frameX = 0;
		frameY = 0;
		break;
	case OBJ_FURNACE:
		frameX = 1;
		frameY = 0;
		break;
	case OBJ_SCARECROW1:
		frameX = 2;
		frameY = 0;
		break;
	case OBJ_SCARECROW2:
		frameX = 3;
		frameY = 0;
		break;
	}

	_tiles[num].objFrameX = frameX;
	_tiles[num].objFrameY = frameY;
	_tiles[num].obj = objSelect(frameX, frameY);
	_tiles[num].objPage = 5;
	_attribute[num] |= ATTR_UNMOVE;
}

void homeMap::RemoveObject(int num)
{
	if (_tiles[num].obj == OBJ_BUILD || _tiles[num].obj == OBJ_WALL || _tiles[num].obj == OBJ_PROP) return;

	_tiles[num].objFrameX = 0;
	_tiles[num].objFrameY = 0;
	_tiles[num].obj = OBJ_NONE;
	_tiles[num].objPage = 0;
	_attribute[num] = ATTR_MOVE;
}



OBJECT homeMap::objSelect(int frameX, int frameY)
{
	char strX[128];
	char strY[128];
	char name[128];
	sprintf_s(strX, "%d", frameX);
	sprintf_s(strY, "%d", frameY);
	sprintf_s(name, "OBJECT_5");

	return (OBJECT)INIDATA->loadDataInterger(name, strY, strX);
}
