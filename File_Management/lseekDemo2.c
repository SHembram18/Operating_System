/*SYSYTEM PROGRAM TO READ A FILE CONTENT AND PRINT ON STDOUT*/
/*
 * READ FROM A FILE FROM 10TH BYTE ONWARDS
 * FILE : lseekDemo2.c
 *
 * use of sysytem call
 * open(),
 * close(),
 * write(),
 * read(),
 * lseek
 *
 *  HERE BUF SIZE IS PREVIOUSLY DEFINED
 */
	
	#include<fcntl.h>
	#include<unistd.h>

	#define BUFSIZE 512

	int main(void)
	{
		int fd,n;
		char buf[BUFSIZE];

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
			while( (n=read( fd, buf, BUFSIZE )) > 0 )
			{
				write(STDOUT_FILENO, buf, n);
			}
		}
		close(fd);
	
		return 0;	
	}
		
