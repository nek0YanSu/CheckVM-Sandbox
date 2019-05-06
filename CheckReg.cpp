// CheckReg.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <Windows.h>
#include <winreg.h>

bool checkReg() {
	HKEY hkey;
	if (RegOpenKey(HKEY_CLASSES_ROOT, "\\Applications\\VMwareHostOpen.exe", &hkey) == ERROR_SUCCESS) {
		return true;
	}
	else {
		return false;
	}

}

int main()
{
	if (checkReg()) {
		printf("检测到虚拟机");
	}
	else {
		printf("未检测到虚拟机");
	}
	getchar();
	return 0;
}

