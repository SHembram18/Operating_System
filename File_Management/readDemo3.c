/*
 *
 *  
 *
 *  READING FROM A FILE & WRITING TO A DISK FILE
 *
 *
 *
 * */
	#include<fcntl.h>
	int main()
	{
		int fd1,fd2,n;
		char buf[1024];

		fd1 = open("readDemo3.c",O_RDONLY);
		if(fd1 == -1)
		{
			perror("readDemo3.c");
			return 1;
		}
		fd2 = open("readDemo3.c.backup", O_WRONLY | O_CREAT);
		if(fd2 == -1)
		{
			perror("readDemo3.c.backup");
			return 1;
		}
		
		while(  (n=read(fd1, buf, 1024)) > 0 )
		{
			write(fd2, buf, n); //STDERR_FILENO,STDIN_FILENO,STDOUT_FILENO
		}

		close(fd1);
		close(fd2);
		
		return 0;				 
	} 
