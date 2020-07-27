/*
 *
 * TO STANDARD OUTPUT DEVICE
 * USING write() SYSTEM CALL
 * File : permissionDemo.c
 *
 *
 *CHECKING THE FILE SECUIRITY PERMISSION
 *
 */
	#include<fcntl.h>
	int main()
	{
		int fd;
		fd  = open("testPermission.txt",O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
		
		if(fd != -1)
		{
			write(fd, "\nWELCOME", 8);
		}
		close(fd);
		return 0;
	}
		
