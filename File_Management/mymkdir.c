/*
 * TO CREATE A NEW DIRECTORY 
 * FILE:- mymkdir.c
 * author:- Santosh Hembram
 *
 */
	#include<unistd.h>
	int main(int argc,char **argv)
	{
		if(argc!=2)
		{
			write(STDERR_FILENO,"Invalid no. of argument(s) !!!\n",31);
			return 1;
		}
		
		if( mkdir(argv[1],0751)== -1)
		{
			perror(argv[1]);
			return 2;
		}
		return 0;
		
	}
