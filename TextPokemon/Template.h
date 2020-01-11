#pragma once
#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

namespace poke_template
{
	template<typename T>
	using fptr_SelMenu = void(T::*)(char*, int, int, POS&);
	//
	template <typename T>
	int Up_Down_Select_Interface(fptr_SelMenu<T> _fpRenderMenu,
		char* _szMenu, int _rowSize, int _colSize, POS& _selPos)
	{
		int iInput = 0;
		T t;
		while (true) {
			system("cls");
			cout << string(40, '=') << '\n';
			(t.*_fpRenderMenu)(_szMenu, _rowSize, _colSize, _selPos);

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
					--_selPos.y;
					_selPos.y = (_selPos.y < 0) ? 0 : _selPos.y;
					break;
				case DOWN:
					++_selPos.y;
					_selPos.y = (_selPos.y > _rowSize - 1) ? _rowSize - 1 : _selPos.y;
					break;
				}
			}
			else {
				iInput = tolower(iInput);
				if ('z' == iInput)
					return _selPos.y + 1;
				else if ('x' == iInput)
					return 0;
			}
		}
	}

}

#endif