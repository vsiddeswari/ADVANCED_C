/* required for printf() scanf()  */
#include<stdio.h>
/* required for strlen() strstr() strcat()  */ 
#include<string.h>
/* main program starts */
void main()
{
	/* to hold the  strings */
	char s1[20],s2[20];
	/* reading strings from stdin */
	scanf("%s%s",s1,s2);
	/* checking the length of two strings if not equal then printing -1 and returning from main*/
	if(strlen(s1)!=strlen(s2))
	{
		printf("-1\n");
		return ;
	}
	/* concatinating the both strings  */
	strcat(s1,s1);
	/* finding the secong string is present in the first string or not ,, if presented prints 1 else print -1 */
	if(strstr(s1,s2))
	{
		printf("1\n");
	}
	else
		printf("-1\n");
}


