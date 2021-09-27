#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* dan_to_c(const char *s)
{
	char *ptr=(char*)malloc(strlen(s));
	strcpy(ptr,s+1);
	return ptr;
}
void dan_strcat(char *s1,const char *s2)
{
	strcat(s1,s2+1);
	int s=strlen(s1)-1;
	if(s>9)
	{
		memmove(s1+1,s1,strlen(s1));
		char a[2];
		int i=1;
		while(s)
		{
			s1[i]=48+(s%10);
			s=s/10;
			i--;
		}

	}
	else
	{
		s1[0]=s1[0]+strlen(s2)-1;
	}
}
void main()
{
	char d_arr[20]="5siddu";
	const char d_arr2[]="4rama";
	char *p=dan_to_c(d_arr2);
	printf("%s\n",p);
	dan_strcat(d_arr,d_arr2);
	printf("%s\n",d_arr);
	printf("%s\n",d_arr2);
}

