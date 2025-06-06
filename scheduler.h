#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
};

void fcfsScheduling(std::vector<Process>& processes);
void sjfScheduling(std::vector<Process>& processes);
void roundRobinScheduling(std::vector<Process>& processes, int quantum);
void priorityScheduling(std::vector<Process>& processes);
void printResults(const std::vector<Process>& processes);

#endif
