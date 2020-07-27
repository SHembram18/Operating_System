/*
 *
 * TO STANDARD OUTPUT DEVICE
 * USING write() SYSTEM CALL
 * File : permissionDemo2.c
 *
 * CHECKING THE FILE SECUIRITY
 *
 */
	#include<fcntl.h>
	int main()
	{
		int fd;
		fd  = open("testPermission2.txt",O_WRONLY | O_CREAT, 0640);
		
		if(fd != -1)
		{
			write(fd, "\nWELCOME", 8);
		}
		close(fd);
		return 0;
	}
		
