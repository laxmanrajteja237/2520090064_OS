#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int i;
    pid_t pid, child_pid;

    printf("Parent Process: PID = %d\n", getpid());

    // Create 3 child processes
    for (i = 0; i < 3; i++)
    {
        pid = fork();

        if (pid < 0)
        {
            perror("fork failed");
            exit(1);
        }

        if (pid == 0)
        {
            printf("Child %d: PID = %d, PPID = %d\n",
                   i + 1, getpid(), getppid());

            sleep(i + 1);

            printf("Child %d completed\n", i + 1);
            exit(0);
        }
    }

    // Parent waits for all children
    for (i = 0; i < 3; i++)
    {
        child_pid = wait(NULL);
        printf("Parent: Child with PID %d completed\n", child_pid);
    }

    printf("Parent process completed.\n");

    return 0;
}
