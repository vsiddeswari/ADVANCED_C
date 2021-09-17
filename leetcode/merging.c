/*given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
   * Merge nums1 and nums2  into a single array sorted in non-decreasing order.
    
     * The final sorted array shiuld not be returned by the function. but instead be stored inside the array nums1. To accomidate this, nums1 has a length of m+n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 *     *
 *  test case 1:
 * Input : nums1 = [1,2,3,0,0,0], m = 3, 
 * nums2 = [2,5,6] , n = 3
 * Output : nums1=[1,2,2,3,5,6]
*/
 /*! include headers */
#include<stdio.h>

 /*! merge function */
 void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
	int i,j,temp;
	 

	for(i=m,j=0;i<nums1Size;i++,j++)
						
	{
	nums1[i] = nums2[j];
	}

	/*! sorting using bubbule sort technique */

	for(i=1;i<nums1Size;i++)
	{
		for(j=0;j<nums1Size-i;j++)
		{
			if(nums1[j]>nums1[j+1])
			{																				temp = nums1[j];																		nums1[j] = nums1[j+1];

			nums1[j+1] = temp;
																							}
		}

	}
}

/*! main program starts */
int main()
{
		int nums1[] = {1,0,3,2,0,0};
		int nums2[] = {2,5,6};
		int m = 3, n = 3,i;
		int nums1Size = sizeof(nums1)/4;
		int nums2Size = sizeof(nums2)/4;
		printf("Input : \n");
		printf("nums1 = ");
		for(i=0;i<nums1Size;i++)
		{
			printf("%d ",nums1[i]);
		}
		printf("\n");

		printf("nums2 = ");
		for(i=0;i<nums2Size;i++)
		{
		printf("%d ",nums2[i]);
		}
		printf("\n");

		merge(nums1,nums1Size,m,nums2,nums2Size,n);

		printf("Output:  \n");
		for(i=0;i<nums1Size;i++)
		{
																						printf("%d ",nums1[i]);																		}
																	
		return 0;
}
