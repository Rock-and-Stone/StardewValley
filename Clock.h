#pragma once
#include "gameNode.h"
#include <string>


enum WEATHER
{
    FINE, RAINY, SNOW, THUNDER
};

enum DAYNIGHT
{
    DAY, NIGHT
};

enum SEASON
{
    SPRING, SUMMER, FALL, WINTER
};

enum WEEKDAY
{
    MON, TUE, WED, THU, FRI, SAT, SUN
};

class Clock :
    public gameNode
{
private:
    image* _seasonImg;         //계절
    image* _weatherImg;        //날씨
    image* _dayNightImg;       //밤낮
    image* _needleMoveImg;     //시침
    WEATHER _weather;       //날짜
    DAYNIGHT _dayNight;     //밤낮
    SEASON _season;         //계절
    WEEKDAY _weekDay;           //요일
    
    RECT _rc;               //시침 렉트
    float _x, _y;           //시침 좌표
    float _angle;           //시침 각도
    float _radius;          //시침 지름
    float _moveSpeed;       //시간 재기
    float _elapsedTime;     //경과 시간
    float _worldTime;       //월드 타임
    int _dayCount;          //요일 체크
    string _weekDayStr;     //요일 str
    string _dayNightStr;    //오전오후 str

    int _hour, _minute, _date;
    bool _isCheck;

   

public:
    Clock();
    ~Clock();
    virtual HRESULT init();
    virtual void release();
    virtual void update();
    virtual void render();

    void ClockRender();
    void MoneyRender();
    void Move();
    void Font();

};

