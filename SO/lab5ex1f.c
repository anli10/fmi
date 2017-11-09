#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<semaphore.h>
#include<string.h>

char shm_name[] = "myshm";
int shm_fd;
int errno;
char *shm_ptr;
size_t shm_size = 6000;

void forker(int nr_argumente, int nr_procese, char **argumente)
{
int numar;
pid_t pid;

if (nr_procese > 0)
	{
	if ((pid = fork()) < 0)
		{
		perror("fork");
		}
	else if (pid == 0)
		{
		char secventa[400];
		size_t size_secventa;
		numar = atoi(argumente[nr_argumente-nr_procese]);
		snprintf(secventa,400,"%d: %d ",numar,numar);
		size_secventa = strlen(secventa);
		while (numar != 1)
			{
			if (numar%2 == 0) numar/=2;
			else numar = 3*numar+1;
			size_secventa = strlen(secventa);
			snprintf(secventa+size_secventa,400,"%d ",numar);
			}
		snprintf(shm_ptr+(400*nr_procese),400,"%s",secventa);
		printf("\nA terminat copilul %d cu parintele: %d\n",getpid(), getppid());
		}
	else
		{
		forker(nr_argumente, nr_procese-1, argumente);
		wait(NULL);
		}
	}
}

int main(int argc, char **argv)
{
	int numar_procese = argc - 1;
	//printf("Parintele initial: %d\n",getpid());

	shm_fd = shm_open(shm_name, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
        if (shm_fd < 0)
        {
                perror(NULL);
                return errno;
        }
        if (ftruncate(shm_fd, shm_size) == -1)
        {
                perror(NULL);
                shm_unlink(shm_name);
                return errno;
        }
        shm_ptr = mmap(0,shm_size,PROT_WRITE,MAP_SHARED, shm_fd,0);
        if (shm_ptr == MAP_FAILED)
        {
                perror(NULL);
                shm_unlink(shm_name);
                return errno;
         }

	pid_t pid_parinte;
	if ((pid_parinte = fork()) < 0)
		{ perror("fork"); }
	else if (pid_parinte == 0)
		{ forker(argc,numar_procese, argv);}
	else
		{
		wait(NULL);
		int i;
		for (i=argc-1; i>=1; i--)
			{ printf("%s\n",shm_ptr+(400*i));}
		munmap(shm_ptr,shm_size);
		shm_unlink(shm_name);
		}
	return 0;
}
