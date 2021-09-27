
/*write the code for ll_min function below.
The function returns the smallest of all numbers in the pointed-to list.
A sample call is provided in main().
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
int *num;
struct node *next;
};

int ll_min(struct node **ptr) {
	    // TODO your code here
	struct node *current=*ptr;
	int min_value=*current->num;
	current=current->next;
    while(current)
    {
	if(*current->num < min_value)
	{
		min_value=*current->num;
	}
      current=current->next;
    }
    return min_value;
}
int main()
{
int x = 258, y = 207, z = 209;
struct node n1, n2, n3;
	       
struct node *ptr = &n1;
n1.num = &x;
n1.next = &n2;
n2.num = &y;
	      
n2.next = &n3;
n3.num = &z;
n3.next = NULL;
printf("%d\n", ll_min(&ptr)); // Should print 207
return 0;
 }
	    
