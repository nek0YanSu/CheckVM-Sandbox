// ProcessCheck.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <TlHelp32.h>
int check(char* name) {
	const char* list[2] = { "VBoxService.exe","VBoxTray.exe" };
	for (int i = 0;i < 2;++i) {
		if (strcmp(name, list[i]) == 0)
			return -1;
	}
	return 0;
}
bool CheckProcess() {
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);
	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	BOOL bResult = Process32First(hProcessSnap, &pe32);
	while (bResult) {
		char sz_Name[MAX_PATH] = { 0 };
		WideCharToMultiByte(CP_ACP, 0, pe32.szExeFile, -1, sz_Name, sizeof(sz_Name), NULL, NULL);
		//printf("%s\n", sz_Name);
		if (check(sz_Name) == -1)
			return false;
		bResult = Process32Next(hProcessSnap, &pe32);
	}
	return true;
}
int main(){
	if (CheckProcess() == false) {
		printf("存在虚拟机\n");
	}
	else{
		printf("检测通过!\n");
	}
	getchar();
	return 0;
}
