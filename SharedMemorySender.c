#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main()
{
	key_t key = ftok("/home/dac/CDAC_STUDY11/Priya_OSC/OSC_ASSIGNMENT_6", 1);

	int shared_id = shmget(key, 1024, IPC_CREAT | 0666); 

	char *buf = shmat(shared_id, NULL, 0); // creation of shared varibale....
	
	printf("\nChild, plz enter your data\n");
	scanf("%s", buf);

	sleep(7);
	printf("\nIn Child Shared memory have: %s\n", buf);
	shmdt(buf);

	shmctl(shared_id, IPC_RMID, NULL);

	return 0;
}

