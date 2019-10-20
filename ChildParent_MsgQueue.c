#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<unistd.h>

struct message
{
	long id;
	char str[100];
};


int main()
{

	//key_t key = ftok("DAC", 123);
	struct message msg;//message send
	//struct message msg1;//message receive 
	int mqid ;//= msgget(key, IPC_CREAT | 0666);
	
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		printf("failed to create child process\n");
		return -1;
	}
	
	if(pid==0)
	{	
		printf("Child process sending the message with pid == %d ",getpid());
		printf("to parent process with pid == %d \n", getppid());
		key_t key = ftok("DAC", 123);
		mqid = msgget(key, IPC_CREAT | 0666);
		printf("Enter the message that you wants to send\n");
		//scanf("%s", msg.str);
		gets(msg.str); 
		msg.id=1;
		msgsnd(mqid, &msg, sizeof(msg), 0);
		//printf("Message sent is == %s \n",msg.str);
	}
	else
	{	
		key_t key = ftok("DAC", 123);
		mqid = msgget(key, IPC_CREAT | 0666);
		//sleep(5);
		printf("Parent process pid == %d ", getpid());
		printf("Receiving message from child process pid == %d\n",pid);
		msgrcv(mqid, &msg, sizeof(msg), 1, 0);
		printf("Message received is == %s \n",msg.str);
	}

	msgctl(mqid, IPC_RMID, 0);
	return 0;
}
