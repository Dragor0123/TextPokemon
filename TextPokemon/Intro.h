#pragma once

#ifndef __INTRO_H__
#define __INTRO_H__

#include <sstream>

class CPlayer;

class CIntro
{
public:
	CIntro();
	virtual ~CIntro();

	void Initialize();
	void Progress();
	int Intro_Prog();
	void Prologue();
	void Set_Player_Name();
	void Release();

	void Render_Title();
	void Render_IntroMenu(char* _str, int _rowSize, int _colSize, POS& _selPos);

private:
	static stringstream		m_ssTitle;
	static stringstream		m_ssMonster;
	char					m_szIntroMenu[100];
	int						m_iIntroColSize;
};

#endif