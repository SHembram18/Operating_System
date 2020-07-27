/*SYSTEM PROGRAM TO READ A FILE CONTENT AND PRINT ON STDOUT*/
/*
 * READ FROM A FILE FROM 10TH BYTE ONWARDS
 * FILE : lseekDemo1.c
 * 
 * use of system call
 * open(),
 * close(),
 * write(),
 * read(),
 * lseek()
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
		if( lseek( fd , 9l , SEEK_SET) == -1 )
		{
			perror("lseek:readKBDemo.c");
		}
		else
		{
			while( (n=read( fd, buf, 10 )) > 0 )
			{
				write(STDOUT_FILENO, buf, n);
			}
		}
		close(fd);
	
		return 0;	
	}
		
