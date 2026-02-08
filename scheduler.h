// this is a general interface scheduler which will be acting between main.cpp and FIFO_scheduler.cpp

// #ifndef : if not define ; is used to prevent redefination errors, since we don't want scheduler to preserve it's memory, that can cause problems in FIFO.

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"


class Scheduler{
public: 
    // instead of constrcutor, we use destructor, to always clear memory before running
    virtual ~Scheduler() {}

    // on_process_ready() is a void function that takes Process pointer P. 
    // virtual ..... = 0 : is written in notes.
    virtual void on_process_ready(Process* P) = 0;

    // get_next_process is Process8 type function since it will be returning the process from queue
    virtual Process* get_next_process() = 0;

};

#endif