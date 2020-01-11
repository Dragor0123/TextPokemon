#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Trainer.h"
#include <mutex>

class CPlayer : public CTrainer
{
public:
	static CPlayer*		Get_Instance();
	static void			Release_Instance();
	void Move_xy(int _input);
	const int Get_x() { return m_tPos.x; }
	const int Get_y() { return m_tPos.y; }

private:
	CPlayer();
	CPlayer(int _posX, int _posY);
	virtual ~CPlayer() {};
	CPlayer(const CPlayer&) = delete;
	CPlayer& operator=(const CPlayer&) = delete;
private:
	POS					m_tPos;
	static CPlayer*		m_Instance;
	static once_flag	m_OnceFlag;
	int					m_iGold;
	int					m_MonsterMetCnt;
	int					m_MonsterCoughtCnt;

	// PlayerID
	// Bag
	// MonsterEntry 6¸¶¸®
};


#endif // !__PLAYER_H__