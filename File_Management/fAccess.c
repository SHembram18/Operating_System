/*
 *      PROGRAM :  TO CHECK FILE'S OWNER PERMISSION USING access() SYSTEM CALL
 *      FILE    : fAccess.c
 *      OWNER   : SANTOSH HEMBRAM
 */
	
	#include<unistd.h>
	#include<stdio.h>

	int main(int argc, char **argv)
	{
		if(argc != 2)
		{
			fprintf(stderr, "Invalid Argument(s)... !!!\n\n");
			return 1;
		}

		if( access(argv[1], F_OK) == -1)
			fprintf(stdout, "File doesn't exist !!! ");
		else

			fprintf(stdout, "File exist. ");

		if( access(argv[1],R_OK) == -1 )
			fprintf(stdout, "Not Readable !!! ");
		else
			fprintf(stdout, "Readable. ");

		if( access(argv[1], W_OK) == -1 ) 
		 	fprintf(stdout, "Not Writeable !!! ");
		else
			fprintf(stdout, "Writeable. ");

		if( access(argv[1], X_OK) == -1 )
			fprintf(stdout, "File doesnot Executable !!! ");
		else
			fprintf(stdout, "Executable. ");

		fprintf(stdout, "\n\n");

		return 0;
	}
