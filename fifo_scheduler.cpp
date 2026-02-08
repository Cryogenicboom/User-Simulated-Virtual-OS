#include <iostream>
#include <queue>
#include "fifo_scheduler.h"

void FIFOScheduler::on_process_ready(Process* P){
    ready_queue.push(P);
}

Process* FIFOScheduler::get_next_process(){
    if(ready_queue.empty()){
        return nullptr;
    }   

    // storing first process in next_process
    Process* next_process = ready_queue.front();
    ready_queue.pop();
    return next_process;
}