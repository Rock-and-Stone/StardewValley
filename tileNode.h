#pragma once
#define TILESIZE 32	//타일 사이즈 32X32

#define TILEX 80	//가로 타일 갯수
#define TILEY 65	//세로 타일 갯수

#define MINETILEX 40	//가로 타일 갯수
#define MINETILEY 23	//세로 타일 갯수

//타일 규격 20 X 32 사이즈니까 -> 총 사이즈는 640 X 640
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

//타일 셋 가로 20줄 세로 9줄
#define SAMPLETILEX 13
#define SAMPLETILEY 18

#define SAMPLE2XOBJECTX 13
#define SAMPLE2XOBJECTY 4

#define SAMPLETREEX 3
#define SAMPLETREEY 2

//이넘문으로 해도 되지만 옛날에는 메모리 아낀다고 많이 썼던
//비트필드로 한 번 해보겠슴다 (요즘은 걍 이넘문 써도 무방함)

#define ATTR_UNMOVE		0x00000001	//못가는 타일
#define ATTR_HOE		0x00000002	//경작지대
#define ATTR_ROAD		0x00000004	//도로지대
#define ATTR_ENTRANCE	0x00000008	//입출구
#define ATTR_CORNER		0x00000016  //테두리 타일
#define ATTR_MOVE		0x00000000  //갈수 있는 타일

//지형
enum TERRAIN
{
	TR_GRASS, TR_DIRT, TR_DIRT_WET, TR_WATER, TR_WOOD, TR_NULL, TR_HOE
};

//오브젝트
enum OBJECT
{
	OBJ_WALL, OBJ_GRASS, OBJ_TREE, OBJ_ROCK, OBJ_BUILD, OBJ_PROP, OBJ_NONE, OBJ_BOXX, OBJ_COPPERR, OBJ_IRONN, OBJ_GOLDD 
};

enum POS
{
	//1P진영 깃발(독수리 모양) 1P 탱크 리스폰 위치
	POS_HOUSE_ENTER, POS_HOUSE_EXIT, POS_FARM_EXIT, POS_FARM_ENTER
};

//타일 구조체 (타일 정보등을 담고있다)
struct tagTile
{
	TERRAIN terrain;
	OBJECT obj;
	RECT rc;

	int terrainFrameX;
	int terrainFrameY;
	int objFrameX;
	int objFrameY;
	int posX, posY;

 	int tilePage;
	int objPage;
};

//타일 셋
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};
