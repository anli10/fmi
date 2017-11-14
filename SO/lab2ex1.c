#include<sys/stat.h>
#include<unistd.h>
int main(int argc, char const *argv[])
{
	write(1,"hello world\n",12);
	return 0;
}