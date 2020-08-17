/*
 * 	PROGRAM : CHECKING THE PERMISSION OF A FILE
 *
 */
	
	#include<stdio.h>
	#include<sys/stat.h>

	int main(int argc, char **argv)	
	{
		struct stat statBuf;
		mode_t file_perm;


		if(argc != 2)
		{
			fprintf(stderr, "Invalid Argument(s) !!!\n\n");
			return 1;
		}

		if( lstat(argv[1], &statBuf) < 0 )
		{
			perror("lstat");
			return 2;
		}

		file_perm = statBuf.st_mode & ~S_IFMT;

		fprintf(stdout, "\nFile: %s\n Others can ",argv[1] );

		if(file_perm & S_IROTH)
			fprintf(stdout, "Read");
		if(file_perm & S_IWOTH)
			fprintf(stdout, "Write");
		if(file_perm & S_IXOTH)
			fprintf(stdout, "Execute.");

		fprintf(stdout, "\n\n");
		return 0;
	}
