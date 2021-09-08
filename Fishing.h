#pragma once
#include "gameNode.h"
struct tagFishFrame
{
    image* image;
    int x, y;
};
struct tagFishIcon
{
    image* image;
    RECT rc;
    int x, y;
};
struct tagCheck
{
    image* image;
    RECT rc;
    int x, y;
};
class Fishing :
    public gameNode
{
private:
    image*  _image;
    RECT    _rc;
    int     _rndCount;
    int     _rndCountNum;
    float   _gravity;
    float   _jumpPower;
    int     _rndSpeed;
    bool    _isStart;
    bool    _isFail;
    bool    _isSuccess;
    bool    _isJump;
    
    bool    _isRandom;
    bool    _isCollide;

    tagFishFrame    _fishFrame;
    tagFishIcon     _icon;
    tagCheck        _check;

    //프로그레스바
    RECT _rcProgress;
    int _x, _y;
    float _height;
    float _currentGauge, _maxGauge;

    image* _progressBarTop;
    image* _progressBarBottom;

public:
    virtual HRESULT init();
    virtual void release();
    virtual void update();
    virtual void render();

    void progressbarInit(int x, int y, int width, int height);
    void setGauge(float currentGauge, float maxGauge);
    void Collision();

    void setX(int x) { _x = x; }
    void setY(int y) { _y = y; }
};

