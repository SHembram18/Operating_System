/*
 * SYSTEM PROGRAM TO READ A FILE CONTENT AND PRINT ON STDOUT
 *
 * Use of system call
 * open(),
 * close(),
 * read(),
 * write(),
 * lseek()
 *
 * File: lseekDemo.c
 */
	
	#include<fcntl.h>
	#include<unistd.h>

	int main(void)
	{
		int fd,n;
		char buf[10];

		fd =  open("readKBDemo.c",O_RDONLY);
		if(fd == -1)
		{
			perror("readKBDemo.c");
			return 1;
		}
		if( lseek(fd, -2, SEEK_SET) == -1 )
		{
			perror("lseek:readKBDemo.c");
		}
		else
		{
			write(STDOUT_FILENO,"Success",7);
		}
		close(fd);
	
		return 0;
	 }	
		
