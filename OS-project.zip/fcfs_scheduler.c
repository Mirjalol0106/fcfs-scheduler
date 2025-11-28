#include <stdio.h>
#include <stdlib.h>

// Simple structure to store process information
typedef struct {
    int processID;           // Process number (P1, P2, etc.)
    int arrivalTime;         // When it arrives
    int burstTime;           // How long it needs CPU
    int startTime;           // When it starts executing
    int completionTime;      // When it finishes
    int waitingTime;         // How long it waited
    int turnaroundTime;      // Total time in system
} Process;


// Function to sort processes by arrival time (earliest first)
void sortProcessesByArrival(Process processes[], int numberOfProcesses) {
    
    for (int i = 0; i < numberOfProcesses - 1; i++) {
        for (int j = 0; j < numberOfProcesses - i - 1; j++) {
            
           
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                
                
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}


int main() {
    
    int numberOfProcesses;
    
    printf("\n========================================\n");
    printf("   FCFS CPU SCHEDULING SIMULATOR\n");
    printf("========================================\n\n");
    
    printf("How many processes do you want? ");
    scanf("%d", &numberOfProcesses);
    
    
    // Create array to store all processes
    Process *processes = (Process*)malloc(numberOfProcesses * sizeof(Process));
    
    
    // Get information for each process
    printf("\nEnter details for each process:\n");
    printf("--------------------------------\n");
    
    for (int i = 0; i < numberOfProcesses; i++) {
        
        processes[i].processID = i + 1;  // P1, P2, P3, etc.
        
        printf("\nProcess P%d:\n", processes[i].processID);
        
        printf("  When does it arrive? ");
        scanf("%d", &processes[i].arrivalTime);
        
        printf("  How long does it need CPU? ");
        scanf("%d", &processes[i].burstTime);
    }
    
    
    // Sort processes by arrival time (FCFS = First Come First Served!)
    printf("\n\nSorting processes by arrival time...\n");
    sortProcessesByArrival(processes, numberOfProcesses);
    
    
    // Start the scheduling simulation
    printf("\n========================================\n");
    printf("   RUNNING FCFS ALGORITHM\n");
    printf("========================================\n\n");
    
    int currentTime = 0;  // This keeps track of time
    
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;
    
    
    // Process each process one by one
    for (int i = 0; i < numberOfProcesses; i++) {
        
        printf("Time %d: ", currentTime);
        
        // If CPU is idle (current time is before process arrival), wait
        if (currentTime < processes[i].arrivalTime) {
            printf("CPU is idle, waiting for P%d to arrive...\n", processes[i].processID);
            currentTime = processes[i].arrivalTime;
            printf("Time %d: ", currentTime);
        }
        
        // Process arrives and starts
        processes[i].startTime = currentTime;
        printf("P%d starts executing\n", processes[i].processID);
        
        // Calculate when it will complete
        processes[i].completionTime = currentTime + processes[i].burstTime;
        
        // Calculate waiting time (how long it waited before starting)
        // Formula: Waiting Time = Start Time - Arrival Time
        processes[i].waitingTime = processes[i].startTime - processes[i].arrivalTime;
        
        // Calculate turnaround time (total time from arrival to completion)
        // Formula: Turnaround Time = Completion Time - Arrival Time
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        
        printf("         P%d will run for %d time units\n", 
               processes[i].processID, 
               processes[i].burstTime);
        
        // Update current time to when this process finishes
        currentTime = processes[i].completionTime;
        
        printf("Time %d: P%d completed!\n\n", currentTime, processes[i].processID);
        
        // Add to totals for calculating averages
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }
    
    
    // Show final results in a nice table
    printf("\n========================================\n");
    printf("           FINAL RESULTS\n");
    printf("========================================\n\n");
    
    printf("┌─────────┬─────────┬───────┬───────┬────────┬─────────┬───────────┐\n");
    printf("│ Process │ Arrival │ Burst │ Start │  End   │ Waiting │ Turnaround│\n");
    printf("├─────────┼─────────┼───────┼───────┼────────┼─────────┼───────────┤\n");
    
    for (int i = 0; i < numberOfProcesses; i++) {
        printf("│   P%-2d   │   %-3d   │  %-3d  │  %-3d  │  %-4d  │   %-4d  │    %-5d  │\n",
               processes[i].processID,
               processes[i].arrivalTime,
               processes[i].burstTime,
               processes[i].startTime,
               processes[i].completionTime,
               processes[i].waitingTime,
               processes[i].turnaroundTime);
    }
    
    printf("└─────────┴─────────┴───────┴───────┴────────┴─────────┴───────────┘\n\n");
    
    
    // Calculate and show averages
    float averageWaitingTime = totalWaitingTime / numberOfProcesses;
    float averageTurnaroundTime = totalTurnaroundTime / numberOfProcesses;
    
    printf("📊 PERFORMANCE METRICS:\n");
    printf("   • Average Waiting Time    = %.2f time units\n", averageWaitingTime);
    printf("   • Average Turnaround Time = %.2f time units\n\n", averageTurnaroundTime);
    
    
    
    // Free the memory we used
    free(processes);
    
    printf("========================================\n");
    printf("Thank you for using FCFS Scheduler!\n");
    printf("========================================\n\n");
    
    return 0;
}


