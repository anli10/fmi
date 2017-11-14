#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
int main(int argc, char const *argv[])
{
	char c;
	int in=open(argv[1],O_RDONLY);
	if(in<0){
		printf("Input nu a fost deschis\n");
		return -1;
	}
	int out=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC);\
	while(read(in,&c,1)!=0){
		write(out,&c,1);
	}
	close(in);
	close(out);
	return 0;
}