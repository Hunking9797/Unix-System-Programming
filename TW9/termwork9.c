#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>

void sys(const char *cmdstr){
	int pid;
	pid = fork();
	if(pid ==0){
		execl("/bin/bash","bash","-c",cmdstr,NULL);
	}
	else{
		waitpid(pid,NULL,0);
	}
}

int main(int argc, char *argv[]){
	int i;
	for(i =1; i<argc; i++){
		sys(argv[i]);
		printf("\n");
	}
	exit(0);
}

