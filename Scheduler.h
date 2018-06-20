/*************************************************************************
	> File Name: Scheduler.h
	> Author: 
	> Mail: 
	> Created Time: Sun 17 Jun 2018 07:43:14 PM DST
 ************************************************************************/

#ifndef _SCHEDULER_H
#define _SCHEDULER_H
#include<vector>
#include<functional>
#include<ucontext.h>
#include"MicoThread.h"

namespace mt{

class Scheduler{
public:
    Scheduler():curthread_idx(-1),threads_num(0),threads(),main(){}
    ~Scheduler(){}

    void resume(int id);
    //Hang current mthread switch to main 
    void yield();
    //return num of RUNNING mthread
    int finished();
    //add new thread
    int append_thread(const std::function<void()>& f){
        int id =  0;
        for(;id < threads.size();id++){
            if(threads[id]!=nullptr && threads[id]->state != FREE){
                continue;
            }
        }
        if(id == threads.size()){
            threads.push_back(new mthread());
        }
        if(threads[id] == nullptr ){
            threads[id] == new mthread();
        }
        mthread* t = threads[id];
        t->func = f;
        t->state = RUNNABLE;
        
        getcontext(&(t->context));

        t->context.uc_stack.ss_sp = t->stack;
        t->context.uc_stack.ss_size = 1024 * 128;
        t->context.uc_stack.ss_flags = 0;
        t->context.uc_link = &main;

        curthread_idx = id;
        
   
        makecontext(&(t->context), (void (*)(void))(&Scheduler::main_func), 1, this);
        swapcontext(&main, &(t->context));

        return id;

    }

    void main_func(){
        if(curthread_idx != -1){
            mthread* t = threads[curthread_idx];
            t->func();
            t->state = FREE;
            curthread_idx = -1;
        }
    }
    

    int curthread_idx;
    int threads_num;
    std::vector<mthread*> threads;
    ucontext_t main;

};


}
#endif
