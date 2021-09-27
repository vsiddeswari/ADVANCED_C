#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

NODE *add_node(NODE *head,int n)
{
	NODE *new = (NODE *)malloc(sizeof(NODE));
	new->data = n;
	new->next = NULL;
	if(head == NULL)
	{
		head = new;
	}
	else
	{
		NODE *temp = head;
		while(temp->next)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
	return head;
}


NODE *delete_node(NODE *head,int n)
{
	NODE *temp = head,*prev = NULL;
	while(n && temp->next!=NULL)
	{
		if(temp->data < temp->next->data)
		{
			if(temp==head)
			{
				head = temp->next;
			}
			else{
				prev->next = temp->next;
			}
			n--;
		}
		else
		{
			prev = temp;
		}
		temp = temp->next;
			
	}
	if(n)
	{
		head = delete_node(head,n);
	}
	return head;
}

void display(NODE *head)
{
	NODE *temp = head;
	while(temp)
	{
		printf("%d ",temp->data);
		temp= temp->next;
	}
	printf("\n");
}

int main()
{
		
	int T,N,i,j,val;
	scanf("%d",&T);
	NODE *head[T];
	int K[T];
	for(i=0;i<T;i++)
	{
		head[i] = NULL;
	}
	for(i=0;i<T;i++)
	{
		scanf("%d %d",&N,&K[i]);
		for(j=0;j<N;j++)
	       	{
			scanf("%d",&val);
				 														
			head[i] = add_node(head[i],val);
		}
	}
	for(i=0;i<T;i++)
	{
		head[i] = delete_node(head[i],K[i]);
	}
	for(i=0;i<T;i++)
	{							
		display(head[i]);
	}
	return 0;
}
