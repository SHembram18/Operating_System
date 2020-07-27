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
	#include<unistd.h>
	int main()
	{
		int fd,n;
		char buf[10];

		fd = open("readDemo2.c",O_RDONLY);
		if(fd == -1)
		{
			perror("readDemo2.c");
			return 1;
		}
		
		while(  (n=read(fd, buf, 10)) > 0 )
		{
			write(STDOUT_FILENO, buf, n);
		}

		close(fd);
		return 0;				 
	} 
