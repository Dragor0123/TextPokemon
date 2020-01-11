#include "stdafx.h"
#include "MainGame.h"
#include "Intro.h"
#include "Player.h"

CMainGame::CMainGame()
	:m_pIntro(nullptr), m_pPlayer(nullptr)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	// 여기서 
	// 1  인트로 페이지
	// 2. 플레이어 초기화
	// 3. 월드맵 초기화
	// 4. 기타 기본적인 것들(NPC라던가....) 
	// 모두 초기화해야한다.

	if (!m_pIntro) {
		m_pIntro = new CIntro();
	}

	m_pPlayer = CPlayer::Get_Instance();
	// 무한루프로 계속 돌게 변경. 만약 Z,X,A,S중 하나가 입력되면 무한루프 종료
	m_pIntro->Progress();
}

void CMainGame::Progress()
{
	int iInput = 0;
	while (true) {
		system("cls");
		int posX = m_pPlayer->Get_x();
		int posY = m_pPlayer->Get_y();
		cout << "x좌표: " << posX << "  y좌표: " << posY << endl;
		cout << "방향키: ←↑→↓  입력키: z,x" << endl;
		cout << "============================================" << endl;
		cout << "입력: ";
		
		// 여기서부터
		iInput = _getch();
		
		if (iInput == 0xE0 || iInput == 0) {
			iInput = _getch();
			switch (iInput)
			{
			case LEFT:
			case RIGHT:
			case UP:
			case DOWN:
				m_pPlayer->Move_xy(iInput);
				break;
			}
		}
		else {
			iInput = tolower(iInput);
			if (iInput == 'z') {
				cout << "Z가 눌러졌습니다!" << endl;
			}
			else if (iInput == 'x') {
				break;
			}
		}
		// 여기까지 함수화.....

		//system("pause");
	}
}

void CMainGame::Render()
{
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pIntro);
	m_pPlayer->Release_Instance();
}
