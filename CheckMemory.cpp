#include <windows.h>
#include <stdio.h>
bool CheckMemory(){
    _MEMORYSTATUSEX mst;
    DWORDLONG d_size = 4294496257;
    mst.dwLength = sizeof(mst);
    GlobalMemoryStatusEx(&mst);
    //printf("PhyMszie:%llu \n",mst.ullTotalPhys);
    if(mst.ullTotalPhys < d_size)
        return false;
    else
        return true;
}
int main(){

    if(CheckMemory())
        printf("ok\n");
    else 
        printf("error!\n");
    getchar();
    return 0;
}