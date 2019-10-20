#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
	long id;
	char str[100];
};


int main()
{

	key_t key = ftok("DAC", 123);
	struct message msg;//message send
	struct message msg1;//message receive 
	int mqid = msgget(key, IPC_CREAT | 0666);

	printf("Enter the message that you wants to send\n");
	scanf("%s", msg.str);
	msg.id=1;
	msgsnd(mqid, &msg, sizeof(msg), 0);

	
	msgrcv(mqid, &msg1, sizeof(msg1), 7, 0);
	printf("Message received from another process  : %s\n", msg1.str);

	return 0;
}
