/*
 * USING SYSTEM CALL
 * read(),
 * write(),
 * open(),
 * close(),
 * umask()
 *
 * Modifiying file permission during creation
 * File:- UmaskDemo.c
 */
	#include<fcntl.h>
	#include<stdio.h>
	
	int main()
	{
		int fd;
		mode_t old_mode;
	
		/* get old umask value*, with no umask setting */
		old_mode  = umask(0);
	
		printf("Previous umask value : %o \n", old_mode);

		fd = open("testUmask1.txt", O_WRONLY | O_CREAT, 0764);

		if(fd == -1)
		{
			perror("testUmask1.txt:Create");
			return 1;
		}
		close(fd);
		
		umask(old_mode);
		
		fd = open("testUmask2.txt", O_WRONLY | O_CREAT, 0764);
		
		if(fd == -1)
		{
			perror("testUmask2.txt:Create");
			return 1;
		}
		close(fd);
		return 0;
	}
