#include <stdio.h>
#include <windows.h>

bool isVM(){
    DWORD dw_ecx;
    bool bFlag = true;
    _asm{
        pushad;
        pushfd;
        mov eax,1;
        cpuid;
        mov dw_ecx,ecx;
        and ecx,0x80000000;
        test ecx,ecx;
        setz[bFlag];
        popfd;
        popad;
    }
    if(bFlag)
    //真实机器
        return false;
    else
        return true;
}



int main(){
    return 0;
}