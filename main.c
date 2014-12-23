#include <stdio.h>
#include <fcntl.h>

#define DEV_NAME	"/dev/demo_dev"

int main()
{	
	int fd ;
	char data;
	fd = open(DEV_NAME,O_RDWR);
	if(fd<0)
	{
		printf("Open %s failed \n" ,DEV_NAME );	
		return -1 ;
	}
	read(fd , &data ,1);
	close(fd);
}
