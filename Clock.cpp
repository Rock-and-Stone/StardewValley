#include "pch.h"
#include "Clock.h"

Clock::Clock()
{
}

Clock::~Clock()
{
}

HRESULT Clock::init()
{
	IMAGEMANAGER->addImage("Clock", "source/clock/Clock.bmp", 288, 236, true, MAGENTA);
	_needleMoveImg = IMAGEMANAGER->addFrameImage("NeedleMove", "source/clock/NeedleMove.bmp", 1330, 120, 19, 1, true, MAGENTA);
	_weatherImg = IMAGEMANAGER->addImage("FineDay", "source/clock/FineDay.bmp", 48, 32, true, MAGENTA);
	IMAGEMANAGER->addImage("RainyDay", "source/clock/RainyDay.bmp", 48, 32, true, MAGENTA);
	_seasonImg = IMAGEMANAGER->addImage("Spring", "source/clock/Spring.bmp", 48, 32, true, MAGENTA);
	IMAGEMANAGER->addImage("Summer", "source/clock/Summer.bmp", 48, 32, true, MAGENTA);
	

	_hour = 06;			//오전 6시 시작
	_minute = 00;		//00분
	_date = 1;			//1일
	_weekDay = MON;		//월요일
	_season = SPRING;	//봄
	_weekDayStr = "월";
	_dayNightStr = "오전";

	_x = 1000;
	_y = 40;
	_angle = 0.0f;
	_rc = RectMakeCenter(_x, _y,
		_needleMoveImg->getFrameWidth(), _needleMoveImg->getHeight());
	_radius = _needleMoveImg->getFrameWidth() / 2;


	
	
	return S_OK;
}

void Clock::release()
{
}

void Clock::update()
{
	Move();
	_angle += PI20 / 1800 ;
	
}

void Clock::render()
{
	ClockRender();
	
	Font();
	char str[128];
	sprintf_s(str, "X : %d", _ptMouse.x);
	TextOut(getMemDC(), 10, 10, str, strlen(str));
	sprintf_s(str, "Y : %d", _ptMouse.y);
	TextOut(getMemDC(), 10, 30, str, strlen(str));
	sprintf_s(str, "elapsedTime : %f", TIMEMANAGER->getWorldTime());
	TextOut(getMemDC(), 10, 50, str, strlen(str));
	sprintf_s(str, "angle : %f", _angle);
	TextOut(getMemDC(), 10, 70, str, strlen(str));
	sprintf_s(str, "minute : %d", _minute);
	TextOut(getMemDC(), 10, 90, str, strlen(str));
	sprintf_s(str, "hour : %d", _hour);
	TextOut(getMemDC(), 10, 110, str, strlen(str));
	
}

void Clock::ClockRender()
{
	IMAGEMANAGER->findImage("Clock")->render(getMemDC(), 980, 20);
	_weatherImg->render(getMemDC(), 1096, 84);
	_seasonImg->render(getMemDC(), 1192, 84);
	_needleMoveImg->frameRender(getMemDC(), _x, _y);


}

void Clock::MoneyRender()
{
	
	
}

void Clock::Move()
{
	int frame;

	//특정 각도별로 보여져야할 프레임 번호를 계산한다.
	frame = int(_angle / PI20);
	_needleMoveImg->setFrameX(frame);

	_worldTime = TIMEMANAGER->getWorldTime();

	if ((int)_worldTime % 5 == 0 && !_isCheck)
	{
		_isCheck = true;
		_minute += 10;
	}
	else if ((int)_worldTime % 5 != 0)
	{
		_isCheck = false;
	}

	if (_minute >= 60)
	{
		_minute = 0;
		_hour++;
	}
	if (_hour >= 26 || KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_hour = 0;
		_minute = 0;
		switch (_weekDay)
		{
		case MON:
			_weekDay = TUE;
			_weekDayStr = "화";
			_hour = 6;
			break;
		case TUE:
			_weekDay = WED;
			_weekDayStr = "수";
			_hour = 6;
			break;
		case WED:
			_weekDay = THU;
			_weekDayStr = "목";
			_hour = 6;
			break;
		case THU:
			_weekDay = FRI;
			_weekDayStr = "금";
			_hour = 6;
			break;
		case FRI:
			_weekDay = SAT;
			_weekDayStr = "토";
			_hour = 6;
			break;
		case SAT:
			_weekDay = SUN;
			_weekDayStr = "일";
			_hour = 6;
			break;
		case SUN:
			_weekDay = MON;
			_weekDayStr = "월";
			_hour = 6;
			break;
		}
		_date++;
	}

	if (_date > 28)
	{
		_date = 0;
		_season = SUMMER;
	}

	_elapsedTime = TIMEMANAGER->GetWorldElapsedTime();
	

	if (_angle >= PI)
	{
		_angle -= PI;
		TIMEMANAGER->SetWorldElapsedTime(0);
	}
	if (_angle <= 0) _angle += PI;

	//_x += cosf(_angle) * 0;
	//_y += -sinf(_angle) * 0;

	_rc = RectMakeCenter(_x, _y,
		_needleMoveImg->getFrameWidth(), _needleMoveImg->getFrameHeight());
}

