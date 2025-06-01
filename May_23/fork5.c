#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    int child1 = fork();

    if (child1 == 0) {
        // Child1 process: Factorial
        printf("\nChild1 -> PID: %d \t PPID: %d\n", getpid(), getppid());

        int fact = 1, i;
        for (i = 1; i <= n; i++) {
            fact *= i;
        }
        printf("\nFactorial of %d is %d\n", n, fact);

        // Child5 of Child1: Fibonacci
        int child5 = fork();
        if (child5 == 0) {
            printf("\nChild5 -> PID: %d \t PPID: %d\n", getpid(), getppid());

            int a = 0, b = 1, fib = 0, j;
            if (n == 0)
                fib = 0;
            else if (n == 1)
                fib = 1;
            else {
                for (j = 2; j <= n; j++) {
                    fib = a + b;
                    a = b;
                    b = fib;
                }
            }
            printf("\nFibonacci term at position %d is %d\n", n, fib);
        } else {
            wait(NULL);  // Wait for child5
        }

    } else {
        // Parent process

        int child2 = fork();
        if (child2 == 0) {
            // Child2: Power of 2
            printf("\nChild2 -> PID: %d \t PPID: %d\n", getpid(), getppid());
            int s = 1, k;
            for (k = 0; k < n; k++) {
                s *= 2;
            }
            printf("\n2 to the power of %d is %d\n", n, s);

        } else {
            int child3 = fork();
            if (child3 == 0) {
                // Child3: Square
                printf("\nChild3 -> PID: %d \t PPID: %d\n", getpid(), getppid());
                int square = n * n;
                printf("\nSquare of %d is %d\n", n, square);

            } else {
                // Parent waits for all its children
                wait(NULL); // Wait for child1
                wait(NULL); // Wait for child2
                wait(NULL); // Wait for child3
            }
        }
    }

    return 0;
}
