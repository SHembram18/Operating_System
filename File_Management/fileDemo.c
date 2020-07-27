/*
 * A SIMPLE PROGRAM TO OUTPUT SOMETHING
 * TO STANDARD OUTPUT DEVICE
 * USING write() SYSTEM CALL
 * File: fileDemo.c
 */
        #include <fcntl.h>

        int main()
        {
                int fd;
                fd = open("fileDemo12345.c",O_RDONLY);
                if( fd == -1)
                {
                        write(2,"Error in opening file !!!",25);
                        return 1;
                }
                else
                {
                        write(1,"Open successfull ...",20);
                }
                close(fd);
                return 0;
        }

