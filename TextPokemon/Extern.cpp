#include "stdafx.h"

namespace poke_glob {
	float gTypeChart[TYPE_END][TYPE_END] = {};
	
	void Output_TextMsg(const char* _filename)
	{
		char msgBuff[128] = "";
		ifstream ifs;
		ifs.open(_filename);

		while (ifs) {
			system("cls");
			ifs.getline(msgBuff, 128);
			cout << msgBuff << endl;
			ifs.getline(msgBuff, 128);
			cout << msgBuff << endl;
			while (!Is_ZX_Key_Pushed())
				;
		}

		ifs.close();
	}

	bool Is_ZX_Key_Pushed()
	{
		int iInput = _getch();
		iInput = tolower(iInput);
		if ('z' == iInput || 'x' == iInput)
			return true;
		else
			return false;
	}

	void Init_TypeChart()
	{
		for (int i = 0; i < TYPE_END; ++i) {
			for (int j = 0; j < TYPE_END; ++j) {
				gTypeChart[i][j] = 1.0f;
			}
		}
		// 앞첨자 <- 공격하는 기술 타입
		// 뒷첨자 <- 기술을 받는 포켓몬 타입
		gTypeChart[TYPE_NORMAL][TYPE_ROCK] = 0.5f;
		gTypeChart[TYPE_NORMAL][TYPE_GHOST] = 0.0f;
		gTypeChart[TYPE_NORMAL][TYPE_STEEL] = 0.5f;

		gTypeChart[TYPE_FIRE][TYPE_FIRE] = 0.5f;
		gTypeChart[TYPE_FIRE][TYPE_WATER] = 0.5f;
		gTypeChart[TYPE_FIRE][TYPE_GRASS] = 2.0f;
		gTypeChart[TYPE_FIRE][TYPE_ICE] = 2.0f;
		gTypeChart[TYPE_FIRE][TYPE_BUG] = 2.0f;
		gTypeChart[TYPE_FIRE][TYPE_ROCK] = 0.5f;
		gTypeChart[TYPE_FIRE][TYPE_DRAGON] = 0.5f;
		gTypeChart[TYPE_FIRE][TYPE_STEEL] = 2.0f;

		gTypeChart[TYPE_WATER][TYPE_FIRE] = 2.0f;
		gTypeChart[TYPE_WATER][TYPE_WATER] = 0.5f;
		gTypeChart[TYPE_WATER][TYPE_GRASS] = 0.5f;
		gTypeChart[TYPE_WATER][TYPE_GROUND] = 2.0f;
		gTypeChart[TYPE_WATER][TYPE_ROCK] = 2.0f;
		gTypeChart[TYPE_WATER][TYPE_DRAGON] = 0.5f;

		gTypeChart[TYPE_ELECTRIC][TYPE_WATER] = 2.0f;
		gTypeChart[TYPE_ELECTRIC][TYPE_ELECTRIC] = 0.5f;
		gTypeChart[TYPE_ELECTRIC][TYPE_GRASS] = 0.5f;
		gTypeChart[TYPE_ELECTRIC][TYPE_GROUND] = 0.0f;
		gTypeChart[TYPE_ELECTRIC][TYPE_FLYING] = 2.0f;
		gTypeChart[TYPE_ELECTRIC][TYPE_DRAGON] = 0.5f;

		gTypeChart[TYPE_GRASS][TYPE_FIRE] = 0.5f;
		gTypeChart[TYPE_GRASS][TYPE_WATER] = 2.0f;
		gTypeChart[TYPE_GRASS][TYPE_GRASS] = 0.5f;
		gTypeChart[TYPE_GRASS][TYPE_POISON] = 0.5f;
		gTypeChart[TYPE_GRASS][TYPE_GROUND] = 2.0f;
		gTypeChart[TYPE_GRASS][TYPE_FLYING] = 0.5f;
		gTypeChart[TYPE_GRASS][TYPE_BUG] = 0.5f;
		gTypeChart[TYPE_GRASS][TYPE_ROCK] = 2.0f;
		gTypeChart[TYPE_GRASS][TYPE_DRAGON] = 0.5f;
		gTypeChart[TYPE_GRASS][TYPE_STEEL] = 0.5f;

		gTypeChart[TYPE_ICE][TYPE_FIRE] = 0.5f;
		gTypeChart[TYPE_ICE][TYPE_WATER] = 0.5f;
		gTypeChart[TYPE_ICE][TYPE_GRASS] = 2.0f;
		gTypeChart[TYPE_ICE][TYPE_ICE] = 0.5f;
		gTypeChart[TYPE_ICE][TYPE_GROUND] = 2.0f;
		gTypeChart[TYPE_ICE][TYPE_FLYING] = 2.0f;
		gTypeChart[TYPE_ICE][TYPE_DRAGON] = 2.0f;
		gTypeChart[TYPE_ICE][TYPE_STEEL] = 0.5f;

		gTypeChart[TYPE_FIGHTING][TYPE_NORMAL] = 2.0f;
		gTypeChart[TYPE_FIGHTING][TYPE_ICE] = 2.0f;
		gTypeChart[TYPE_FIGHTING][TYPE_POISON] = 0.5f;
		gTypeChart[TYPE_FIGHTING][TYPE_FLYING] = 0.5f;
		gTypeChart[TYPE_FIGHTING][TYPE_PSYCHIC] = 0.5f;
		gTypeChart[TYPE_FIGHTING][TYPE_BUG] = 0.5f;
		gTypeChart[TYPE_FIGHTING][TYPE_ROCK] = 2.0f;
		gTypeChart[TYPE_FIGHTING][TYPE_GHOST] = 0.0f;
		gTypeChart[TYPE_FIGHTING][TYPE_DARK] = 2.0f;
		gTypeChart[TYPE_FIGHTING][TYPE_STEEL] = 2.0f;

		gTypeChart[TYPE_POISON][TYPE_GRASS] = 2.0f;
		gTypeChart[TYPE_POISON][TYPE_POISON] = 0.5f;
		gTypeChart[TYPE_POISON][TYPE_GROUND] = 0.5f;
		gTypeChart[TYPE_POISON][TYPE_ROCK] = 0.5f;
		gTypeChart[TYPE_POISON][TYPE_GHOST] = 0.5f;
		gTypeChart[TYPE_POISON][TYPE_STEEL] = 0.0f;

		gTypeChart[TYPE_GROUND][TYPE_FIRE] = 2.0f;
		gTypeChart[TYPE_GROUND][TYPE_ELECTRIC] = 2.0f;
		gTypeChart[TYPE_GROUND][TYPE_GRASS] = 0.5f;
		gTypeChart[TYPE_GROUND][TYPE_POISON] = 2.0f;
		gTypeChart[TYPE_GROUND][TYPE_FLYING] = 0.0f;
		gTypeChart[TYPE_GROUND][TYPE_BUG] = 0.5f;
		gTypeChart[TYPE_GROUND][TYPE_ROCK] = 2.0f;
		gTypeChart[TYPE_GROUND][TYPE_STEEL] = 2.0f;

		gTypeChart[TYPE_FLYING][TYPE_ELECTRIC] = 0.5f;
		gTypeChart[TYPE_FLYING][TYPE_GRASS] = 2.0f;
		gTypeChart[TYPE_FLYING][TYPE_FIGHTING] = 2.0f;
		gTypeChart[TYPE_FLYING][TYPE_BUG] = 2.0f;
		gTypeChart[TYPE_FLYING][TYPE_ROCK] = 0.5f;
		gTypeChart[TYPE_FLYING][TYPE_STEEL] = 0.5f;

		gTypeChart[TYPE_PSYCHIC][TYPE_FIGHTING] = 2.0f;
		gTypeChart[TYPE_PSYCHIC][TYPE_POISON] = 2.0f;
		gTypeChart[TYPE_PSYCHIC][TYPE_PSYCHIC] = 0.5f;
		gTypeChart[TYPE_PSYCHIC][TYPE_DARK] = 0.0f;
		gTypeChart[TYPE_PSYCHIC][TYPE_STEEL] = 0.5f;

		gTypeChart[TYPE_BUG][TYPE_FIRE] = 0.5f;
		gTypeChart[TYPE_BUG][TYPE_GRASS] = 2.0f;
		gTypeChart[TYPE_BUG][TYPE_FIGHTING] = 0.5f;
		gTypeChart[TYPE_BUG][TYPE_POISON] = 0.5f;
		gTypeChart[TYPE_BUG][TYPE_FLYING] = 0.5f;
		gTypeChart[TYPE_BUG][TYPE_PSYCHIC] = 2.0f;
		gTypeChart[TYPE_BUG][TYPE_GHOST] = 0.5f;
		gTypeChart[TYPE_BUG][TYPE_DARK] = 2.0f;
		gTypeChart[TYPE_BUG][TYPE_STEEL] = 0.5f;

		gTypeChart[TYPE_ROCK][TYPE_FIRE] = 2.0f;
		gTypeChart[TYPE_ROCK][TYPE_ICE] = 2.0f;
		gTypeChart[TYPE_ROCK][TYPE_FIGHTING] = 0.5f;
		gTypeChart[TYPE_ROCK][TYPE_GROUND] = 0.5f;
		gTypeChart[TYPE_ROCK][TYPE_FLYING] = 2.0f;
		gTypeChart[TYPE_ROCK][TYPE_BUG] = 2.0f;
		gTypeChart[TYPE_ROCK][TYPE_STEEL] = 0.5f;

		gTypeChart[TYPE_GHOST][TYPE_NORMAL] = 0.0f;
		gTypeChart[TYPE_GHOST][TYPE_PSYCHIC] = 2.0f;
		gTypeChart[TYPE_GHOST][TYPE_GHOST] = 2.0f;
		gTypeChart[TYPE_GHOST][TYPE_DARK] = 0.5f;
		gTypeChart[TYPE_GHOST][TYPE_STEEL] = 0.5f;

		gTypeChart[TYPE_DRAGON][TYPE_DRAGON] = 2.0f;
		gTypeChart[TYPE_DRAGON][TYPE_STEEL] = 0.5f;

		gTypeChart[TYPE_DARK][TYPE_FIGHTING] = 0.5f;
		gTypeChart[TYPE_DARK][TYPE_PSYCHIC] = 2.0f;
		gTypeChart[TYPE_DARK][TYPE_GHOST] = 2.0f;
		gTypeChart[TYPE_DARK][TYPE_DARK] = 0.5f;
		gTypeChart[TYPE_DARK][TYPE_STEEL] = 0.5f;

		gTypeChart[TYPE_STEEL][TYPE_FIRE] = 0.5f;
		gTypeChart[TYPE_STEEL][TYPE_WATER] = 0.5f;
		gTypeChart[TYPE_STEEL][TYPE_ELECTRIC] = 0.5f;
		gTypeChart[TYPE_STEEL][TYPE_ICE] = 2.0f;
		gTypeChart[TYPE_STEEL][TYPE_ROCK] = 2.0f;
		gTypeChart[TYPE_STEEL][TYPE_STEEL] = 0.5f;
	}
}