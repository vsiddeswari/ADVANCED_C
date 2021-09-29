
#include<stdio.h>
#include<stdlib.h>

struct NODE
{
int data;
struct NODE *prev;
struct NODE *next;
};
struct NODE* reverse(struct NODE *ptr)
{
struct NODE *last=ptr,*prevv=NULL;
while(last->next)
{
last=last->next;
} 
ptr=last;
prevv=last->next;
last->next=last->prev;
last->prev=prevv;
while(last->next)
{
last=last->next;
prevv=last->next;
last->next=last->prev;
last->prev=prevv;
}
return ptr;
}

void add_node(struct NODE **ptr,int num)
  {
         struct NODE *present,*new,*last;
         new=malloc(sizeof(struct NODE));
         new->data=num;
          if(*ptr==0)
          {
                  new->next=0;
                  new->prev=0;
                 *ptr=new;
          }
         else
          {
                  last=*ptr;
                  while(last&&last->data<num)
	{
                present=last;
		last=last->next;  
	}
		if(last==*ptr){		
		new->next=last;
                 last->prev=new;
                  *ptr=new;
          }
	else if(last)
{
last->prev->next=new;
new->prev=last->prev;
last->prev=new;
new->next=last;
}
else
{
present->next=new;
new->prev=present;
}
}
}
	

 
void display(struct NODE *ptr)
  {
          struct NODE *temp=ptr;
          if(temp==0)
          {
                  printf("no nodes available\n");
                 return ;
          }
         while(temp)
          {
                  printf("%d ",temp->data);
                  temp=temp->next;
          }
  printf("\n");
  }

void main()
{
struct NODE *head=NULL;
int i,val;
for(i=0;i<10;i++)
{
val=rand()%100+1;
add_node(&head,val);
}
display(head);
head=reverse(head);
display(head);
}
