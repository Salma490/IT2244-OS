#include <stdio.h>
#include <stdlib.h>	//for exit()
#include <unistd.h>	//for fork(), sleep()
#include <sys/wait.h>	//for wait()

int main(){
	printf("Program started.\n");
	
	printf("Sleeping for 3 seconds...\n");
	sleep(3);	//pause for 3s
	
	printf("Exiting the program.\n");
	exit(0);	//clean exit
}





#include <stdio.h>
#include <stdlib.h>	//for exit()
#include <unistd.h>	//for fork(), sleep()
#include <sys/wait.h>	//for wait()

int main(){
	pid_t pid;
	printf("Parent process started. PID: %d\n", getpid());
	pid = fork();	//create a new child process
	
	if(pid < 0){
		perror("Fork failed");
		exit(1);
	}
	
	if(pid == 0){	//child process
		perror("Child process. PID: %d, sleeping for 2 seconds...\n", getpid());
		sleep(2);
		printf("Child process exiting.\n");
		exit(0);	//child exits with status 0
	}
	else{
		//parent process
		int status;
		printf("Parent waiting for child to finish...\n");
		wait(&status);	//wait for child to finish
		
		if(WIFEXITED(status)){	//WIFEXITED(status) returns true if child terminated normally
			printf("Child exited with status: %d\n", WEXITSTATUS(status));
		}
		else{
			printf("Child did not exit normally.\n");
		}
		printf("Parent process ending.\n");
	}
	return 0;
}




Exercise 01

First child: slept for 1 second.
Second child: slept for 3 seconds.
Parent: Both children have finished.

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





Exercise 02

First child: sleeps for 2 seconds, exits with status 2.
Second child: sleeps for 1 seconds, exits with status 1.
Parent: waits twice, and prints which child (by PID or exit code) finished first and second.

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

    for (int i = 0; i < 2; ++i) {
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










Exercise 03

The parent creates a child process.
The child creates a grandchild process.
The grandchild sleeps 2s and exits with status 2.
The child waits for the grandchild, prints its exit status, then exits with status 55.

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
