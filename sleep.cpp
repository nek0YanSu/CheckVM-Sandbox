#include <stdio.h>
#include <thread>

int main(){
    std::chrono::seconds t = std::chrono::seconds(60);
    std::this_thread::sleep_for(t);
    return 0;
}



