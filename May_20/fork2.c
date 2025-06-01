#include <stdio.h>
#include <unistd.h>

int main() {
    int f = fork();            // Create child process
    printf("\nHello world\n"); // Executed by both parent and child

    int p = getpid();          // Get current process ID

    if (f == 0) {
        printf("\nHello! I'm child process. My pid is %d", p);
    } else {
        printf("\nHello! I'm parent process. My pid is %d", p);
    }

    return 0;
}
