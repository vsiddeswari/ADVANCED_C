
      /* circular double linked list  */

#include<stdio.h>
#include<stdlib.h>
typedef struct circular
{
	        int data;
		        struct circular *prev;
			struct circular *next;
}cdll;
void add_begin(cdll**,int);
void add_end(cdll**,int);
void add_middle(cdll**,int) ;
void delete_node(cdll**,int);
void display(cdll*);
int count_node(cdll*);
/* main function */
void main()
{
         cdll *headptr=0;
	 int num;
       display(headptr);
       add_begin(&headptr,1);
       add_end(&headptr,3);
       add_middle(&headptr,2);
       add_begin(&headptr,4);
       display(headptr);
       delete_node(&headptr,2);  
       display(headptr);
       num=count_node(headptr);
       printf("%d\n",num);

}
         


/*adding at begining of the list*/
void add_begin(cdll **ptr,int value)
{
       cdll *new,*last;
new=(cdll *)malloc(sizeof(cdll));
new->data=value;
/* linked list is free  */
if(*ptr==0)
{
	*ptr=new;
	new->prev=new;
	new->next=new;
}
/*  if linked list already having nodes  */
else
{	
new->next=*ptr;
new->prev=(*ptr)->prev;
(*ptr)->prev->next=new;
(*ptr)->prev=new;
*ptr=new;
}
}

/*Adding at ending of the list*/
void add_end(cdll **ptr,int value)
{
	cdll *new,*last;
	new=(cdll *)malloc(sizeof(cdll));
	new->data=value;
	/*if linked list is free  */
	if(*ptr==0)
	{
		new->next=new;
		new->prev=new;
		*ptr=new;
	}
	/*if linked already have nodes */ 
	else
	{
		new->next=*ptr;
		new->prev=(*ptr)->prev;
		(*ptr)->prev->next=new;
		(*ptr)->prev=new;
	}
}

/*adding at middle*/

void add_middle(cdll **ptr,int value)
{
	cdll *new,*last;
	new=malloc(sizeof(cdll));
	new->data=value;
	if(*ptr==0||(new->data)<((*ptr)->data))
	{
		new->next=*ptr;
		new->prev=(*ptr)->prev;
		*ptr=new;
	}
	else
	{
		last=*ptr;
	while((last->next!=*ptr)&&(last->next->data  <  new->data))
		last=last->next;
	new->next=last->next;
	new->prev=last->next->prev;
	last->next->prev=new;
	last->next=new;
        }
	last=*ptr;
	while(last->next!=*ptr)
		last=last->next;
	last->next=*ptr;
}
/*DISPLAYING OF ALL NODES*/
void display(cdll *ptr)
{
	cdll *first=ptr;
        if(ptr==0)
	{
	  printf("no nodes available\n");
          return;
        }
        do
	{
		printf("%d\t",ptr->data);
	       	ptr=ptr->next;
	}while(ptr!=first);
printf("\n");
}      
/*DELETEING OF GIVEN NODE */
void delete_node(cdll **ptr,int value)
{
     cdll *del=*ptr;
     int c,i;
	if(*ptr==0)
	{
		printf("no nodes available\n");
		return;
	}

	c=count_node(*ptr);
	if(value>0 && value<=c)
	{
		for(i=1;i<=c;i++)
		{
			if(value==i)
			{
				if(del==*ptr)
				{
				*ptr=del->next;
		         	}
			del->prev->next=del->next;
			del->next->prev=del->prev;
	        	free(del);
	         	return;
        	        }
			del=del->next;
	       	
		}
	}
	else
		printf("node num outof range\n");
}

/*   COUNTING NODES  */
int count_node(cdll *ptr)
{
	int c=0;
	if(ptr==0)
	{
		printf("no nodes found\n");
		return 0;
	}
	cdll *pres=ptr;
	do{
		c++;
		pres=pres->next;
	}while(pres!=ptr);
return c;
}
