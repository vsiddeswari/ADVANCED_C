/* program to create directory and child directory and files*/

/* header files */
#include<stdio.h>
#include<sys/fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
void files(char *ptr)
{
if(strcmp(ptr,"test")==0)
{
system(touch test1 test2 test3);
}
else if(strcmp(ptr,"programs")
{
system(touch prog1 prog2 prog3 prog4 prog5);
}
else if(strcmp(ptr,"exercises")==0)
{
system(touch exer1 exer2 exer3 exer4 exer5 exer6 exer7 exer8 exer9 exer10);
}
}
int main(int argc, char **argv)
{
	char *sub_dir[3]={"test","programs","exercises"};
	char *path=NULL,*path1=NULL;
	int i;
	if((path=getcwd(path,100))==NULL)
	{
	printf("%s\n",strerror(errno));
	return 0;
	}

	if(argc != 2)
	{
		printf("Usage : ./a.out sysProg\n");
		return 0;
	}
	if(argc==2)
	{
		if((access(argv[1],F_OK))==0)
		{
			printf("already exists\n");
			return 0;
		}
	
		if(mkdir(argv[1],0777)==-1)
		{
			printf("%s\n",strerror(errno));
			return 0;
		}
		if(chdir(argv[1])==-1)
		{
		printf("%s\n",strerror(errno));
		return 0;
		}		
	}
for(i=0;i<3;i++)
{		
	if(mkdir(sub_dir[i],0777)==-1)
	{
	printf("%s\n",strerror(errno));
	return 0;
	}
	if((path1=getcwd(path1,100))==NULL)
	{
	printf("%s\n",strerror(errno));
	return 0; 
	}
	if(chdir(sub_dir[i])==-1)
	{
		printf("%s\n",strerror(errno));
		return 0;
	}
	files(sub_dir[i]);
	if(chdir(path1)==-1)
	{
	printf("%s\n",strerror(errno));
	return 0;
	}
	
}

if(chdir(path)==-1)
{
printf("%s\n",strerror(errno));
return 0;
}
}

