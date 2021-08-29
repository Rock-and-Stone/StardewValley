#pragma once
#define TILESIZE 32	//타일 사이즈 32X32

#define TILEX 20	//가로 타일 갯수
#define TILEY 20	//세로 타일 갯수

//타일 규격 20 X 32 사이즈니까 -> 총 사이즈는 640 X 640
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

//타일 셋 가로 20줄 세로 9줄
#define SAMPLETILEX 15
#define SAMPLETILEY 4

#define SAMPLEOBJECTX 13
#define SAMPLEOBJECTY 18


//이넘문으로 해도 되지만 옛날에는 메모리 아낀다고 많이 썼던
//비트필드로 한 번 해보겠슴다 (요즘은 걍 이넘문 써도 무방함)

#define ATTR_UNMOVE 0x00000001	//못가는 타일
#define ATTR_HOE	0x00000002	//경작지대
#define ATTR_ROAD	0x00000004	//도로지대
#define ATTR_ENTRANCE	0x00000008	//입출구


//지형
enum TERRAIN
{
	TR_GRASS_0, TR_GRASS_1, TR_GRASS_2, TR_DIRT, TR_DIRT_WET, TR_WATER, TR_END
};

//오브젝트
enum OBJECT
{
	OBJ_BLOCK1, OBJ_BLOCK3, OBJ_BLOCKS,
	OBJ_FLAG1, OBJ_FLAG2,
	OBJ_TANK1, OBJ_TANK2, OBJ_NONE
};

enum POS
{
	//1P진영 깃발(독수리 모양) 1P 탱크 리스폰 위치
	POS_FLAG1, POS_FLAG2, POS_TANK1, POS_TANK2
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
};

//타일 셋
struct tagSampleTile
{
	RECT rcTile;
	int terrainFrameX;
	int terrainFrameY;
};
