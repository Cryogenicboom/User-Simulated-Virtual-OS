// fifo_scheduler.h
#ifndef FIFO_SCHEDULER_H
#define FIFO_SCHEDULER_H

#include "scheduler.h"
#include <queue>

// FIFO SCHEDULER class inherits Scheduler class from scheduler.h file
class FIFOScheduler : public Scheduler{
private:
    std::queue<Process*> ready_queue;

public: 
    // only declaration, defination in FIF_scheduler.cpp
    void on_process_ready(Process* P);
    Process* get_next_process();
};


#endif