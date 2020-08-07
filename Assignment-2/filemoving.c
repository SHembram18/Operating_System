/*
 *
 */

#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define TOKENSIZE       20
#define DELIM           "/\0"
#define BUFFSIZE        512

int main(int argc, char **argv)
{

        int fd1, fd2;
        int n=1;

        char buf[BUFFSIZE];
        char *tokens[TOKENSIZE];

        char destination[200];

        if(argc != 3)
        {
                write(STDERR_FILENO, "Invalid Argument(s) !!!",23 );
				return 1;
        }

//Tokenize the argv[1]  
        tokens[0] = strtok(argv[1], DELIM);
        while( (tokens[n]=strtok(NULL, DELIM)) != NULL)
        {
                n++;
        }
//open source file
        fd1= open(argv[1], O_RDONLY);
        if(fd1 == -1)
        {
                perror(argv[1]);
                return 2;
        }
/*
//change directory to destination       
        if( chdir(argv[2]) == -1)
        {
                perror(argv[2]);
                close(fd1);
                return 3;
        }
*/
        strcpy(destination, argv[2]);
		strcat(destination, "/");
        strcat(destination, tokens[n-1]);

        if( (fd2=open(destination, O_WRONLY | O_CREAT | O_EXCL)) ==  -1 )
        {
                perror(destination);
                close(fd1);
                return 2;
        }

        n=0;
//read from source and write into destination
        while( (n=read(fd1, buf, BUFFSIZE)) >0 )
        {
                if(write(fd2, buf, n) ==0)
                {
                        perror("write");
                }
        }

        close(fd2);

        close(fd1);

//remove source file
        unlink(argv[1]);
		 return 0;
}


