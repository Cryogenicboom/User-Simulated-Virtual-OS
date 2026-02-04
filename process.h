

// enum is used to store const values.
enum class ProcessState{
    New, 
    Ready,
    Running,
    Blocked,
    Finished
};

// structure of a process
class Process{
public: 
    int pid;
    ProcessState state;
    int cpu_time_total;
    int cpu_time_remaining;
    int arrival_time, finish_time, first_run_time;

    Process(int pid, int cpu_time_total, int arrival_time) {
    this->pid = pid;
    this->state = ProcessState::Ready;
    this->cpu_time_total = cpu_time_total;
    this->cpu_time_remaining = cpu_time_total;
    this->arrival_time = arrival_time;
    this->finish_time = -1;
    this->first_run_time = -1;
}
};