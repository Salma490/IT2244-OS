#include <stdio.h>
#include <unistd.h>
int main(){
	
	int f=fork();
	printf("\nHello world\n");
	int p=getpid();
		if(f==0){
			printf("\nHello! I'm child process. My pid is %d", f);
		}
		else{
			printf("\nHello! I'm parent process. My pid is %d", p);
		}
	return 0;
}

#include <stdio.h>
#include <unistd.h>
int main(){
	
	int f = fork();
	
	if(f==0){
		printf("I'm Child. ");
		printf("My Parent id %d\n", getppid());
	}
	else{
		int f1=fork();
		if(f1==0){
			printf("I'm Sibling. ");
			printf("My Parent id %d\n", getppid());
		}
		else{
			
			printf("I'm Parent. ");
			printf("My id %d. ", getpid());
			printf("My Parent id %d\n", getppid());
		}
	}
	return 0;
}