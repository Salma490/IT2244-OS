#include <stdio.h>
#include <stdlib.h>	//for exit()
#include <unistd.h>	//for fork(), sleep()
#include <sys/wait.h>	//for wait()

int main(){
	pid_t pid;
	printf("Parent process started. PID: %d\n", getpid());
	pid = fork();	//create a new child process
	
	if(pid < 0){
		printf("Fork failed");
		exit(1);
	}
	
	if(pid == 0){	//child process
		printf("Child process. PID: %d, sleeping for 2 seconds...\n", getpid());
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