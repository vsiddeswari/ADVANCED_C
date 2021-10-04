/* this program scan the number of inputs 

   scan the strings

   gives the output of number of strings are high strings than present string


Input: 4

"a"

"b"

"c"

"a"

Output: 

0

1

2

1   */

/* header files*/
#include<stdio.h>
#include<string.h>

/* main function*/

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
