#include "stdafx.h"
#include "Player.h"

CPlayer * CPlayer::m_Instance = nullptr;
once_flag CPlayer::m_OnceFlag;

CPlayer::CPlayer()
{
}

CPlayer::CPlayer(int _posX, int _posY)
{
	m_tPos.x = _posX;
	m_tPos.y = _posY;
}

CPlayer * CPlayer::Get_Instance()
{
	call_once(CPlayer::m_OnceFlag, []() {
		m_Instance = new CPlayer(4, 8);
	});
	return m_Instance;
}

void CPlayer::Release_Instance()
{
	SAFE_DELETE(m_Instance);
}

void CPlayer::Move_xy(int _input)
{
	switch (_input)
	{
	case UP:
		--m_tPos.y;
		break;
	case DOWN:
		++m_tPos.y;
		break;
	case LEFT:
		--m_tPos.x;
		break;
	case RIGHT:
		++m_tPos.x;
		break;
	}
}
