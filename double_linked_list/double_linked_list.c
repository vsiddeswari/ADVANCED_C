#include<stdio.h>
#include<stdlib.h>
struct double_link
{
	struct double_link *prev;
	int num;
	struct double_link *next;
};
void add_begin(struct double_link **ptr,int num)
{
	struct double_link *new=malloc(sizeof(struct double_link));
        new->num=num;
	new->next=*ptr;
	new->prev=0;
	if(*ptr!=0)
	{
		(*ptr)->prev=new;
	}
	*ptr=new;
}
void add_end(struct double_link **ptr,int num)
{
	struct double_link *new,*last;
	new=malloc(sizeof(struct double_link));
	new->num=num;
	if(*ptr==0)
	{
		new->next=0;
		new->prev=0;
		*ptr=new;
	}
	else
	{
		last=*ptr;
		while((*ptr)->next)
		last=last->next;
		new->prev=last;new->next=0;
		last->next=new;
	}
}
void add_middle(struct double_link **ptr,int num)
{
	struct double_link *new,*last;
	new=malloc(sizeof(struct double_link));
	new->num=num;
	if((*ptr==0)||(new->num)<((*ptr)->num))
	{
		new->next=*ptr;
		new->prev=0;
		if(*ptr!=0)
			(*ptr)->prev=new;

		*ptr=new;
	}
	else
	{
		last=*ptr;
		while((last->next!=0)&&(last->next->num < new->num))
			last=last->next;
		new->next=last->next;
		new->prev=last;
		if(last->next !=0)
			new->next->prev=new;
		last->next=new;
	}
}
void display(struct double_link *ptr)
{
	struct double_link *temp=ptr;
	if(temp==0)
	{
		printf("no nodes available\n");
		return ;
	}
	while(temp)
	{
		printf("%d ",temp->num);
		temp=temp->next;
	}
printf("\n");
}

void delete_node(struct double_link **ptr,int node,int c)
{
	int num,i;
	struct double_link *del=*ptr;
	if(*ptr==0)
	{
		printf("no nodes available\n");
		return;
	}
//	c=count_node(*ptr);
//	printf("%d\n",c);
	if(node>0 && node<=c)
	{
		for(i=1;i<=c;i++)
		{
			if(i==node)
			{
				if(del==*ptr)
				{
					*ptr=(*ptr)->next;
					(*ptr)->prev=0;
				}
				else
				{
					if(del->next!=0)
						del->next->prev=del->prev;
					del->prev->next=del->next;
				}
				free(del);
				return ;
			}
			del=del->next;
		}
	}
	else
		printf("node out of range\n");
}
int count_node(struct double_link **ptr)
{
	int c=0;
	struct double_link *temp=*ptr;
	if(temp==0)
	{
		printf("no records available\n");
		return 0;
	}
	while(temp)
	{
		c++;
		temp=temp->next;
	}
	return c;
}


void main()
{
	int c;
	struct double_link *head=0;
	display(head);
	add_begin(&head,1);
	display(head);
	add_end(&head,3);
	display(head);
	add_middle(&head,2);
        display(head);
	c=count_node(&head);
	printf("%d\n",c);
        delete_node(&head,2,c);
	display(head);
}


