#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL,*second=NULL;

void CreateFirst(int A[],int n)
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

void CreateSecond(int A[],int n)
{
	int i;
	struct Node *t,*last;
	second=(struct Node *)malloc(sizeof(struct Node));
	second->data=A[0];
	second->next=NULL;
	last=second;
	
	for(i=1;i<n;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

void Concat(struct Node *p,struct Node *q)
{
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=q;
	q=NULL;
}

void Display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

int main()
{
	int A[]={1,2,3,4};
	int B[]={5,6,7};
	CreateFirst(A,4);
	CreateSecond(B,3);
	
	Concat(first,second);
	Display(first);
}
