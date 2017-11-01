#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{ 
   const int SIZE = 2048;
   if(argc<=1){
	printf("numar incorect de argumente");
	exit(1);
	}
   const char *name = "Ana";	  	
   int shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
   ftruncate(shm_fd, SIZE);
   void *ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	   


   for(int i=1;i<=argc;i++){
	pid_t pid=fork();
	if(pid < 0)
		return errno;
	
	else if(pid == 0){  
		int n = atoi(argv[i]); 
		sprintf(ptr, "%d", n);	     		 			ptr += sizeof(n);

	        
		printf("%d: ",n);
	        while(n != 1){

	                if(n%2 == 0)
				n = n/2;
			else
				n = n*3 + 1; 
			sprintf(ptr, "%d", n);	     		 			ptr += sizeof(n);            
		}
       		 sprintf(ptr,"0");   
     		 ptr += sizeof(n);
		exit(0);
   	}
	else{
	 //wait(); 
     	 while (atoi((char *)ptr) != 0)   
      {
         printf("%s", (char *)ptr);
         ptr += sizeof(int);
         if (atoi((char *)ptr) != 0)
            printf(", ");
	}
      printf("\n");
     // shm_unlink(name);
  
  int status; 
  for(int i=1;i<=argc;i++)
	wait(&status);
}}}
//  int status; 
//  int pid2;
//  while (argc>1){
//	pid2=wait(&status);
//	printf("\nChild %d finished si are parintele %d\n",getppid(),getpid());
//	argc--;
//}
		
