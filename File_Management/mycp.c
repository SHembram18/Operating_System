/*SYSTEM PROGRAM TO READ A FILE CONTENT AND COPY THE CONTENT IN ANOTHER FILE USING COMMAND LINE ARGUMENT*/

/*
 * Use of system call
 * open(),
 * close(),
 * write(),
 * read()
 *
 * File:- mycp.c
 *
 * TO RUN THIS FILE:- ./mycp source_file destination_file
 *
 */
	#include<fcntl.h>
	#include<unistd.h>

	int main(int argc, char **argv)
	{
		int fd1,fd2,n;
		char buf;
		
		if(argc!=3)
		{
			write(STDERR_FILENO, "Invalid no. of arguments...\n",28);
			return 1;	
		}
		fd1 = open(argv[1],O_RDONLY); //OPENS FILE IN WRITE-ONLY-MODE
		if(fd1==-1)
		{
			perror(argv[1]);
			return 1;
		}
		fd2 = open(argv[2],O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP );//OPENS FILE IN WRITE-ONLY-MODE
		if(fd2 == -1) //IF ERROR
		{
			perror(argv[2]);
			return 1;
		}
		while((n=read(fd1,&buf,1)) > 0)
		{
			write(fd2,&buf,n); // STDOUT_FILENO
		}
		close(fd1);
		close(fd2);
	
		return 0;
	}
