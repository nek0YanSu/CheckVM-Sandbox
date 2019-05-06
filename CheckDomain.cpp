#include <windows.h>
#include <stdio.h>
#include <LM.h>
bool is_member_of_domain()
{
    bool ret = false;
    DWORD dwLevel = 100;
    LPWKSTA_INFO_100 pBuf = NULL;
    NET_API_STATUS nStatus;
    LPWSTR pszServerName = L"localhost";
    nStatus = NetWkstaGetInfo(pszServerName, dwLevel, (LPBYTE *)&pBuf);
    if (nStatus == NERR_Success)
    {
        char response[512];
        wcstombs(response, pBuf->wki100_langroup, 500);
        char workgroup[] = "WORKGROUP";
        printf("rsp:%s\n",response);
        if (strcmp(response, workgroup)) // returns 0 if identical
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return ret;
}

int main(){
    is_member_of_domain();
    return 0;
}