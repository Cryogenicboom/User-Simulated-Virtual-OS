// Every type of TIME is always calculated as a whole number, considering "0" as your starting point

#include <iostream>
#include <string>
#include "process.h"
#include "fifo_scheduler.h"
#include <vector>

const char* Process_state(ProcessState state){
    switch (state) {
        case ProcessState::New:
            return "New";
        case ProcessState::Ready:
            return "Ready";
        case ProcessState::Running:
            return "Running";
        case ProcessState::Blocked:
            return "Blocked";
        case ProcessState::Finished:
            return "Finished";
    }
    return "N.A.";
}

int main(){

    // Scheduler Object: Working in Notes
    Scheduler* scheduler = new FIFOScheduler();

    Process process1(101, 4, 0);
    Process process2(102, 6, 3);
    Process process3(103, 7, 5);
    std::vector<Process*> process_vector = {&process1, &process2, &process3};

    // intial CPU STATE, cpu_running = nullptr means cpu is idle. 
    // and since it is declared a Process*, that means this is a variable and can only run one process at a time
    Process* cpu_running = nullptr;

    int global_time = 0;
    std::cout<<"Kernal Starting\n";

    while(true){

        // When process has arrival_time = global_time ; NEW --> READY ; and when READY its send to Scheduler's QUEUE

        // for ( a:b ) means for(a in range of b)
        for (Process* p : process_vector) {   
            // if( *p.state == Processstate :: NEW && *p.arrival_time == global time)
            if (p->state == ProcessState::New && p->arrival_time == global_time) {
                p->state = ProcessState::Ready;
                // *scheduler.on_process_ready(p)
                scheduler->on_process_ready(p);
            }
        }
        if(cpu_running != nullptr){
                cpu_running->cpu_time_remaining--;

                if(cpu_running->cpu_time_remaining == 0){
                    cpu_running -> state = ProcessState :: Finished;
                    cpu_running -> finish_time = global_time + 1;
                    cpu_running = nullptr;
                }
            }   

        // calling scheduler whenever CPU is idle
        if(cpu_running == nullptr){
            // class the next processs from scheduler's queue and store it in next variable
            Process* next = scheduler -> get_next_process();
            if(next!=nullptr){
                cpu_running = next;
                // now cpu_running represents the current running process and that's why below cpu_running means process.
                cpu_running -> state = ProcessState :: Running;
                if(cpu_running -> first_run_time == -1){
                    cpu_running -> first_run_time = global_time;
                }
            }
        }   

        std::cout << "\nTick = " << global_time << "\n";
        for (Process* p : process_vector) {
            std::cout << "P" << p->pid << " : "
                      << Process_state(p->state)
                      << " | remaining = "
                      << p->cpu_time_remaining << "\n";
        }
        
        // check if all process are finished
        bool all_finished = true;
        for (Process* p : process_vector) {
            if (p->state != ProcessState::Finished) {
                all_finished = false;
                break;
            }
        }

        // if (all_finished){
        //     break;
        // }
    
        global_time++;
        std::exit(all_finished);
    }

    std::cout<<"Kernal Switch off";
    return 0; 

}