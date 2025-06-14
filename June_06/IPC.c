#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGSIZE 100

int main() {
    int p[2];
    pid_t pid;
    
    char *name = (char*) malloc(50 * sizeof(char)); 
    char *regno = (char*) malloc(50 * sizeof(char));
    int *age = (int*) malloc(sizeof(int));

    if (pipe(p) < 0) {
        perror("Pipe creation failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) { // Parent process
        close(p[0]); // Close read end

        printf("Enter Name: ");
        scanf("%s", name);

        printf("Enter Reg No: ");
        scanf("%s", regno);

        printf("Enter Age: ");
        scanf("%d", age);

        char buffer[MSGSIZE];
        snprintf(buffer, MSGSIZE, "Name: %s\nReg No: %s\nAge: %d", name, regno, *age);

        write(p[1], buffer, MSGSIZE);
        close(p[1]); // Close write end

        free(name);
        free(regno);
        free(age);
    } else { // Child process
        close(p[1]); // Close write end
        char inbuf[MSGSIZE];

        read(p[0], inbuf, MSGSIZE);
        printf("\nReceived Data:\n%s\n", inbuf);

        close(p[0]); // Close read end
    }

    return 0;
}