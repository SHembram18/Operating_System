/*
 * A SIMPLE PROGRAM TO OUTPUT SOMETHING
 * TO STANDARD OUTPUT DEVICE
 * USING write() SYSTEM CALL
 * File: fileDemo2.c
 */
	#include <fcntl.h>
	

	int main()
	{
		int fd;
		fd = open("testWrite.txt",O_WRONLY | O_CREAT); 
		if( fd != -1)
		{
			write(fd,"Hello",5);
		}
		
		close(fd);
		return 0;
 
	}
