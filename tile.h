#pragma once
#include "gameNode.h"

class tile : public gameNode
{
private:
	int _idX;		//X 인덱스
	int _idY;		//Y 인덱스

	POINT _center;	//타일의 중점
	RECT _rc;

	//F = G + H
	//F == 총 거리 비용 (totalCost)
	//G == 시작점으로부터 현재 노드까지의 경로비용(costFromStart)
	//H == 현재 노드부터 도착점까지의 경로비용(costToGoal)

	float _totalCost;		//F
	float _costFromStart;	//G
	float _costToGoal;		//H

	bool _isOpen;			//갈수있는 길이니?

	tile* _parentNode;		//현재 노드 (계속 갱신되는 타일)

	COLORREF _color;
	HBRUSH _brush;
	HPEN _pen;

	string _attribute;

public:
	tile();
	~tile();

	HRESULT init(int idX, int idY);
	void release();
	void update();
	void render();

	int getIdX() { return _idX; }
	int getIdY() { return _idY; }

	void setColor(COLORREF color)
	{
		DeleteObject(_brush);
		_color = color;
		_brush = CreateSolidBrush(_color);
	}

	RECT getRect() { return _rc; }

	//================= 편리를 위한 접근자 & 설정자 =============

	void setCenter(POINT center) { _center = center; }
	POINT getCenter() { return _center; }

	void setAttribute(string str) { _attribute = str; }
	string getAttribute() { return _attribute; }

	void setTotalCost(float totalCost) { _totalCost = totalCost; }
	float getTotalCost() { return _totalCost; }

	void setCostFromStart(float costFromStart) { _costFromStart = costFromStart; }
	float getCostFromStart() { return _costFromStart; }

	void setCostToGoal(float costToGoal) { _costToGoal = costToGoal; }
	float getCostToGoal() { return _costToGoal; }

	void setParentNode(tile* t) { _parentNode = t; }
	tile* getParentNode() { return _parentNode; }

	void setIsOpen(bool isOpen) { _isOpen = isOpen; }
	bool getIsOpen() { return _isOpen; }

};

