 /*
 * A SYSTEM PROGRAM TO GET THE CURRENT WORKING DIRECTORY IN COMMAND LINE ARGUMENT
 *
 * Using system call
 * getcwd()
 *
 *  File:- mypwd.c
 */
	#include<stdio.h>
	
	#define PATH_LENGTH 200

	int main(int argc, char **argv)
	{
		char cwd[PATH_LENGTH+1];
	
	if( getcwd(cwd, PATH_LENGTH) == NULL )
	{
		fprintf(stderr,"System error...\n");
		return 1;
	}
	fprintf(stdout, "\ncwd: %s\n", cwd);
	return 0;
}
