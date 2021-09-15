
/*single linked list */

#include<stdio.h>
#include<stdlib.h>
typedef struct single
{
int data;
struct single *next;
}sll;

void add_begin(sll **,int);
void add_end(sll **,int);
void add_middle(sll **,int);
void delete_node(sll **,int);
void display(sll *);


/* main program */
void main()
{
sll *headptr=0;
display(headptr);
add_begin(&headptr,2);
add_end(&headptr,6);
add_begin(&headptr,1);
delete_node(&headptr,6);
add_middle(&headptr,5);
delete_node(&headptr,7);
display(headptr);
}

/* adding at begging of the linked list  */

void add_begin(sll **ptr,int value)
{
sll *new=malloc(sizeof(sll));
new->data=value;
new->next=*ptr;
*ptr=new;
}

/* adding at ending of linked list */

void add_end(sll **ptr,int value)
{
sll *last,*new=malloc(sizeof(sll));
new->data=value;
if(*ptr==0)
{
new->next=0;
*ptr=new;
}
else
{
new->next=0;
last=*ptr;
while(last->next)
last=last->next;
last->next=new;
}
}

/*adding the value at middle  */

void add_middle(sll**ptr,int value)
{
sll *new,*last;
new=malloc(sizeof(sll));
new->data=value;
if((*ptr==0)||(new->data<(*ptr)->data))
{
new->next=*ptr;
*ptr=new;
}
else{
last=*ptr;

while((last->next!=0)&&(last->next->data<new->data))
last=last->next;
new->next=last->next;
last->next=new;
}
}

/* displaying the linked list  */

void display(sll *ptr)
{
if(ptr==0)
{
printf("no nodes available\n");
return;
}
while(ptr)
{
printf("%d\t",ptr->data);
ptr=ptr->next;
}
printf("\n");
}

/*deleting a node of given value */

void delete_node(sll **ptr,int value)
{
sll *del,*prev;
del=prev=*ptr;
if(*ptr==0)
{
	printf("no nodes available to delete\n");
	return;
}
while(del)
{
	if(del->data==value)
	{
		if(del==*ptr)
			*ptr=del->next;
		else
			prev->next=del->next;
	
		free(del);
		return;
	}
	prev=del;
	del=del->next;
}
}

