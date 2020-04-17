#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
     int N[2];
     int fileSize;
     pid_t pid;
     char text[1024];
     char copy[1024];  
     char* sourceFile = argv[1]; //source file
     char* destFile = argv[2];  //destination file

    pipe(N);
    if (pipe(N)==-1) 
    { 
        fprintf(stderr, "Pipe is failed" ); 
        return 1; 
    }  
    pid = fork();
     if (pid < 0) 
    { 
        fprintf(stderr, "Fork is failed" ); 
        return 1; 
    } 
    if (pid > 0) 
    {
       int temp1;
       ssize_t loc1; 
        close(N[0]);   //close the reading end of pipe
        temp1=open(sourceFile, O_RDONLY);
        loc1=read(temp1, text,sizeof(text));
        write(N[1],text, loc1);
        close(N[1]);   //close the writing end of pipe
    }else if (pid == 0){
    	
        int temp2;
        close(N[1]);   //close the writing end of pipe
        ssize_t loc2;
        loc2 =read(N[0], copy,sizeof(copy));
        close(N[0]);   //close the reading end of pipe
        temp2=open(destFile, O_CREAT | O_WRONLY);
        write(temp2, copy, loc2);
    }
    return 0;
}

