/*
 *
 * 	PROGRAM : TO DETERMINE THE FILE TYPE USING S_ISxxx MACRO
 * 	FILE    :chkFileType.c
 * 	AUTHOR  : SANTOSH HEMBRAM
 *
 */

	#include<stdio.h>
	#include<sys/stat.h>

	int main(int argc ,char **argv)
	{
		struct stat statBuf;

		if(argc != 2)
		{
			fprintf(stderr, "Inavalid Argument(s) !!!");
			return 1;
		}
		if( lstat(argv[1], &statBuf) < 0 )
		{
			perror("lstat");
			return 2;
		}

		fprintf(stdout, "%s", argv[1]);
		if(S_ISREG(statBuf.st_mode))
			fprintf(stdout, "is a regular File.");

		if(S_ISDIR(statBuf.st_mode))
			fprintf(stdout, "is a Directory.");
		
		if(S_ISBLK(statBuf.st_mode))
			fprintf(stdout, "is a Block device.");
		
		if(S_ISCHR(statBuf.st_mode))
			fprintf(stdout, "is a Character Special.");
	
		if(S_ISLNK(statBuf.st_mode))
			fprintf(stdout, "is a Symbolic Link.");

		if(S_ISFIFO(statBuf.st_mode))
			fprintf(stdout, "is a FIFO File.");

		if(S_ISSOCK(statBuf.st_mode))
			fprintf(stdout, "is a Socket File.");

		return 0;
	}
