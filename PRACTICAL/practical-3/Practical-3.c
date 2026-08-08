#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("Parent Process Started\n");
    printf("Parent PID : %d\n", getpid());

    pid = fork();

    if (pid < 0) {
        printf("Fork Failed!\n");
        return 1;
    }

    if (pid == 0) {
        // Child Process
        printf("\n--- Child Process ---\n");
        printf("Child PID  : %d\n", getpid());
        printf("Parent PID : %d\n", getppid());

        printf("Child is running...\n");
        sleep(5);

        printf("Child exiting...\n");
        exit(0);
    }
    else {
        // Parent Process
        printf("\n--- Parent Process ---\n");
        printf("Parent PID : %d\n", getpid());
        printf("Child PID  : %d\n", pid);

        printf("Parent waiting for child...\n");
        wait(NULL);

        printf("Child has terminated.\n");
        printf("Parent exiting...\n");
    }

    return 0;
}
