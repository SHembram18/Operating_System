/*
 * A SYSTEM PROGRAM THAT CHANGES THE CURRENT WORKING DIRECTORY
 *
 * File:- mychdir.c
 *
 * Using system call
 * chdir()
 *
 */
	#include<stdio.h>
	
	#define PATH_LENGTH 200
	int main(int argc, char **argv)
	{
		char olddir[PATH_LENGTH+1], newdir[PATH_LENGTH+1];
		
		getcwd(olddir, PATH_LENGTH);
		fprintf(stdout, "\nolddir: %s\n", olddir);

		if(argc == 1)
		{	
			fprintf(stderr,"\nInsufficient no. of aerguments !!!");
			return 1;
		}
		else if(argc == 2)
		{
			if( chdir(argv[1]) == -1 )
			{
				perror(argv[1]);
				return 1;
			}
			getcwd(newdir, PATH_LENGTH);
			fprintf(stdout, "\npwd: %s\n", newdir);
		}
		else
		{
			fprintf(stderr,"\nInvalid Arguments....\n");
			return 1;
		}
		return 0;
	}
		
		






















	
