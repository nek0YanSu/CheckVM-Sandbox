#include <stdio.h>
#include <windows.h>

bool CheckCPU(){
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    int CoreNum = sysinfo.dwNumberOfProcessors;
    printf("Core:%d\n",CoreNum);
    if(CoreNum < 4)
        return false;
    else
        return true;
}

int main(){
    if(CheckCPU())
        printf("ok");
    else
        printf("error");
    return 0;
}