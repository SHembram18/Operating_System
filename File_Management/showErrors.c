/*
 * A program to show all the system error Messages and their error numbers 
 * File :showErrors.c
 *
 */
	#include<stdio.h>
	int main()
	{
		int k;
		extern int sys_nerr;


		printf("Error#Error Msg. \n=======================================================\n\n");
		for(k=0; k< sys_nerr ; k++)
		{
			printf("Error#: %-06d AND Message: : %s\n",k,strerror(k));

		}
		printf("Total no. of Errors Available : %d\n",sys_nerr );
		return 0;

	}
