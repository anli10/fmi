#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{ 
   if(argc<=1){
	printf("numar incorect de argumente");
	exit(1);
	}
	  	
   
   for(int i=1;i<=argc;i++){
	pid_t pid=fork();
	if(pid < 0)
		return errno;
	
	else if(pid == 0){  	
	        int n = atoi(argv[i]);
		printf("%d: ",n);
	        while(n != 1){

	   		printf("%d ",n);
	                if(n%2 == 0)
				n = n/2;
			else
				n = n*3 + 1;             
		}
       		printf("\nChild %d finished si are parintele %d\n",getpid(),getppid());
		exit(0);
   	}
	else{
		
	}
  }
  int status; 
  for(int i=1;i<=argc;i++)
	wait(&status);
}
//  int status; 
//  int pid2;
//  while (argc>1){
//	pid2=wait(&status);
//	printf("\nChild %d finished si are parintele %d\n",getppid(),getpid());
//	argc--;
//}
		
