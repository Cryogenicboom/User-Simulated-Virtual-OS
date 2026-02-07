// Every type of TIME is always calculated as a whole number, considering "0" as your starting point

#include <iostream>
#include <string>
#include "process.h"

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
}

int main(){
    Process process1(101, 4, 0);

    int global_time = 1;

    // std::cout << process1.pid<<"\n";
    // // to print custom "enum" class, convert explicity it to integer then access its element
    // // int state_index = static_cast<int>(process1.state);
    // Process_state(process1.state);

    // std::cout << process1.cpu_time_total;
    std::cout<<"Tick = 0\n";
    std::cout<<Process_state(process1.state)<<" is Initial State.\n";
    while(process1.state != ProcessState :: Finished){
        switch (process1.state) {
            case ProcessState::New:
                process1.state = ProcessState :: Ready;
                break;
            case ProcessState::Ready:
                process1.state = ProcessState :: Running;
                break;
            case ProcessState :: Running:
                process1.cpu_time_remaining -= 1;
                if(process1.cpu_time_remaining == 0){
                    process1.state = ProcessState :: Finished;
                    break;
                }
                break;
        }
        int cpu_used = process1.cpu_time_total - process1.cpu_time_remaining;

        std::cout<<"\nTick = "<<global_time;
        std::cout<<"\n";
        std::cout<<Process_state(process1.state)<<"\n";
        global_time ++;
        std::cout<<"cpu time used = "<<cpu_used<<"\n";
        // std::cout<<"\n";
        }
    
    return 0; 
}
