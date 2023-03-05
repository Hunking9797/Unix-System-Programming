#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int pid;
	pid = fork();
	if(pid == 0){
		pid = fork();
		if(pid == 0){
			sleep(1);
			printf("second child: My Parent PID is %d\n", getppid());
		}
	}
	else{
		wait(NULL);
		sleep(1);
		system("ps -o pid,ppid,state,tty,command");
	}
	return 0;
}

