#include <stdio.h>

int main() 
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processes[n], bt[n], at[n], wt[n], tat[n], ct[n];
    int total_wt = 0, total_tat = 0;

    // User input for Arrival Time and Burst Time
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) 
    {
        processes[i] = i + 1;
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sorting processes based on Burst Time (SJF Scheduling)
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (bt[i] > bt[j]) 
            {
                // Swap burst time
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap arrival time
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap process number
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Calculate Completion Time
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) 
    {
        if (ct[i - 1] < at[i]) 
        {
            ct[i] = at[i] + bt[i];  // If CPU is idle, start when the process arrives
        } 
        else 
        {
            ct[i] = ct[i - 1] + bt[i];  // Continue execution
        }
    }

    // Calculate Turnaround Time and Waiting Time
    for (int i = 0; i < n; i++) 
    {
        tat[i] = ct[i] - at[i];  // TAT = CT - AT
        wt[i] = tat[i] - bt[i];  // WT = TAT - BT
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Display process details
    printf("\nProcesses  Arrival Time  Burst Time  Completion Time  Turnaround Time  Waiting Time\n");
    for (int i = 0; i < n; i++) 
    {
        printf("  %d\t\t%d\t    %d\t\t   %d\t\t   %d\t\t  %d\n", processes[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Print average waiting time and turnaround time
    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);

    return 0;
}