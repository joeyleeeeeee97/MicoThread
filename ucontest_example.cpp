/*************************************************************************
	> File Name: ucontest_example.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Jun 2018 04:06:22 PM DST
 ************************************************************************/

#include<ucontext.h>
#include<unistd.h>
#include<iostream>
using namespace std;


int main(){
    ucontext_t context;
    
    getcontext(&context);
    cout<<"Hello world!"<<endl;
    sleep(1);
    setcontext(&context);

    return 0;
}


