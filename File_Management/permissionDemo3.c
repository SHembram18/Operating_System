/*
 *
 * TO STANDARD OUTPUT DEVICE
 * USING write() SYSTEM CALL
 * File : permissionDemo3.c
 *
 * CHECKING THE FILE SECUIRTY PERMISSION  
 *
 */
	#include<fcntl.h>
	int main()
	{
		int fd;
		fd  = open("testPermission3.sh",O_WRONLY | O_CREAT, 0755);
		
		if(fd != -1)
		{
			write(fd, "cal", 3);
		
			
		}
		close(fd);
		return 0;
	}
		
