#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
int main(int argc, char * argv[]){
    int fd,size;
    char buff[255];
    struct flock fvar;
    if(argc==1){
        printf("Usage: %s filename \n",argv[0]);
        return -1;
    }
    if((fd=open(argv[1],O_RDWR))==-1){
        perror("open");
        return -1;
    }
    fvar.l_type=F_WRLCK;
    fvar.l_whence=SEEK_END;
    fvar.l_start=SEEK_END-100;
    fvar.l_len=100;
    printf("Press Enter to set lock:\n");
    getchar();
    printf("Trying to lock the file\n");
    if((fcntl(fd,F_SETLK,&fvar))==-1){
        fcntl(fd,F_GETLK,&fvar);
        printf("File locked by:(pid) %d\n",fvar.l_pid);
        return -1;
    }
    printf("Locked!\n");
    if((size=lseek(fd,SEEK_END-50,SEEK_END))==-1){
            perror("lseek");
            exit(0);
    }
    printf("Data read from file:\n");
    read(fd,&buff,size);
    puts(buff);
    printf("\n Press enter to release lock\n");
    getchar();
    fvar.l_type=F_UNLCK;
    fvar.l_whence=SEEK_SET;
    fvar.l_start=0;
    fvar.l_len=0;
    if((fcntl(fd,F_UNLCK,&fvar))==-1){
        perror("fcntl");
        exit(0);
    }
    printf("Unlocked");
    close(fd);
    return 0;


}
		
