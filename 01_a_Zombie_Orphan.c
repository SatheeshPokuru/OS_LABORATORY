#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <stdlib.h>
void normal()
{
    pid_t id = fork();
    if(id>0)
    {
        printf("Parent Process %d\n",getpid());
        exit(0);
    }
    else if(id==0)
    {
        printf("Child Process : %d,Parent ID : %d\n",getpid(),getppid());
    }
    else
        printf("Fork Failed\n");
}

void zombie()
{ 
    pid_t id = fork();
    if(id>0)
    {
        sleep(1);
        printf("Parent Process Terminating %d\n",getpid());
    }
    else if(id==0)
    {
        printf("Child Process Terminating : %d,Parent ID : %d\n",getpid(),getppid());
        exit(0);
    }
    else
        printf("Fork Failed\n");
}

void orphan()
{ 
    pid_t id = fork();
    if(id>0)
    {
        printf("Parent Process Terminating %d\n",getpid());
        exit(0);
    }
    else if(id==0)
    {
        sleep(1);
        printf("Child Process Terminating : %d\n",getpid());
    }


    else
        printf("Fork Failed\n");
    
}


void fn() {
    //do nothing
}

int main()
{
    // printf("Normal !!!");
    // normal();
    
    // printf("Zombieeee !!!");
    // zombie();

    printf("Orphan !!!");
    orphan();
}