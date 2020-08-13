*
 * PROGRAM : TO REMOVE AN EMPTY DIRECTORY
 * FILE    : myrmdir.c
 * AUTHOR  : Santosh Hembram
 *
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
		if( rmdir(argv[1]) == -1)
		{
			perror(argv[1]);
			return 2;
		}
		
		return 0;
	}
