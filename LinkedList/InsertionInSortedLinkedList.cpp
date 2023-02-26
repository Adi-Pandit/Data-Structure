#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL,*last=NULL;

void Display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

void LInsert(int x)
{
	struct Node *t;
	t=(struct Node *)malloc(sizeof(struct Node));
	t->data=x;
	t->next=NULL;
	
	if(first==NULL)
		first=last=t;
	else
	{
		last->next=t;
		last=t;
	}
}

void InsertSorted(struct Node *p,int x)
{
	struct Node *t,*q;
	p=first;
	q=NULL;
	t=(struct Node *)malloc(sizeof(struct Node));
	t->data=x;
	t->next=NULL;
	
	if(p==NULL)
		first=t;
	else
	{
		while(p!=NULL && p->data<x)
		{
			q=p;
			p=p->next;
		}
		if(p==first)
		{
			t->next=first;
			first=t;
		}
		else
		{
			t->next=p;
			q->next=t;
		}
	}
}

int main()
{
	LInsert(10);
	LInsert(20);
	LInsert(30);
	LInsert(40);
	LInsert(50);
	
	Display(first);
	printf("\n");
	InsertSorted(first,45);
	Display(first);
}
