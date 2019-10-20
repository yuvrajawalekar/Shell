#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main()
{
	key_t key = ftok("/home/dac/CDAC_STUDY11/Priya_OSC/OSC_ASSIGNMENT_6", 1);

	int shared_id = shmget(key, 1024, IPC_CREAT | 0666); 

	char *buf = shmat(shared_id, NULL, 0); // creation of shared varibale....
	
	pid_t pid;
	pid=fork();
	
	while(1)
	{
	
	if(pid==0)
	{
		printf("\nChild process with pid %d and Its Parent process with pid %d \n",getpid(), getppid());	
		printf("\nEnter your name\n");
		
		//__fpurge(stdin); //for bufferfush
		scanf("%s", buf);
		//printf("\nIn child User entered: %s\n", buf);
		buf = shmat(shared_id, NULL, 0);
		printf("\nIn Child Shared memory have: %s\n", buf);
		shmdt(buf);
	}
	else
	{
		sleep(10);
		printf("\nParent process with pid %d and Its child process with pid %d \n",getpid(), pid);	
		printf("\nIn Parent Shared memory have: %s\n", buf);

		printf("\nEnter your name\n");
		
		//__fpurge(stdin); //for bufferfush
		scanf("%s", buf);

		sleep(5);
		shmdt(buf);
	}
	}
	shmctl(shared_id, IPC_RMID, NULL);
	
	return 0;
}

