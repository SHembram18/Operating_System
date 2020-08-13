*
 *
 *
 *
 */
        #include<sys/stat.h>
        #include<stdio.h>
        #include<unistd.h>

        int main(int argc,char **argv)
        {
                struct stat statbuff;

                if(argc!=2)
                {
                        write(STDERR_FILENO, "Invalid Argument(s) !!!\n",23);
                        return 1;
                }

                if( lstat(argv[1], &statbuff) == -1 )
                {
                        perror(argv[1]);
                        return 2;
                }

                fprintf(stdout, "File : %s\n", argv[1]);
                fprintf(stdout, "Inode Number : %d\n", statbuff.st_ino );
                fprintf(stdout, "File size (bytes) : %u\n", statbuff.st_size );
                fprintf(stdout, "Blocks Occupied : %d\n", statbuff.st_blocks );
                fprintf(stdout, "Block Size : %d\n", statbuff.st_blksize);
                fprintf(stdout, "Last modify time : %s\n", ctime(&statbuff.st_mtime) );
                fprintf(stdout, "UID : %u\n", statbuff.st_uid);
                fprintf(stdout, "GID : %u\n", statbuff.st_gid);
                fprintf(stdout, "Type & Permission : %o\n", statbuff.st_mode);

                return 0;
        }
~                                                                                                                                                                                           
~                                                                                                                                                                                           
~         
