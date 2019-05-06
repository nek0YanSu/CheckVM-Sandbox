#include <stdio.h>
#include <string.h>

bool checkMAC(){
    char buffer[128];
    char result[1024*50] = "";
    char MAC[] = "08-00-27";
    FILE *pipe = _popen("ipconfig /all","r");
    if(!pipe)
        return 0;
    
    while(!feof(pipe)){
        if(fgets(buffer,128,pipe))
            strcat(result,buffer);
    }
    _pclose(pipe);
    //08-00-27
    if(strstr(result,MAC))
        return false;
    else
        return true;
}


int main(){
    if(checkMAC())
        printf("正常运行\n");
    else
        printf("vbox虚拟机运行\n");
    getchar();
    
}