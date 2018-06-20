#include"../MicoThread.h"
#include"../Scheduler.h"

#include<iostream>

using namespace mt;

Scheduler s;

void f1(){
    while(1){
        std::cout<<1<<std::endl;
        s.yield();
    }   
}

void f2(){
    while(1){
        std::cout<<2<<std::endl;
        s.yield();
    }
}

int main(){
    
    s.append_thread(f1);
    s.append_thread(f2);



    while(1){
        s.resume(0);
        s.resume(1);
    }


    return 0;
}
