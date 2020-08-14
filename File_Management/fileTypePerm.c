/*
 *
 *
 *
 *
 */
	#include<sys/types.h>
	#include<sys/stat.h>
	#include<stdio.h>

	int main(int argc , char **argv )
	{
		mode_t file_type, file_perm;
		struct stat statBuf;


		if(argc!=2)
		{
			fprintf(stderr, "Invalid Argument(s) !!!\n");
			return 1;
		}

		if( lstat(argv[1] , &statBuf) < 0 )
		{
			perror("lstat");
			return 2;
		}

		file_type = statBuf.st_mode & S_IFMT;
		file_perm = statBuf.st_mode & ~S_IFMT;
		fprintf(stdout, "%o %4d %s\n" , file_type , file_perm , argv[1]);


		return 0;

	}
