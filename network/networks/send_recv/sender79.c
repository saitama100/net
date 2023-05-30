#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

struct message{
	long mtype;
	char mtext[15];
	};
int main(){
	int msgid, len;
	key_t key;
	struct message msg;
	key = 131;
	msgid = msgget(key, IPC_CREAT|0666);
	printf("\nq = %d", msgid);
	strcpy(msg.mtext, "Hello World\n");
	msg.mtype = 1;
	len = strlen(msg.mtext);
	if(msgsnd(msgid, &msg, len, 0) == -1)
	{
		printf("Error\n");
		exit(1);
	}
	return 0;
}
