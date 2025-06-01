#include <stdio.h>
#include <unistd.h>

int main(){
    printf("\nHello World");
    int f=fork();
    int p=getpid();
    printf("\nThe pid1 is %d",p);
    printf("\nThe pid2 is %d\n",f);
    return 0;
}