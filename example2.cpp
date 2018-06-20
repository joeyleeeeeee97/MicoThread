/*************************************************************************
	> File Name: example2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Jun 2018 04:25:02 PM DST
 ************************************************************************/

#include<iostream>
#include<ucontext.h>
#include<stdio.h>
#include<functional>

using namespace std;

typedef function<void()> FUn;

char stack[1024 * 128];

void before_main(){
    cout<<"before main"<<endl;
}

int main(){
    ucontext_t child, main;
    
    getcontext(&child);
    child.uc_stack.ss_sp = stack;
    child.uc_stack.ss_size = sizeof(stack);
    child.uc_stack.ss_flags = 0;
    child.uc_link = &main;// next context

    makecontext(&child, (void (*)(void))before_main, 0);

    swapcontext(&main, &child);
    cout<<"main"<<endl;
    return 0;

}
