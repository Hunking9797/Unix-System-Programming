#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

// Driver Code
int main(int argc, char* argv[])
{
	if(argc==3){
        printf("Hard Link Created!\n");
        return link(argv[1],argv[2]);
    }else if(argc==4){
        if(strcmp(argv[1],"-s")==0){
            printf("Symbolic link created!\n");
            return symlink(argv[2],argv[3]);
        }else{
            printf("Option must be -s for symbolic link\n");
        }
    }else{
        printf("Invalid number of arguments");
    }

	return 0;
}
 