void Clock::Font()
{
	//시, 분, 오전오후
	char str[256];
	char str2[256];
	HFONT oldFont, font1;
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	RECT rcText = RectMake(1040, 100, 200, 100);
	HFONT font2 = CreateFont(40, 0, 0, 0, 400, true, false, false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("sandoll 미생"));
	HFONT oldFont2 = (HFONT)SelectObject(getMemDC(), font2);
	sprintf_s(str, "%.2d : %.2d", _hour, _minute);
	if (_hour < 12 || _hour >=24)
	{
		sprintf_s(str2, "오전", strlen(str2));
	}
	else if (_hour >=12 && _hour < 24)
	{
		sprintf_s(str2, "오후", strlen(str2));
	}
	TextOut(getMemDC(), 1195, 128, str2, strlen(str2));
	SetBkMode(getMemDC(), 0);
	DrawText(getMemDC(), TEXT(str), 7, &rcText, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	SelectObject(getMemDC(), oldFont2);
	DeleteObject(font2);

	//요일, 일자
	char str3[256];
	char str4[256];
	HFONT oldFont3, font3;
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	RECT rcText2 = RectMake(1130, 5, 200, 100);
	HFONT font4 = CreateFont(40, 0, 0, 0, 400, false, false, false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("sandoll 미생"));
	HFONT oldFont4 = (HFONT)SelectObject(getMemDC(), font4);
	switch (_weekDay)
	{
	case MON:
		sprintf_s(str4, "월,", strlen(str4));
		break;
	case TUE:
		sprintf_s(str4, "화,", strlen(str4));
		break;
	case WED:
		sprintf_s(str4, "수,", strlen(str4));
		break;
	case THU:
		sprintf_s(str4, "목,", strlen(str4));
		break;
	case FRI:
		sprintf_s(str4, "금,", strlen(str4));
		break;
	case SAT:
		sprintf_s(str4, "토,", strlen(str4));
		break;
	case SUN:
		sprintf_s(str4, "일,", strlen(str4));
		break;
	}
	sprintf_s(str3, "%d", _date);
	TextOut(getMemDC(), 1130, 35, str4, strlen(str4));
	SetBkMode(getMemDC(), 0);
	DrawText(getMemDC(), TEXT(str3), 7, &rcText2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	SelectObject(getMemDC(), oldFont4);
	DeleteObject(font4);
	
}
/*
	CreateFont(
		40,			//문자폭
		0,			//문자 넓이
		40,			//문자 기울기(진짜 기울어짐)
		0,			//문자 방향
		600,		//문자 굵기
		0,			//bool 문자 기울기 이탤릭체 사용유무
		0,			//bool 문자 밑줄
		0,			//bool 문자 취소선 (나무위키에 많은 그것)
		HANGUL_CHARSET,	//문자 셋팅
		0,				//출력 정확도
		0,				//클리핑 정확도
		0,				//출력의 퀄리티
		0,				//자간
		TEXT("궁서체"));	//폰트
	*/
	/*


	font1 = CreateFont(50, 0, 0, 0, 100, true, true, true, HANGUL_CHARSET, 0, 0, 0, 50, TEXT("휴먼굴림"));
	oldFont = (HFONT)SelectObject(getMemDC(), font1);
	sprintf_s(str, "울트라 캡숑 나이쓰");
	TextOut(getMemDC(), 10, 100, str, strlen(str));
	DeleteObject(font1);
	*/