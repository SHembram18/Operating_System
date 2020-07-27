/*
 *
 *  
 *
 *  READING FROM A FILE & DISPLAYING ON STANDARD OUTPUT DEVICE
 *
 *
 *
 * */
	#include<fcntl.h>
	int main()
	{
		int fd,n;
		char buf[10];

		fd = open("readDemo1.c",O_RDONLY);
		if(fd == -1)
		{
			perror("readDemo1.c");
			return 1;
		}
		
		while(  (n=read(fd, buf, 10)) > 0 )
		{
			write(1, buf, n);
		}

		close(fd);
		return 0;				 
	} 
