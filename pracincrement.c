#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()                                                                                                                                                              
{                                                                                                                                                                       
        int x=5;
        pid_t p;                                                                                                                                                        
        p=fork();                                                                                                                                                       
        if(p<0)
        {                                                                                                                                                               
                perror("fork fail");
                exit(1);
        }                                                                                                                                                               
        if(p==0)
        {
                printf("child  pid=%d\n",getpid());
                printf("incremented value:%d\n",x++);
        }
        else
        {                                                                                                                                                               
                printf("parent child=%d\n",getpid());
                printf("decremented value=%d\n",x--);
        }                                                                                                                                                               
}
