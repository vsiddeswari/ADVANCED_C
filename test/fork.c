
//this program creates a child process using fork


#include<stdio.h>
#include<unistd.h>
//main program starts
void main()
{
	
	
	if(fork()==0)
	{
		printf("in child\n");
	}
	else
	{
		printf("in parent\n");
	}
}

