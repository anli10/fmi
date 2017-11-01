
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
int main()
{ 
   
   pid_t pid = fork();
   if(pid < 0)
	return errno;
   else if(pid == 0)
      {  
         char *argv[] = { " ls ",NULL};
	 execve("/bin/ls",argv,NULL);
	 perror(NULL);
         
      }
      else {
	wait(NULL);
	printf("Parintele are %d si copilul are %d\n",getpid(),getppid());
         
        }

}	
