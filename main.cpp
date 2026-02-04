#include <iostream>
#include <string>
#include "process.h"

const char* Process_state(ProcessState process){
    switch (process1.state) {
        case ProcessState::New:
            std::cout << "New\n";
            break;
        case ProcessState::Ready:
            std::cout << "Ready\n";
            break;
        case ProcessState::Running:
            std::cout << "Running\n";
            break;
        case ProcessState::Blocked:
            std::cout << "Blocked\n";
            break;
        case ProcessState::Finished:
            std::cout << "Finished\n";
            break;
    }
}

int main(){
    int global_time = 1;
    
    Process process1(101, 4, 0);

    std::cout << process1.pid<<"\n";

    // to print custom "enum" class, convert explicity it to integer then access its element
    // int state_index = static_cast<int>(process1.state);
    switch (process1.state) {
    case ProcessState::New:
        std::cout << "New\n";
        break;
    case ProcessState::Ready:
        std::cout << "Ready\n";
        break;
    case ProcessState::Running:
        std::cout << "Running\n";
        break;
    case ProcessState::Blocked:
        std::cout << "Blocked\n";
        break;
    case ProcessState::Finished:
        std::cout << "Finished\n";
        break;
    }
    std::cout << process1.cpu_time_total;

    process1.cpu_time_remaining = process1.cpu_time_total;
    while(global_time){
        switch (process1.state) {
            case ProcessState::New:
                process1.state = ProcessState :: Ready;
                break;
            case ProcessState::Ready:
                process1.state = ProcessState :: Running;
                break;
            case ProcessState :: Running:
                if(process1.cpu_time_remaining == 0){
                    process1.state = ProcessState :: Finished;
                    break;
                }
                break;
        
        std::cout<<"Tick = "<<global_time;
        std::cout<<"\ncurrent state ="<<process1.state;
        
        process1.cpu_time_remaining -= 1;
        global_time ++;

        
        }
    }
    return 0; 
}