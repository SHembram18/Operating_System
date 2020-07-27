/*
 *
 * TO STANDARD OUTPUT DEVICE
 * USING write() SYSTEM CALL
 * File : permissionDemo1.c
 *
 * CHECKING THE FILE SECUIRITY
 *
 */
	#include<fcntl.h>
	int main()
	{
		int fd;
		fd  = open("testPermission1.txt",O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP);
		
		if(fd != -1)
		{
			write(fd, "\nWELCOME", 8);
		}
		close(fd);
		return 0;
	}
		
