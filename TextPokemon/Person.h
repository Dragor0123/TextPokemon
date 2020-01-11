#pragma once

#ifndef __PERSON_H__
#define __PERSON_H__

class CPerson
{
public:
	CPerson();
	virtual ~CPerson();

	void Set_Name(const char* _pName);
	const char* Get_Name();

protected:
	char m_szName[MAX_NAME_SIZE];
};

#endif