/* SYSTEM PROGRAM TO READ FROM STANDARD INPUT (KB) AND PRINT ON STDOUT */
/* 
 * Use of sysytem calls
 * open(),
 * close(),
 * read() and
 * write()
 * Program: readKBDemo.c
 *
 *
 *  TO RUN THIS FILE IN COMMAND PROMPT:-  ./readKBDemo then press [ENTER] then enter the input it will show you the output on command prompt.
 *
 */

	#include<fcntl.h>
	#include<stdlib.h>
	#include<unistd.h>

	int main()
	{
		int n;
		char buf;

		while( (n=read(STDIN_FILENO , &buf,1)) > 0 )
		{
			write(STDOUT_FILENO, &buf , n); //STDOUT_FILENO
		}
		return 0;
	}
