// TextPokemon.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MainGame.h"

/*
	randomNum = rand() / static_cast<double>(RAND_MAX);
	randomNum *= 100.0;
*/

int main()
{	
	CMainGame mainGame;

	mainGame.Initialize();
	//mainGame.Progress();
	mainGame.Release();
	system("cls");
	cout << "GAME OVER " << endl;
    return 0;
}


















/*

cout << "�ССССССССССССССССССС�" << endl;
cout << "�ССССССССССССССССССС�" << endl;
cout << "���������������������" << endl;
cout << "������������ᣫ�ᣫ�ᣫ�ᣫ��" << endl;
cout << "�ᣫ�ᣫ�ᣫ�ᣫ�������������" << endl;
cout << "�ᣫ�ᣫ�ᣫ�ᣫ����ᣫ�ᣫ�ᣫ�ᣫ��" << endl;
cout << "����������| �����������" << endl;
cout << "                                        " << endl;
cout << "                                        " << endl;
cout << "                                        " << endl;
cout << "                                        " << endl;
cout << "                                        " << endl;


*/
