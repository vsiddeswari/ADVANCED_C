#include<stdio.h>
#include<string.h>
void main()
{
	int i,r,j,t,count;
	char a[t][10];
	scanf("%d",&t);
for(i=0;i<t;i++)
scanf(" %s",&a[i]);
for(i=0;i<t;i++)
{
	count=0;
	for(j=0;j<i;j++)
	{
	r=strcmp(a[i],a[j]);
	
	if(r>0)
	count++;
	}
	printf("%d\n",count);
}

}
