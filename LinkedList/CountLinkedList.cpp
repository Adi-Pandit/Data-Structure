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

int Count(struct Node *p)
{
	int c=0;
	while(p!=NULL)
	{
		c++;
		p=p->next;
	}
	return c;
}

int RCount(struct Node *p)
{
	if(p!=NULL)
		return RCount(p->next)+1;
	else
		return 0;
}

int Count1(struct Node *p)
{
	int x=0;
	if(p)
	{
		x=Count(p->next);
		return x+1;
	}
	else
		return 0;
}

int main()
{
	int A[]={1,2,3,4,5};
	Create(A,5);
	printf("%d",Count1(first));
}
