#include<stdio.h>
void main()
{
int last,m,i,j,t,n,k;
scanf("%d",&t);
for(j=0;j<t;j++)
{
	scanf("%d %d",&n,&k);
	int a[n];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
						    	
	for(i=1;i<=k;i++){
		last=a[n-1];
		for(m=n-1;m>0;m--)
		a[m]=a[m-1];
		a[0]=last;
											
		}
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
}
					
}
