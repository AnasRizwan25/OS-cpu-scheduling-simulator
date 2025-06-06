#include "scheduler.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>  

void printResults(const std::vector<Process>& processes) {
    int totalWT = 0, totalTAT = 0;
    std::cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (const auto& p : processes) {
        std::cout << p.pid << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t" 
                  << p.completionTime << "\t" << p.turnaroundTime << "\t" << p.waitingTime << "\n";
        totalWT += p.waitingTime;
        totalTAT += p.turnaroundTime;
    }
    std::cout << "\nAverage Waiting Time: " << (float)totalWT / processes.size();
    std::cout << "\nAverage Turnaround Time: " << (float)totalTAT / processes.size() << "\n";
}

void fcfsScheduling(std::vector<Process>& processes) {
    std::sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;
    for (auto& p : processes) {
        currentTime = std::max(currentTime, p.arrivalTime);
        p.waitingTime = currentTime - p.arrivalTime;
        currentTime += p.burstTime;
        p.completionTime = currentTime;
        p.turnaroundTime = p.completionTime - p.arrivalTime;
    }

    printResults(processes);
}

void sjfScheduling(std::vector<Process>& processes) {
    int n = processes.size();
    int completed = 0;
    int time = 0;
    std::vector<bool> isCompleted(n, false);

    while (completed < n) {
        int idx = -1;
        int minBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= time && !isCompleted[i] && processes[i].burstTime < minBurst) {
                minBurst = processes[i].burstTime;
                idx = i;
            }
        }

        if (idx != -1) {
            processes[idx].waitingTime = time - processes[idx].arrivalTime;
            time += processes[idx].burstTime;
            processes[idx].completionTime = time;
            processes[idx].turnaroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
            isCompleted[idx] = true;
            completed++;
        } else {
            time++;
        }
    }

    printResults(processes);
}

void roundRobinScheduling(std::vector<Process>& processes, int quantum) {
    std::queue<int> q;
    int n = processes.size();
    int time = 0;
    int completed = 0;
    std::vector<int> remainingTime(n);
    std::vector<bool> inQueue(n, false);

    for (int i = 0; i < n; i++) {
        remainingTime[i] = processes[i].burstTime;
    }

    // Start with first arriving process(es)
    for (int i = 0; i < n; i++) {
        if (processes[i].arrivalTime <= time && !inQueue[i]) {
            q.push(i);
            inQueue[i] = true;
        }
    }

    if (q.empty()) { // No process arrived at time 0
        time = processes[0].arrivalTime;
        q.push(0);
        inQueue[0] = true;
    }

    while (completed < n) {
        if (q.empty()) {
            time++;
            // Check if any new process arrived
            for (int i = 0; i < n; i++) {
                if (processes[i].arrivalTime <= time && !inQueue[i] && remainingTime[i] > 0) {
                    q.push(i);
                    inQueue[i] = true;
                }
            }
            continue;
        }

        int idx = q.front();
        q.pop();

        int execTime = std::min(quantum, remainingTime[idx]);
        remainingTime[idx] -= execTime;
        time += execTime;

        // Add newly arrived processes during this quantum
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= time && !inQueue[i] && remainingTime[i] > 0) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (remainingTime[idx] == 0) {
            completed++;
            processes[idx].completionTime = time;
            processes[idx].turnaroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
            processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;
        } else {
            q.push(idx); // Re-add to queue if not finished
        }
    }

    printResults(processes);
}

void priorityScheduling(std::vector<Process>& processes) {
    int n = processes.size();
    int completed = 0;
    int time = 0;
    std::vector<bool> isCompleted(n, false);

    while (completed < n) {
        int idx = -1;
        int highestPriority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= time && !isCompleted[i] && processes[i].priority < highestPriority) {
                highestPriority = processes[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            processes[idx].waitingTime = time - processes[idx].arrivalTime;
            time += processes[idx].burstTime;
            processes[idx].completionTime = time;
            processes[idx].turnaroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
            isCompleted[idx] = true;
            completed++;
        } else {
            time++;
        }
    }

    printResults(processes);
}
