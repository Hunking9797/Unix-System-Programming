#define POSIX_SOURCE 
#define POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

static void char_at_time(char *);

int main(void){
	int pid, i;
	for(i=0; i<10; i++){
		pid = fork();
		if(pid < 0){
			printf("fork error\n");
		}
		else if(pid == 0){
			char_at_time("output from child\n");
		}
		else{
			char_at_time("output from parent\n");
		}
	}
	return 0;
}

static void char_at_time(char *str){
	char *ptr; int c;
	setbuf(stdout, NULL);
	for(ptr = str; (c = *ptr++)!= 0; )
		putc(c, stdout);
}

