/* required for printf , scanf  */
#include<stdio.h>
/* main program starts */
void main()
{
	/* declaring elements  */	
	int n,i,j;
	/* reading the no of elements in the array from stdin  */
	scanf("%d",&n);
	int array[n],array1[n];
	/* reading values of array from stdin */
	for(i=0;i<n;i++)
		scanf("%d",&array[i]);
	/* rearranging the array  */
	for(i=0;i<n;i++)
	{
		/* checking for the indexes associated with the number  */
		for(j=0;j<n;j++)
		{
			if(array[j]==i)
			{
				array1[i]=j;
				break;
			}
		}
	}
	/* printing the rearranged array  */
	for(i=0;i<n;i++)
		printf("%d ",array1[i]);
}
