#include<stdio.h>
#include<stdlib.h>
#define ArrivalTime 0

int BurstTime[5];
int WaitingTime[5];
int CompletionTime[5];
int TurnAroundTime[5];

int N;

void calcWaitingTime()
{
	int i;
	
	for(i = 0; i < N; i++)
	{
		if(i == 0)
		{
			WaitingTime[i] = 0;
		}
		else
		{
			WaitingTime[i] = WaitingTime[i - 1] + BurstTime[i - 1];
		}
	}
	printf("Waiting Time: \n");
	for(i = 0; i < N; i++)
	{
		printf("%d\t", WaitingTime[i]);
	}
	printf("\n");
}

void calcCompletionTime()
{
	int i;
	
	for(i = 0; i < N; i++)
	{
		CompletionTime[i] = WaitingTime[i] + BurstTime[i];
	}
	printf("Completion Time: \n");
	for(i = 0; i < N; i++)
	{
		printf("%d\t", CompletionTime[i]);
	}
	printf("\n");
}

void calcTurnAroundTime()
{
	int i;
	for(i = 0; i < N; i++)
	{
		TurnAroundTime[i] = BurstTime[i] + WaitingTime[i];
	}
	printf("Turn Around Time: \n");
	for(i = 0; i < N; i++)
	{
		printf("%d\t", TurnAroundTime[i]);
	}
	printf("\n");
}

int main()
{
	int i;
	
	printf("Enter No of Processes: ");
	scanf("%d", &N);
	
	for(i = 0; i < N; i++)
	{
		printf("Enter Burst Time: ");
		scanf("%d", &BurstTime[i]);	
	}
	
	calcWaitingTime();
	calcCompletionTime();
	calcTurnAroundTime();
}
