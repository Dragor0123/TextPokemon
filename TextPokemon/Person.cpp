#include "stdafx.h"
#include "Person.h"

CPerson::CPerson()
{
}


CPerson::~CPerson()
{
}

void CPerson::Set_Name(const char * _pName)
{
	strcpy_s(m_szName, MAX_NAME_SIZE, _pName);
}

const char* CPerson::Get_Name()
{
	return m_szName;
}
