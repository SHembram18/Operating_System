/*
 * A SIMPLE PROGRAM TO OUTPUT SOMETHING
 * TO STANDARD OUTPUT DEVICE
 * USING write() SYSTEM CALL
 * File: fileDemo3.c
 */
	#include <fcntl.h>
	

	int main()
	{
		int fd;
		fd = open("testWrite.txt",O_WRONLY | O_APPEND); 
		if( fd != -1)
		{
			write(fd,"\nWelcome",8);
		}
		
		close(fd);
		return 0;
 
	}
