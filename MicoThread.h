/*************************************************************************
	> File Name: MicoThread.h
	> Author: 
	> Mail: 
	> Created Time: Tue 19 Jun 2018 11:08:05 AM DST
 ************************************************************************/

#ifndef _MICOTHREAD_H
#define _MICOTHREAD_H
#include<ucontext.h>
#include<functional>
namespace mt{
enum State{RUNNING, FREE, RUNNABLE, SUSPEND};

class mthread{
public:
    mthread():state(FREE),func(), context(), stack(){};


    enum State state;
    std::function<void()> func;
    ucontext_t context;
    char stack[1024 * 128];

};

}
#endif
