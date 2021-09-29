#include<stdio.h>
int m,n=5;          /* global variables  */
static int j,k=10;  /* global static variables */ 
void main()       
{
int i=10;           /* auto variables*/
static int o,p=20;  /* local static variables*/
//printf("bye\n");
printf("%d %d\n",i,p);
}

