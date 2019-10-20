#include<stdio.h>
#include <sys/types.h> //  get a System V message queue identifier
#include <sys/ipc.h>
#include <sys/msg.h>// for msgget
#include<unistd.h>

struct message
{
	long id;
	char str[100];
};


int main()
{

	key_t key = ftok("DAC", 123);
	struct message msg;//message receive 
	struct message msg1;//message send
	int mqid = msgget(key, IPC_CREAT | 0666);
	

	msgrcv(mqid, &msg, sizeof(msg), 1, 0);
	printf("Message received from second process : %s\n", msg.str);

	printf("Enter the message that you wants to send\n");
	scanf("%s", msg1.str);
	msg1.id=7;
	msgsnd(mqid, &msg1, sizeof(msg1),0);

	
	msgctl(mqid, IPC_RMID, 0);
	return 0;
}
