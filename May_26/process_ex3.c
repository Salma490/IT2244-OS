//Exercise 03

//The parent creates a child process.
//The child creates a grandchild process.
//The grandchild sleeps 2s and exits with status 2.
//The child waits for the grandchild, prints its exit status, then exits with status 55.

#include <stdio.h>
#include <stdlib.h>     // for exit()
#include <unistd.h>     // for fork(), sleep(), getpid()
#include <sys/wait.h>   // for wait()

int main() {
    pid_t child_pid, grandchild_pid;
    int status;

    printf("Parent process started. PID: %d\n", getpid());

    child_pid = fork();
    if (child_pid < 0) {
        perror("Fork for child failed");
        exit(1);
    }

    if (child_pid == 0) {
        // Child process
        printf("Child process started. PID: %d, Parent PID: %d\n", getpid(), getppid());

        grandchild_pid = fork();
        if (grandchild_pid < 0) {
            perror("Fork for grandchild failed");
            exit(1);
        }

        if (grandchild_pid == 0) {
            // Grandchild process
            printf("Grandchild process started. PID: %d, Parent PID: %d\n", getpid(), getppid());
            sleep(2);
            printf("Grandchild (PID: %d) exiting with status 2.\n", getpid());
            exit(2);
        } else {
            // Child waits for grandchild
            wait(&status);
            if (WIFEXITED(status)) {
                printf("Child (PID: %d) detected grandchild (PID: %d) exited with status %d\n",
                       getpid(), grandchild_pid, WEXITSTATUS(status));
            } else {
                printf("Grandchild did not exit normally.\n");
            }

            printf("Child (PID: %d) exiting with status 55.\n", getpid());
            exit(55);
        }
    } else {
        // Parent process
        wait(&status); // Wait for child
        if (WIFEXITED(status)) {
            printf("Parent (PID: %d) detected child (PID: %d) exited with status %d\n",
                   getpid(), child_pid, WEXITSTATUS(status));
        } else {
            printf("Child did not exit normally.\n");
        }
        printf("Parent process ending.\n");
    }

    return 0;
}