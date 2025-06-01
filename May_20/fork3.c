#include <stdio.h>
#include <unistd.h>

int main(){
int f=fork();

if(f==0){
	 printf("I am child. My parent id is %d. My id is %d\n", getppid(), getpid());
}
else{
	int f1=fork();
	if(f1==0){
	printf("I am sibling. My parent id is %d. My id is %d\n", getppid(), getpid());
	}
	else{
	printf("I am parent. My parent id is %d. My id is %d\n", getppid(), getpid());
	}
}

return 0;
}