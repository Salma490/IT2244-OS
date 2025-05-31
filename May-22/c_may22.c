#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();  // Create a child process    

    if (pid == 0) {
        // Child process: Print numbers 1 to 5
        for (int i = 1; i <= 5; i++) {
            printf("Child Process: %d\n", i);
        }
    } else {
        // Parent process: Calculate the sum of numbers from 6 to 10
        int sum = 0;
        for (int i = 6; i <= 10; i++) {
            sum += i;
        }
        printf("Parent Process: Sum of numbers from 6 to 10 is %d\n", sum);

    }

    return 0;
}
