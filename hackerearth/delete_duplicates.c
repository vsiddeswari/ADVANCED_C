#include<stdio.h>
#include<stdlib.h>
struct node
{
int num;
struct node *prev;
struct node *next;
};
void add_end(struct node **ptr,int value)
{
struct node *new=malloc(sizeof(struct node));
new->num=value;
if(*ptr==0)
{
new->prev=new;
new->next=new;
*ptr=new;
}
else
{
new->prev=(*ptr)->prev;
new->next=*ptr;
(*ptr)->prev->next=new;
(*ptr)->prev=new;
}
}
void display(struct node *ptr)
{
struct node *temp=ptr;
while(temp->next!=ptr)
{
printf("%d ",temp->num);
temp=temp->next;
}
printf("%d ",temp->num);
printf("\n");
}
void delete(struct node **ptr)
{
int s=0;
struct node *last=*ptr,*temp=(*ptr)->next;
do{
	last=*ptr;
	while(last!=temp)
	{
	if(last->num==temp->num)
	s=1;
	if(s==1)
	{
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	}
last=last->next;
}
temp=temp->next;
}while(temp!=*ptr);
}
void main()
{
struct node *head=0;
add_end(&head,1);
add_end(&head,3);

add_end(&head,3);
add_end(&head,3);
display(head);
delete(&head);
}


