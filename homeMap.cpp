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
	IMAGEMANAGER->addFrameImage("FloorTiles", "source/Sprite/TileSheet.bmp", 416, 576, SAMPLETILEX, SAMPLETILEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ObjectTiles", "source/Sprite/ObjectSheet.bmp", 416, 576, SAMPLEOBJECTX, SAMPLEOBJECTY, true, RGB(255, 0, 255));


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
	for (int i = 0; i < TILEX * TILEY; ++i)
	{
		if (_tiles[i].rc.left > WINSIZEX || _tiles[i].rc.top > WINSIZEY) continue;
		if (_tiles[i].rc.left + 32 < 0 || _tiles[i].rc.top + 32 < 0) continue;

		IMAGEMANAGER->frameRender("FloorTiles", getMemDC(),
			_tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].terrainFrameX, _tiles[i].terrainFrameY);
	}
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
		if (_tiles[i].obj == OBJ_POND) _attribute[i] |= ATTR_UNMOVE;
		if (_tiles[i].obj == OBJ_BUILD) _attribute[i] |= ATTR_UNMOVE;
	}

	CloseHandle(file);
}
