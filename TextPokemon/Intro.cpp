#include "stdafx.h"
#include "Intro.h"
#include "Player.h"

stringstream CIntro::m_ssTitle;
stringstream CIntro::m_ssMonster;

using poke_glob::Init_TypeChart;

CIntro::CIntro()
{
	strcpy_s(m_szIntroMenu, 100,
		"  _  1. Continue        "
		"  _  2. New Game        "
		"  _  3. How to Play     "
		"  _  4. Exit            ");

	m_iIntroColSize = strlen("  _  1. Continue        ");

	Initialize();
}

CIntro::~CIntro()
{
}

void CIntro::Release()
{
}

void CIntro::Initialize()
{
	{
		m_ssTitle
			<< R"(                                  ,'\                              )" << '\n'
			<< R"(    _.----.        ____         ,'  _\   ___    ___     ____       )" << '\n'
			<< R"(_,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`. )" << '\n'
			<< R"(\      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |)" << '\n'
			<< R"( \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |)" << '\n'
			<< R"(   \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |)" << '\n'
			<< R"(    \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     |)" << '\n'
			<< R"(     \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    |)" << '\n'
			<< R"(      \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |)" << '\n'
			<< R"(       \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |)" << '\n'
			<< R"(        \_.-'       |__|    `-._ |              '-.|     '-.| |   |)" << '\n'
			<< R"(                                `'                            '-._|)" << '\n';
		m_ssMonster
			<< "                           _._       _,._\n"
			<< "                        _.'   `. ' .'   _`.\n"
			<< "                ,\"\"\"/`\"\"-.-.,/. ` V'\\-,`.,--/\"\"\".\"-..\n"
			<< "              ,'    `...,' . ,\\-----._|     `.   /   \\\n"
			<< "             `.            .`  -'`\"\" .._   :> `-'   `.\n"
			<< "            ,'  ,-.  _,.-'| `..___ ,'   |'-..__   .._ L\n"
			<< "           .    \\_ -'   `-'     ..      `.-' `.`-.'_ .|\n"
			<< "           |   ,',-,--..  ,--../  `.  .-.    , `-.  ``.\n"
			<< "           `.,' ,  |   |  `.  /'/,,.\\/  |    \\|   |\n"
			<< "                `  `---'    `j   .   \\  .     '   j\n"
			<< "              ,__`\"        ,'|`'\\_/`.'\\'        |\\-'-, _,.\n"
			<< "       .--...`-. `-`. /    '- ..      _,    /\\ ,' .--\"'  ,'\".\n"
			<< "     _'-\"\"-    --  _`'-.../ __ '.'`-^,_`-\"\"\"\"---....__  ' _,-`\n"
			<< "   _.----`  _..--.'        |  \"`-..-\" __|'\"'         .\"\"-. \"\"'--.._\n"
			<< "  /        '    /     ,  _.+-.'  ||._'   \"\"\"\". .          `     .__\\\n"
			<< " `---    /        /  / j'       _/|..`  -. `-`\\ \\   \\  \\   `.  \\ `-..\n"
			<< ",\" _.-' /    /` ./  /`_|_,-\"   ','|       `. | -'`._,   L  \\ .  `.   |\n"
			<< "`\"' /  /  / ,__...-----| _.,  ,'            `|----.._`-.|' |. .` ..  .\n"
			<< "   /  '| /.,/   \\--.._ `-,' ,          .  '`.'  __,., '  ''``._ \\ \\`,'\n"
			<< "  /_,'---  ,     \\`._,-` \\ //  / . \\    `._,  -`,  / / _   |   `-L -\n"
			<< "   /       `.     ,  ..._ ' `_/ '| |\\ `._'       '-.'   `.,'     |\n"
			<< "  '         /    /  ..   `.  `./ | ; `.'    ,\"\" ,.  `.    \\      |\n"
			<< "   `.     ,'   ,'   | |\\  |       \"        |  ,'\\ |   \\    `    ,L\n"
			<< "   /|`.  /    '     | `-| '                  /`-' |    L    `._/  \\\n"
			<< "  / | .`|    |  .   `._.'                   `.__,'   .  |     |  (`\n"
			<< " '-\"\"-'_|    `. `.__,._____     .    _,        ____ ,-  j     \".-'\"'\n"
			<< "        \\      `-.  \\/.    `\"--.._    _,.---'\"\"\\/  \"_,.'     /-'\n"
			<< "         )        `-._ '-.        `--\"      _.-'.-\"\"        `.\n"
			<< "        ./            `,. `\".._________...\"\"_.-\"`.          _j\n"
			<< "       /_\\.__,\"\".   ,.'  \"`-...________.---\"     .\".   ,.  / \\\n"
			<< "              \\_/\"\"\"-'                           `-'--(_,`\"`-` mh\n";
	}

	Init_TypeChart();
}

void CIntro::Progress()
{
	int iIntroChoice = -1;
	while (true)
	{
		system("cls");
		Render_Title();
		if (poke_glob::Is_ZX_Key_Pushed()) {
			iIntroChoice = Intro_Prog();
			if (iIntroChoice) {
				break;
			}
		}
	}

	// World Map 초기화

	switch (iIntroChoice)
	{
	case 1:	// 이어 하기
		cout << "이어합니다" << endl;
		system("pause");
		break;
	case 2:	// 새로 하기
		Prologue();

		// Set Player Name
		system("pause");
		break;
	case 3:
		break;
	case 4: // 종료
		return;
	}
}

int CIntro::Intro_Prog()
{
	// New code - generic
	POS tSel = { 0, 2 };
	int rowSize = 4;

	fptr_SelMenu<CIntro> fpRender_Menu = &CIntro::Render_IntroMenu;

	return Up_Down_Select_Interface(fpRender_Menu, m_szIntroMenu,
	rowSize, m_iIntroColSize, tSel);
	
	/* Original code - none generic

	int iInput = 0;
	POS tSel = { 0, 2 };

	while (true)
	{
		system("cls");
		cout << string(40, '=') << '\n';
		Render_IntroMenu(m_szIntroMenu, 4, m_iIntroColSize, tSel);

		iInput = _getch();
		if (iInput == 0xE0 || iInput == 0) {
			iInput = _getch();
			switch (iInput)
			{
			case LEFT:
				break;
			case RIGHT:
				break;
			case UP:
				--tSel.y;
				tSel.y = (tSel.y < 0) ? 0 : tSel.y;
				break;
			case DOWN:
				++tSel.y;
				tSel.y = (tSel.y > 3) ? 3 : tSel.y;
				break;
			}
		}
		else {
			iInput = tolower(iInput);
			if ('z' == iInput) {
				return tSel.y + 1;
			}
			else if ('x' == iInput) {
				return 0;
			}
		}
	}
	*/
}

void CIntro::Render_Title()
{

	cout << m_ssTitle.str() << endl;
	cout << m_ssMonster.str() << endl;
	cout << " \t\tPress key 'X' or 'Z' to Play the Game..." << endl;
}

void CIntro::Render_IntroMenu(char* _str, int _rowSize, int _colSize, POS& _selPos)
{
	for (int i = 0; i < _rowSize; ++i) {
		for (int j = 0; j < _colSize; ++j) {
			if (i == _selPos.y && j == _selPos.x)
				cout << "▶";
			else
				cout << _str[_colSize * i + j];
		}
		cout << '\n';
	}
}

void CIntro::Prologue()
{
	poke_glob::Output_TextMsg("NPCSpeech/001_Intro_Prologue.txt");
}

void CIntro::Set_Player_Name()
{

}
