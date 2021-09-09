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
	DrawTile();
	DrawObject();
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
		if (_tiles[i].terrain == TR_WATER) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_WALL) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_GRASS) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_BUILD) _attribute[i] |= ATTR_UNMOVE;
	}

	CloseHandle(file);
}

void homeMap::Movement(float posX, float posY)
{
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		_tiles[i].rc = RectMake(_tiles[i].posX - posX, _tiles[i].posY - posY, TILESIZE, TILESIZE);
	}
}

void homeMap::DrawTile()
{
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		char tileStr[128];
		if (_tiles[i].rc.left > WINSIZEX || _tiles[i].rc.top > WINSIZEY) continue;
		if (_tiles[i].rc.left + 32 < 0 || _tiles[i].rc.top + 32 < 0) continue;

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

		IMAGEMANAGER->frameRender(tileStr, getMemDC(),
			_tiles[i].rc.left, _tiles[i].rc.top,
			_tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
	}
}

void homeMap::DrawObject()
{
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		char tileStr[128];
		int  tileReposX = 0;
		int  tileReposY = 0;
		if (_tiles[i].rc.left > WINSIZEX || _tiles[i].rc.top > WINSIZEY) continue;
		if (_tiles[i].rc.left + 32 < 0 || _tiles[i].rc.top + 32 < 0) continue;
		//오브젝트 속성이 아니면 그리지마라 (지우개로 지울때 쓰려고)
		if (_tiles[i].obj == OBJ_NONE) continue;

		switch (_tiles[i].objPage)
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

		default:
			sprintf_s(tileStr, "Home_ObjectSheet");
			break;
		}

		IMAGEMANAGER->frameRender(tileStr, getMemDC(), _tiles[i].rc.left - tileReposX, _tiles[i].rc.top - tileReposY, _tiles[i].objFrameX, _tiles[i].objFrameY);
	}
}
