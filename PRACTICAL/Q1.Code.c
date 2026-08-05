#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    char command[100];
    pid_t pid;

    printf("=========================================\n");
    printf(" Linux Command Execution using fork()\n");
    printf("=========================================\n");

    printf("Enter a Linux command: ");
    fgets(command, sizeof(command), stdin);

    // Remove newline character
    command[strcspn(command, "\n")] = '\0';

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0)
    {
        // Child Process
        printf("\n--- Child Process ---\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());
        printf("Executing command: %s\n\n", command);

        execlp(command, command, NULL);

        // Executes only if execlp() fails
        printf("Error: Command not found!\n");
        exit(1);
    }
    else
    {
        // Parent Process
        printf("\n--- Parent Process ---\n");
        printf("Parent PID : %d\n", getpid());
        printf("Waiting for child process...\n");

        wait(NULL);

        printf("Child process completed.\n");
    }

    return 0;
}
