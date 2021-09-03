#pragma once
#include "entity.h"
#include "CameraManager.h"
#include "tileNode.h"

enum ENEMYDIRECTION
{
	DOWN, RIGHT, UP, LEFT
};

enum ENEMYSTATEMENT
{
	IDLE, CHASE, ATTACK, DEAD
};

enum NODESTATE
{
	NODE_START,
	NODE_END,
	NODE_WALL,
	NODE_EMPTY
};

class node
{
public:
	RECT rc;
	int idX, idY;
	int F, G, H;
	node* parentNode;
	NODESTATE nodeState;

	node(){}
	node(int idx, int idy)
	{
		idX = idx;
		idY = idy;
		F = G = H = 0;
		nodeState = NODE_EMPTY;
		parentNode = NULL;
	}
};
class Enemy : public entity
{
protected:
	//aStar!!
	node* _totalNode[TILEX][TILEY];		//전체노드 25개(보드판 역할)
	node* _startNode;					//시작노드
	node* _endNode;						//종료노드
	node* _curNode;						//현재노드

	vector<node*> _openList;			//오픈리스트 (탑색할 노드들을 담아둘 벡터)
	vector<node*> _closeList;			//길을 찾은 노드들을 담아둘 벡터
	vector<node*> _finalList;			//클로즈리스트에 담겨있는 노드들을 리버스시켜서 담아둘 벡터

	int _count;							//시작노드, 종료노드를 한번씩만 선택하기 위한 변수
	bool _isFind;						//길 찾았냐?
	bool _isMove;						//움직이냐?

	ENEMYSTATEMENT _enemyStatement;
	ENEMYDIRECTION _enemyDirection;
	CameraManager* _cm;	
	image* _image;		
	RECT _rc;			
	POINT _pos;			//절대좌표
	POINT _rend;		//렌더좌표
	int _posX, _posY;	//절대좌표
	int _idX, _idY;		//에너미 인덱스 좌표

	int _fullHP;		//전체체력
	int _currentHP;		//현재체력

	int _frameCount = 0;	//에너미 이미지 프레임카운트
	int _frameX = 0;		//에너미 이미지 프레임X
	int _frameY = 0;		//에너미 이미지 프레임Y



public:
	Enemy();
	~Enemy();

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void SwitchImage() = 0;

	void AstarInit();
	void StartSearchPlayer(int playerIdX, int playIdY);
	void SearchPlayer(int playerIdX, int playerIdY);
	//길찾기 함수
	void pathFinding();
	//오픈리스트 추가
	void addOpenList(int idx, int idy);
	//오픈리스트 삭제
	void delOpenList(int index);
	//편의를 위한 함수
	void setNodeColor(node* node, COLORREF color);

	void Move();
	void Draw();
	void Collision();

public:
	//frame 값 접근,설정자
	int GetEnemyFrameX() { return _frameX; }
	void SetEnemyFrameX(int frameX) { _frameX = frameX; }
	int GetEnemyFrameY() { return _frameY; }
	void SetEnemyFrameY(int frameY) { _frameY = frameY; }

	//pos 값 접근,설정자
	int GetEnemyPosX() { return _posX; }
	void SetEnemyPosX(int posX) { _posX = posX; }
	int GetEnemyPosY() { return _posY; }
	void SetEnemyPosY(int posY) { _posY = posY; }

	//index 값 접근,설정자
	int GetEnemyIdX() { return _idX; }
	void SetEnemyIdX(int idX) { _idX = idX; }
	int GetEnemyIdY() { return _idY; }
	void SetEnemyIdY(int idY) { _idY = idY; }
};
