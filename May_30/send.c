#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#define MAX 10 //Max size for message queue

//structure for message queue
struct mesg_buffer { //tempory storage box
	long mesg_type;
	char mesg_text[100];
} message; //tempory variable

int main(){
	int msgid;
	//fork to generate unique key
	key_t key;
	key = ftok("progfile116", 65);
	//msgget reates a message queue and returns identifier
	
	msgid = msgget(key, 0666 | IPC_CREAT);
	message.mesg_type = 1;
	printf("Write Data : ");
	fgets(message.mesg_text, MAX, stdin);
	//mgsnd to send messege
	msgsnd(msgid, &message, sizeof(message.mesg_text), 0);
	//display the message
	printf("Data send is : %s\n", message.mesg_text);
	return 0;
}