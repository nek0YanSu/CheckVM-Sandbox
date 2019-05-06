#include <windows.h>
#include <stdio.h>
#include <string>

bool CheckTemp(){
    int file_count = 0;
    DWORD dwRet;
    LPSTR pszOldVal;
    pszOldVal = (LPSTR)malloc(4096 * sizeof(char));
    dwRet = GetEnvironmentVariableA("TEMP",pszOldVal, 4096);

    std::string stdstr = pszOldVal;
    stdstr += "\\*";

    LPSTR s = const_cast<char *>(stdstr.c_str());

    WIN32_FIND_DATAA data;
    HANDLE hFind = FindFirstFileA(s, &data);
    if (hFind != INVALID_HANDLE_VALUE){
        do{
            file_count++;
        } while (FindNextFileA(hFind, &data));
        FindClose(hFind);
    }
    printf("count:%d\n",file_count);
    if (file_count < 30)
        return false;
    else
        return true;
}

int main()
{
    CheckTemp();
    return 0;
}