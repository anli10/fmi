#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{ 
   if(argc!=2){
	printf("numar incorect de argumente");
	exit(1);
	}

   pid_t pid = fork();
   if(pid < 0)
	return errno;
   else if(pid == 0)
      {  
	
        int n = atoi(argv[1]);
	printf("%d: ",n);
        while(n != 1)
            {
   		printf("%d ",n);
                if(n%2 == 0)
			n = n/2;
		else
			n = n*3 + 1;

             }
         printf("\nChild %d finished",getppid());
      }
      else 
 	{ 
 	 //printf("Am intrat in procesul parinte");
          wait(NULL);
	  
        }

}		
