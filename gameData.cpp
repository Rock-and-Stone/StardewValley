#include "pch.h"
#include "gameData.h"

float gameData::getBGMVolume()
{
	int BGMVolume;
	BGMVolume = INIDATA->loadDataInterger("gameData", "BGM", "volume");
	return BGMVolume;
}

void gameData::setBGMVolume(float volume)
{
	char str[30];
	_BGMVolume = volume;
	sprintf_s(str, "%d", _BGMVolume);
	INIDATA->addData("BGM", "volume", str);
	INIDATA->iniSave("gameData");
}

float gameData::getSFXVolume()
{
	int SFXVolume;
	SFXVolume = INIDATA->loadDataInterger("gameData", "SFX", "volume");
	return SFXVolume;
}

void gameData::setSFXVolume(float volume)
{
	char str[30];
	_SFXVolume = volume;
	sprintf_s(str, "%d", _SFXVolume);
	INIDATA->addData("SFX", "volume", str);
	INIDATA->iniSave("gameData");
}

int gameData::getPlayerSaveHP()
{
	int hp;
	hp = INIDATA->loadDataInterger("gameData", "player", "hp");
	return hp;
}

void gameData::SavePlayerHP(int hp)
{
	char str[30];
	_playerHP = hp;
	sprintf_s(str, "%d", _playerHP);
	INIDATA->addData("player", "hp", str);
	INIDATA->iniSave("gameData");
}

int gameData::getPlayerSaveSM()
{
	int gp;
	gp = INIDATA->loadDataInterger("gameData", "player", "sm");
	return gp;
}

void gameData::SavePlayerSM(int sm)
{
	char str[30];
	_playerSM = sm;
	sprintf_s(str, "%d", _playerSM);
	INIDATA->addData("player", "sm", str);
	INIDATA->iniSave("gameData");
}

int gameData::getSaveGold()
{
	int gold;
	gold = INIDATA->loadDataInterger("gameData", "player", "gold");
	return gold;
}

void gameData::SaveGold(int gold)
{
	char str[30];
	_gold = gold;
	sprintf_s(str, "%d", _gold);
	INIDATA->addData("player", "gold", str);
	INIDATA->iniSave("gameData");
}

