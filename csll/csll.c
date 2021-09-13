
      /* circular linked list  */

#include<stdio.h>
#include<stdlib.h>
typedef struct circular
{
	        int data;
		        struct circular *next;
}csll;
void add_begin(csll**,int);
void add_end(csll**,int);
void add_middle(csll**,int) ;
void delete_node(csll**,int);
void display(csll*);

/* main function */
void main()
{
         csll *headptr=0;
         display(headptr);
 	 add_begin(&headptr,1);
         add_end(&headptr,3);
       add_middle(&headptr,2);
       add_begin(&headptr,4);
       display(headptr);
       delete_node(&headptr,2);  
       display(headptr);
}
         


/*adding at begining of the list*/
void add_begin(csll **ptr,int value)
{
       csll *new,*last;
new=(csll *)malloc(sizeof(csll));
new->data=value;
/* linked list is free  */
if(*ptr==0)
{
	*ptr=new;
	new->next=new;
}
/*  if linked list already having nodes  */
else
{	
new->next=*ptr;
last=*ptr;
while(last->next!=*ptr)
	last=last->next;
last->next=new;
*ptr=new;
}
}

/*Adding at ending of the list*/
void add_end(csll **ptr,int value)
{
	csll *new,*last;
	new=(csll *)malloc(sizeof(csll));
	new->data=value;
	/*if linked list is free  */
	if(*ptr==0)
	{
		new->next=new;
		*ptr=new;
	}
	/*if linked already have nodes */ 
	else
	{
		last=*ptr;
		while(last->next!=*ptr)
			last=last->next;
                 new->next=*ptr;
                 last->next=new;
	}
}

/*adding at middle*/
void add_middle(csll **ptr,int value)
{
	csll *new,*last;
	new=malloc(sizeof(csll));
	new->data=value;
	if(*ptr==0||(new->data)<((*ptr)->data))
	{
		new->next=*ptr;
		*ptr=new;
	}
	else
	{
		last=*ptr;
	while((last->next!=*ptr)&&(last->next->data  <  new->data))
		last=last->next;
	new->next=last->next;
	last->next=new;
        }
	last=*ptr;
	while(last->next!=*ptr)
		last=last->next;
	last->next=*ptr;
}
/*DISPLAYING OF ALL NODES*/
void display(csll *ptr)
{
	csll *first=ptr;
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
/*DELETEING NODE OF GIVEN VALUE */
void delete_node(csll **ptr,int value)
{
	if(*ptr==0)
	{
		printf("no nodes available\n");
		return;
	}
	csll *del=*ptr,*last=*ptr,*prev=*ptr;
	do{
                 		if(del->data==value)
		{
			if(del==*ptr){
			last=*ptr;
			while(last->next!=*ptr)
				last=last->next;
			last->next=del->next;
			*ptr=del->next;
		}
		else
		{
			prev->next=del->next;
		}
		free(del);
		return;
	}

                	prev=del;
                	del=del->next;

         }while(del!=*ptr);
printf("value not found\n");
}


