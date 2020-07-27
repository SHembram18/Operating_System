/*SYSTEM PROGRAM TO READ A FILE CONTENT AND DISPLAY THE CONTENT IN REVERSE ORDER
 *
 * Use of system call
 * open(),
 * close(),
 * read(),
 * write(),
 * lseek()
 *
 * File:- revRead.c
 *
 */
	#include<fcntl.h>
	#include<unistd.h>
	#include<stdlib.h>
	
	int main(void)
	{
		int fd,n;
		char buf;
		 long size=0;

		fd = open("text.txt" , O_RDONLY);//OPENS FILE IN READ_ONLY MODE

		if(fd==-1) //IF ERROR
		{
			perror("text.txt");
			return 1;
		}

		size = lseek(fd, -1, SEEK_END); //MOVE TO ONE BYTE BACK FROM END-OF-FILE
		while(size-- >= 0)
		{
			n = read(fd, &buf, 1);
			write(STDOUT_FILENO , &buf ,1); //STDOUT_FILENO
			lseek(fd, -2, SEEK_CUR);
		}

		close(fd);

		return 0;
	}
	

	
	
