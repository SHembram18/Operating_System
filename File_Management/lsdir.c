/*
 * TO DEMONSTRATE THE EACH FILE TYPE AND PERMISSIONS OF A DIRECTORY 
 * FILE :- lsdir.c
 *
 */
	#include<sys/types.h>
	#include<sys/stat.h>
	#include<stdio.h>
	#include<dirent.h>

	int main(int argc , char **argv)
	{
		DIR *dirPtr;
		struct dirent *dirEntryPtr;
		mode_t  file_type , file_perm;
		struct stat statBuf;
		

		if(argc!=2)
		{
			fprintf(stderr, "Invalid Argument(s) !!!\n");
			return 1;
		}

		if( (dirPtr = opendir(argv[1])) == NULL )
		{
			perror(argv[1]);
			return 2;
		}

		while( (dirEntryPtr = readdir(dirPtr)) != NULL )
		{
			if( lstat(dirEntryPtr->d_name, &statBuf) < 0 )
			{
				perror("lstat");
				continue;
			}
			file_type = statBuf.st_mode & S_IFMT;
			file_perm = statBuf.st_mode & ~S_IFMT;
			fprintf(stdout, "%o %4d %s\n",file_type, file_perm, dirEntryPtr->d_name);
		}

		closedir(dirPtr);

		return 0;
	}
