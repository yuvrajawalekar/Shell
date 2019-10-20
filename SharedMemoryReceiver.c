#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main()
{
	key_t key = ftok("/home/dac/CDAC_STUDY11/Priya_OSC/OSC_ASSIGNMENT_6", 1);

	int shared_id = shmget(key, 1024, IPC_CREAT| 0666); 

	char *buf = shmat(shared_id, NULL, 0); // creation of shared varibale....
	
	
	printf("\nParent, plz enter yourdata\n");
	scanf("%s", buf);
	shmdt(buf);
	//sleep(7);
	buf = shmat(shared_id, NULL, 0);
	sleep(7);
	printf("\nIn Parent Shared memory have: %s\n", buf);
	shmdt(buf);

	//shmctl(shared_id, IPC_RMID, NULL);

	return 0;
}

