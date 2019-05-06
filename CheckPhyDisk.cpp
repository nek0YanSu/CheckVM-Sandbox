#include <windows.h>
#include <stdio.h>

bool CheckPhyDisk(){
    HANDLE hDrive;
    GET_LENGTH_INFORMATION size;
    DWORD lpBytes;
    hDrive = CreateFileA("\\\\.\\PhysicalDrive0", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if(hDrive == INVALID_HANDLE_VALUE){
        printf("Error");
        CloseHandle(hDrive);
        return false;
    }
    bool result = DeviceIoControl(hDrive, IOCTL_DISK_GET_LENGTH_INFO, NULL, 0, &size,
    sizeof(GET_LENGTH_INFORMATION), &lpBytes, NULL);
    CloseHandle(hDrive);
    printf("disk size:%d\n",(size.Length.QuadPart / 1073741824));
    if((size.Length.QuadPart / 1073741824) > 110 ){
        return true;
    }else{
        return true;
    }
}



int main(){
    CheckPhyDisk();
    return 0;
}