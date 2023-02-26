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
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
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

void Reverse(struct Node *p)
{
	int i=0,n=Count(p);
	int A[n];
	while(p!=NULL)
	{
		A[i]=p->data;
		i++;
		p=p->next;
	}
	p=first;
	i--;
	while(p!=NULL)
	{
		p->data=A[i];
		p=p->next;
		i--;
	}
}

void Reverse1(struct Node *p)
{
	struct Node *q=NULL,*r=NULL;
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
}

void RReverse(struct Node *q,struct Node *p)
{
	if(p!=NULL)
	{
		RReverse(p,p->next);
		p->next=q;
	}
	else
	{
		first=q;
	}
}

int main()
{
	int A[]={1,2,3,4,5,6,7,8};
	Create(A,8);
	Reverse(first);
	RReverse(NULL,first);
	Display(first);
}
