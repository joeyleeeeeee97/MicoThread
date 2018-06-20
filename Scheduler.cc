#include"Scheduler.h"

using namespace mt;


void Scheduler::yield(){
    if(curthread_idx == -1){
        return ;
    }
    mthread* t = threads[curthread_idx];
    t->state = State::SUSPEND;
    curthread_idx = -1;
    
    swapcontext(&(t->context), &main);

}

void Scheduler::resume(int id){
    if(id < 0 || id >= threads.size()){
        return ;
    }
    
    mthread* t = threads[id]; 
    
    if(t->state == State::SUSPEND){
        curthread_idx  = id;
        swapcontext(&main, &(t->context));
    
    }
    
}

int Scheduler::finished(){
    for(auto& mt : threads){
        if(mt->state != State::FREE){
            return 0;
        }
    }
    return 1;
}
