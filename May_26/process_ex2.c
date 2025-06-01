//Exercise 02

//First child: sleeps for 2 seconds, exits with status 2.
//Second child: sleeps for 1 seconds, exits with status 1.
//Parent: waits twice, and prints which child (by PID or exit code) finished first and second.

#include <stdio.h>
#include <stdlib.h>     // for exit()
#include <unistd.h>     // for fork(), sleep(), getpid()
#include <sys/wait.h>   // for wait()

int main() {
    pid_t child1, child2;
    int status;
    
    printf("Parent process started. PID: %d\n", getpid());

    child1 = fork();
    if (child1 < 0) {
        perror("Fork for child1 failed");
        exit(1);
    }

    if (child1 == 0) {
        // First child
        printf("First child (PID: %d) sleeping for 2 seconds...\n", getpid());
        sleep(2);
        printf("First child (PID: %d) exiting with status 2.\n", getpid());
        exit(2);
    }

    child2 = fork();
    if (child2 < 0) {
        perror("Fork for child2 failed");
        exit(1);
    }

    if (child2 == 0) {
        // Second child
        printf("Second child (PID: %d) sleeping for 1 second...\n", getpid());
        sleep(1);
        printf("Second child (PID: %d) exiting with status 1.\n", getpid());
        exit(1);
    }

    // Parent process
    printf("Parent waiting for children to finish...\n");

    int i;
    for (i = 0; i < 2; ++i) {
        pid_t finished_pid = wait(&status);
        if (WIFEXITED(status)) {
            printf("Child with PID %d exited with status %d\n", finished_pid, WEXITSTATUS(status));
        } else {
            printf("Child with PID %d did not exit normally.\n", finished_pid);
        }
    }

    printf("Parent process ending.\n");
    return 0;
}