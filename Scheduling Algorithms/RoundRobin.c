#include <stdio.h>

int main() 
{
    int n, quantum;

    // User input for number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n]; // Arrival Time, Burst Time, Remaining Time
    int wt[n], tat[n]; // Waiting Time, Turnaround Time
    int total_wt = 0, total_tat = 0, time = 0;
    
    // User input for Arrival Time and Burst Time
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Remaining Time initially equal to Burst Time
    }

    // Input Time Quantum
    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    // Round Robin Scheduling
    int done;
    do 
    {
        done = 1;
        for (int i = 0; i < n; i++) 
        {
            if (rt[i] > 0 && at[i] <= time) 
            {
                done = 0; // At least one process is still remaining
                
                if (rt[i] > quantum) 
                {
                    time += quantum;
                    rt[i] -= quantum;
                } 
                else 
                {
                    time += rt[i];
                    wt[i] = time - at[i] - bt[i]; // Waiting Time = Completion Time - Arrival Time - Burst Time
                    tat[i] = time - at[i]; // Turnaround Time = Completion Time - Arrival Time
                    rt[i] = 0; // Process is fully executed
                }
            }
        }
    } 
    while (!done);

    // Calculate total waiting time and turnaround time
    for (int i = 0; i < n; i++) 
    {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Display process details
    printf("\nProcesses  Arrival Time  Burst Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) 
    {
        printf("  %d\t\t%d\t    %d\t\t   %d\t\t   %d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    // Print average waiting time and turnaround time
    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);

    return 0;
}