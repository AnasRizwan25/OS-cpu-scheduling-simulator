# 🧠 CPU Scheduling Simulator (C++)

A terminal-based CPU Scheduling Simulator written in C++ that supports multiple scheduling algorithms. Ideal for learning Operating System concepts and for academic projects.

## 🚀 Features

- Simulates four scheduling algorithms:
  - 🔵 First-Come First-Serve (FCFS)
  - 🟢 Shortest Job First (SJF)
  - 🟣 Round Robin (RR)
  - 🟡 Priority Scheduling
- Calculates:
  - Waiting Time (WT)
  - Turnaround Time (TAT)
  - Completion Time (CT)
- User input-driven — no hardcoded data.
- Simple and clean terminal output.
- Modular codebase using header/source separation.

## 📁 Folder Structure

```
scheduler_project/
├── main.cpp         # Entry point and user input
├── scheduler.cpp    # All scheduling algorithm logic
├── scheduler.h      # Structs and function declarations
├── Makefile         # Build and run automation
```

## 🧰 Requirements

- OS: Linux (Ubuntu preferred)
- Compiler: `g++` (GNU C++ compiler)
- C++11 or above

## ⚙️ How to Build and Run

### 1️⃣ Open terminal and navigate to the project folder:
```bash
cd scheduler_project
```

### 2️⃣ Compile the project using make:
```bash
make
```

### 3️⃣ Run the simulator:
```bash
./scheduler
```

## 🧪 Sample Usage

### ✅ Example Input
```
Enter number of processes: 4

Process 1 Arrival Time: 0
Process 1 Burst Time: 5
Process 1 Priority (lower number = higher priority): 2

Process 2 Arrival Time: 1
Process 2 Burst Time: 3
Process 2 Priority (lower number = higher priority): 1

Process 3 Arrival Time: 2
Process 3 Burst Time: 8
Process 3 Priority (lower number = higher priority): 4

Process 4 Arrival Time: 3
Process 4 Burst Time: 6
Process 4 Priority (lower number = higher priority): 3
```
### Choose Scheduling Algorithm:
```
1. FCFS
2. SJF
3. Round Robin
4. Priority

Choice: 3
Enter Time Quantum: 2
```

### 📤 Example Output
```
PID	AT	BT	CT	TAT	WT
1	0	5	13	13	8
2	1	3	9	8	5
3	2	8	23	21	13
4	3	6	18	15	9

Average Waiting Time: 8.75
Average Turnaround Time: 14.25
```

## 🔧 Algorithms Overview

| Algorithm   | Description |
|------------|-------------|
| FCFS       | Executes processes in the order they arrive. |
| SJF        | Picks the shortest burst time among available processes. |
| Round Robin | Each process gets CPU for a fixed time slice (quantum). |
| Priority   | Lower numerical value = higher priority. Chooses based on priority. |

## 📄 License

This project is licensed under the MIT License.
You are free to use, modify, and distribute it.

## 🤝 Contributing

Want to contribute?
1. Fork the repo
2. Create a feature branch
3. Submit a pull request

## 👨‍💻 Author

**Anas Rizwan**  
Information Technology Undergraduate  
Sir Syed University of Engineering and Technology

---

Let me know if you'd like to add:
- Screenshots of the terminal output
- GitHub badges (build status, license, etc.)
- A GUI version
- Unit tests for the algorithms
