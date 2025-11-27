# FCFS CPU Scheduling Simulator

This project implements a First-Come-First-Served (FCFS) CPU Scheduling Algorithm using C.  


## What is FCFS?

FCFS (First-Come-First-Served) is the simplest CPU scheduling algorithm:

- The process that arrives first runs first.
- Non-preemptive — once a process starts, it runs until completion.
- Uses a basic FIFO queue behavior.
- Easy to implement but can suffer from long waiting times (convoy effect).

## Project Files

fcfs_scheduler.c   – Main FCFS implementation in C  
README.md          – Project documentation  

## How to Run the C Program

### macOS / Linux
gcc fcfs_scheduler.c -o fcfs_scheduler
./fcfs_scheduler

### Windows
gcc fcfs_scheduler.c -o fcfs_scheduler.exe
./fcfs_scheduler.exe

## FCFS Logic (Short)

1. Sort processes by arrival time.
2. If CPU is idle, advance time forward.
3. Start process → Waiting = Start − Arrival.
4. Turnaround = Completion − Arrival.
5. Move time forward by its burst time.

## Output Includes

- Detailed table
- Waiting & Turnaround times
- Averages
- Step-by-step log


## Author
Choriyev Mirjalol
