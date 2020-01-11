#pragma once

#ifndef __MAINGAME_H__
#define __MAINGAME_H__

class CIntro;
class CPlayer;

class CMainGame
{
public:
	CMainGame();
	virtual ~CMainGame();

	void Initialize();
	void Progress();
	void Render();
	void Release();

	// void Save_Data();
	// void Load_Data();
private:
	CIntro* m_pIntro;
	CPlayer* m_pPlayer;
};

#endif