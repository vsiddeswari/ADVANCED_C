#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
char *buf,*buf1;
int i,j;
FILE *fptr;
buf=getcwd(buf,30);

mkdir("systemprogramming",0777);
chdir("systemprogramming");
char *dire[]={"test","program","exercise"};
char *arr[][3]={{"test1","test2","test3"},{"program1","program2","program3"},{"exercise1","exercise2","exercise3"}};
for(i=0;i<3;i++)
{
mkdir(dire[i],0777);
buf1=getcwd(buf1,100);
chdir(dire[i]);
for(j=0;j<3;j++)
{
fptr=fopen(arr[i][j],"w");
fclose(fptr);
}
chdir(buf1);
}
chdir(buf);
return 0;
}

