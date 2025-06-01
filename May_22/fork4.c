#include <stdio.h>
#include <unistd.h>

int main() {
    int f = fork();

    if (f == 0) {
        printf("I'm the child!\n");
        int csum = 0;
        int i; // declare loop variable outside
        for (i = 1; i <= 5; i++) {
            printf("%d ", i);
            csum += i;
        }
        printf("\nSummation of child process: %d\n", csum);
    } else {
        printf("I'm the parent!\n");
        int psum = 0;
        int i; // declare loop variable outside
        for (i = 6; i <= 10; i++) {
            printf("%d ", i);
            psum += i;
        }
        printf("\nSummation of parent process: %d\n", psum);
    }

    return 0;
}
