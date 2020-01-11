// TextPokemon.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

cout << "∠∠∠∠∠∠∠∠∠∠∠∠∠∠∠∠∠∠∠∠" << endl;
cout << "∠∠∠∠∠∠∠∠∠∠∠∠∠∠∠∠∠∠∠∠" << endl;
cout << "■■■■■■■■■■■■■■■■■■■■" << endl;
cout << "■■■■■■■■■■■■＋■＋■＋■＋■" << endl;
cout << "■＋■＋■＋■＋■■■■■■■■■■■■" << endl;
cout << "■＋■＋■＋■＋■■■■＋■＋■＋■＋■" << endl;
cout << "■■■■■■■■■| ■■■■■■■■■■" << endl;
cout << "                                        " << endl;
cout << "                                        " << endl;
cout << "                                        " << endl;
cout << "                                        " << endl;
cout << "                                        " << endl;


*/
