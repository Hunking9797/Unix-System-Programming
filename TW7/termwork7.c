#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define PS "ps -eo pid,ppid,state,tty,command"

int main(){
	pid_t child_pid;
	child_pid = fork();
	if(child_pid < 0){
		printf("fork error\n");
	}
	else if(child_pid == 0)
		exit(0);
	sleep(4);
	system(PS);
	return 0;
}
