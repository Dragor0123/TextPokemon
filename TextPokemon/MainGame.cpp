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
	// ���⼭ 
	// 1  ��Ʈ�� ������
	// 2. �÷��̾� �ʱ�ȭ
	// 3. ����� �ʱ�ȭ
	// 4. ��Ÿ �⺻���� �͵�(NPC�����....) 
	// ��� �ʱ�ȭ�ؾ��Ѵ�.

	if (!m_pIntro) {
		m_pIntro = new CIntro();
	}

	m_pPlayer = CPlayer::Get_Instance();
	// ���ѷ����� ��� ���� ����. ���� Z,X,A,S�� �ϳ��� �ԷµǸ� ���ѷ��� ����
	m_pIntro->Progress();
}

void CMainGame::Progress()
{
	int iInput = 0;
	while (true) {
		system("cls");
		int posX = m_pPlayer->Get_x();
		int posY = m_pPlayer->Get_y();
		cout << "x��ǥ: " << posX << "  y��ǥ: " << posY << endl;
		cout << "����Ű: �����  �Է�Ű: z,x" << endl;
		cout << "============================================" << endl;
		cout << "�Է�: ";
		
		// ���⼭����
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
				cout << "Z�� ���������ϴ�!" << endl;
			}
			else if (iInput == 'x') {
				break;
			}
		}
		// ������� �Լ�ȭ.....

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
