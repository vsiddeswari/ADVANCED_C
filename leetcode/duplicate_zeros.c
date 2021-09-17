/* given a fixed length integer array arr, duplicate each occurance of zero, shifting the remaining elements to the right.
 * Note: that elements beyond the length of the original array are not written. 
 *  
 * Test case 1:
 * Input: arr = [1,0,2,3,0,4,5,0]
 * Output: arr = [1,0,0,2,3,0,0,4]   */

 /*! include headers */
#include<stdio.h>

 /*! duplication function */
 void duplicateZeros(int *arr,int arrSize)
{
int i,j;
for(i=0;i<arrSize;i++)
{
if(arr[i] == 0)
{
for(j=arrSize-1;j>i;j--)
{
																				arr[j] = arr[j-1];
																				}
i = i+1;
																				}
}
}

/*! main program starts */
int main()
{
int arr[] = {1,0,2,3,0,4,5,0};
int size  = sizeof(arr)/4;
int i;
printf("input arr= ");
for(i=0;i<size;i++)
{
printf("%d ",arr[i]);
}
printf("\n");
								
duplicateZeros(arr,size);
printf("output arr= ");
for(i=0;i<size;i++)
{
printf("%d ",arr[i]);
}
printf("\n");
return 0;
}

