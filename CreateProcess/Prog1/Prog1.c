#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void ExitSys(LPCSTR lpszMsg);

int main(void)
{
	char szPath[] = "..\\x64\\Debug\\Prog2.exe arg1 arg2";
	STARTUPINFO si = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION pa;

	if (!CreateProcess(NULL, szPath, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pa))
	{
		ExitSys("CreateProcess");
	}


	return 0;
}

void ExitSys(LPCSTR lpszMsg)
{
	DWORD dwLastError = GetLastError();
	LPTSTR lpszErr;

	if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL)) {
		fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
		LocalFree(lpszErr);
	}

	exit(EXIT_FAILURE);
}