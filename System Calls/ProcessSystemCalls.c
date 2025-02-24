#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
    pid_t pid;    
    pid = fork(); // Create a child process
    
    if (pid < 0) 
    {
        perror("Fork failed");
        exit(1);
    }
    
    if (pid == 0) 
    {  // Child process
        printf("Child process (PID: %d) executing ls command...\n", getpid());
        execlp("ls", "ls", NULL); // Execute ls command
        perror("Exec failed"); // If exec fails
        exit(1);
    } 
    else 
    {  // Parent process
        int status;
        printf("Parent process (PID: %d) waiting for child...\n", getpid());
        waitpid(pid, &status, 0); // Wait for child to finish
        if (WIFEXITED(status)) 
        {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}