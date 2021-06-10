// UserSecurity.cpp : Implementation of CUserSecurity

#include "pch.h"
#include "UserSecurity.h"


// CUserSecurity



STDMETHODIMP CUserSecurity::SayHello(BSTR* pHello)
{
	*pHello = SysAllocString(L"Hello, I am a 32bit library!");
	Sleep(2000);

	return S_OK;
}
