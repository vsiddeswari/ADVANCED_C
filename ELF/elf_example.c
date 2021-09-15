/* program for checking the given file is  ELF or not */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
/* main program starts  */
void main(int argc,char *argv[])
{
/*checking for command line input is passed or not */
	if(argc!=2)
	{
		printf("usage:./a.out filename\n");
                exit(1);
	}

	int fd,data;
	/* opening input file in read only mode */
       fd=open(argv[1],O_RDONLY);
if(fd<0)
{
printf("failed to open file\n");
exit(1);
}
/* reading first four bytes data from file*/
read(fd,&data,sizeof(data));
/* checking input file is elf or not*/
       if(data==0x464c457f)
	printf("The file is ELF..\n");
	else
	printf("The file is not ELF..\n");
}

