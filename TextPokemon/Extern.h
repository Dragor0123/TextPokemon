#pragma once

#ifndef __EXTERN_H__
#define __EXTERN_H__

namespace poke_glob {
	extern float gTypeChart[TYPE_END][TYPE_END];
	
	void Init_TypeChart(void);
	void Output_TextMsg(const char* _filename);

	bool Is_ZX_Key_Pushed();
}

#endif // !__EXTERN_H__