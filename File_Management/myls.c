/*
 * A SYSTEM PROGRAM TO RAED A DIRECTORY USING COMMAND LINE ARGUMENT
 *
 * File:- myls.c
 *
 * Using System calls
 * readdir(),
 * opendir(),
 * closedir()
 *
 */
	#include<dirent.h>
	#include<stdio.h>
	
	int main(int argc,char **argv)
	{
		DIR *dirPointer;
		struct dirent *dirEntry;	
		
		if(argc == 1)
	 	{
			fprintf(stderr,"Insufficient no. of Arguments!!!");
			return 1;
		}

		if( ( dirPointer = opendir(argv[1]) ) == NULL )
		{
			perror(argv[1]);
			return 1;
		}
		
		while( ( dirEntry = readdir(dirPointer) ) != NULL )
		{
			fprintf( stdout,"%10d %s\n",dirEntry->d_ino , dirEntry->d_name );
		}

		closedir(dirPointer);
		return 0;
		
	}
