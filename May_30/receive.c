#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
//structure for message queue
struct mesg_buffer {
	long mesg_type;
	char mesg_text[100];
} message; //tempory variable

int main(){
	key_t key;
	int msgid;
	
	//ftok to generate unique key
	key = ftok("progfile116", 65);
	//msgget creates a message queue and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT);
	//msgrcv to recive message
	msgrcv(msgid, &message, sizeof(message.mesg_text), 1, 0);
	//display the message
	printf("Data recived is : %s\n", message.mesg_text);
	//to destroy the message queue
	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}