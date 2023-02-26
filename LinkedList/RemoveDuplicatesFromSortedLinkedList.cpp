#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

void Create(int A[],int n)
{
	int i;
	struct Node *t,*last;
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first;
	
	for(i=1;i<n;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

void Display(struct Node *p)
{
	if(p!=NULL)
	{
		printf("%d ",p->data);
		Display(p->next);
	}
}

void RemoveDuplicates(struct Node *p)
{
	struct Node *q=first->next;
	while(q!=NULL)
	{
		if(p->data!=q->data)
		{
			p=q;
			q=q->next;
		}
		else
		{
			p->next=q->next;
			free(q);
			q=p->next;
		}
	}
}

int main()
{
	int A[]={1,1,1,2,2,3,4,4,5,5,5};
	Create(A,11);
	RemoveDuplicates(first);
	Display(first);
}
