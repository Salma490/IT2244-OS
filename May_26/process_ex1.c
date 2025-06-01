//Exercise 01

//First child: slept for 1 second.
//Second child: slept for 3 seconds.
//Parent: Both children have finished.

#include <stdio.h>
#include <stdlib.h>     // for exit()
#include <unistd.h>     // for fork(), sleep()
#include <sys/wait.h>   // for wait()

int main() {
    pid_t pid1, pid2;
    int status;

    printf("Parent process started. PID: %d\n", getpid());

    // First child
    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed for first child");
        exit(1);
    }
    if (pid1 == 0) {
        // First child process
        printf("First child. PID: %d, sleeping for 1 second...\n", getpid());
        sleep(1);
        printf("First child done.\n");
        exit(0);
    }

    // Second child
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed for second child");
        exit(1);
    }
    if (pid2 == 0) {
        // Second child process
        printf("Second child. PID: %d, sleeping for 3 seconds...\n", getpid());
        sleep(3);
        printf("Second child done.\n");
        exit(0);
    }

    // Parent process
    // Wait for both children
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);

    printf("Parent: Both children have finished.\n");

    return 0;
}