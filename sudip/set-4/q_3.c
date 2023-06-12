#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUFFER_SIZE 100

int isPal(const char *str){
    int len = strlen(str);
    int i,j;

    for(int i=0,j=len-1;i<j;i++,j--){
        if(str[i]!=str[j])
        return 0;
    }
    return 1;
}

int main()
{
    int fd[2],fd2[2];

    char buffer[BUFFER_SIZE]; 
    pipe(fd);
    pipe(fd2);

    int pid = fork(); 


     if (pid == 0)
    {                 
        close(fd[1]);  //write
        close(fd2[0]); // read
        while (1)
        {
            fflush(stdout);
            read(fd[0],buffer,BUFFER_SIZE);
            printf("child recieved....pid(%d) ppid(%d) : %s\n",getpid(),getppid(),buffer);
            if(strcmp(buffer,"quit")==0){
                break;
            
            }
            fflush(stdout);
            if(isPal(buffer)){
                write(fd2[1],"YES\0",4);
            }else{
                write(fd2[1],"NO\0",3);
            }
        } 
        return 0;
    }
    else
    {                
        close(fd[0]);  //read
        close(fd2[1]); //write
        while (1)
        {
            printf("Enter a string: ");
            fflush(stdin);
            fgets(buffer, BUFFER_SIZE, stdin);    
            buffer[strcspn(buffer, "\n")] = '\0'; 
            fflush(stdout);
            write(fd[1], buffer, strlen(buffer) + 1); 
            if (strcmp(buffer, "quit") == 0)  
                break; 
            fflush(stdout);   
            read(fd2[0], buffer, BUFFER_SIZE);         
            printf("Parent recieved...pid(%d) ppid(%d) : %s\n",getpid(),getppid(), buffer);                   
        }
        wait(NULL);
    }
        return 0;
}