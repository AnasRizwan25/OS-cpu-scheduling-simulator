#include "scheduler.h"
#include <iostream>
#include <vector>

int main() {
    int n, algo, quantum;
    std::cout << "Enter number of processes: ";
    std::cin >> n;

    std::vector<Process> processes(n);

    for (int i = 0; i < n; ++i) {
        processes[i].pid = i + 1;
        std::cout << "Process " << i + 1 << " Arrival Time: ";
        std::cin >> processes[i].arrivalTime;
        std::cout << "Process " << i + 1 << " Burst Time: ";
        std::cin >> processes[i].burstTime;
        std::cout << "Process " << i + 1 << " Priority (lower number = higher priority): ";
        std::cin >> processes[i].priority;
        processes[i].completionTime = 0;
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
        processes[i].remainingTime = processes[i].burstTime;
    }

    std::cout << "\nChoose Scheduling Algorithm:\n";
    std::cout << "1. FCFS\n2. SJF\n3. Round Robin\n4. Priority\nChoice: ";
    std::cin >> algo;

    if (algo == 3) {
        std::cout << "Enter Time Quantum: ";
        std::cin >> quantum;
    }

    switch (algo) {
        case 1: fcfsScheduling(processes); break;
        case 2: sjfScheduling(processes); break;
        case 3: roundRobinScheduling(processes, quantum); break;
        case 4: priorityScheduling(processes); break;
        default: std::cout << "Invalid Choice\n";
    }

    return 0;
}
