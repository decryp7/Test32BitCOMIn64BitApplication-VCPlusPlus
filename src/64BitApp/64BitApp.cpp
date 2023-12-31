// 64BitApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"

#include <chrono>
#include <iostream>
using namespace std;

void ErrorDescription(HRESULT hr)
{
	TCHAR* szErrMsg;
	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM, NULL, hr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&szErrMsg, 0, NULL) != 0)
	{
		std::cout << szErrMsg << std::endl;
		LocalFree(szErrMsg);
	}
	else
		std::cout << "Could not find a description for error 0x"
		<< std::hex << hr << std::dec << std::endl;
}

int main()
{
	CoInitializeEx(0, COINIT_MULTITHREADED);

	{
		using std::chrono::high_resolution_clock;
		using std::chrono::duration_cast;
		using std::chrono::duration;
		using std::chrono::milliseconds;

		IUserSecurityPtr ptr;
		HRESULT hr = ptr.CreateInstance(__uuidof(UserSecurity));
		if (SUCCEEDED(hr))
		{
			auto t1 = high_resolution_clock::now();
			auto hello = ptr->SayHello();
			auto t2 = high_resolution_clock::now();

			cout << hello << endl;

			/* Getting number of milliseconds as a double. */
			duration<double, std::milli> ms_double = t2 - t1;

			std::cout << ms_double.count() << "ms";
		}
		else
		{
			ErrorDescription(hr);
		}

		char c;
		cin >> c;
	}
	
	CoUninitialize();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
