#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
}*first=NULL;

void Create(int A[],int n)
{
	int i;
	struct Node *t,*last;
	first=(struct Node *)malloc(sizeof(struct Node));
	first->prev=first->next=NULL;
	first->data=A[0];
	last=first;
	
	for(i=1;i<n;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->prev=last;
		t->next=last->next;
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

int Length(struct Node *p)
{
	int cnt=0;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}
	return cnt;
}

void Insert(struct Node *p,int index,int x)
{
	int i;
	struct Node *t;
	
	if(index<0 || index>Length(p))
		return;
		
	t=(struct Node *)malloc(sizeof(struct Node));
	t->data=x;
	
	if(index==0)
	{
		t->prev=NULL;
		t->next=first;
		first->prev=t;
		first=t;
	}
	else
	{
		for(i=0;i<index-1;i++)
			p=p->next;
		t->next=p->next;
		t->prev=p;
		if(p->next!=NULL)
			p->next->prev=t;
		p->next=t;
	}
	
}

int main()
{
	int A[]={1,2,3,4,5};
	Create(A,5);
	Insert(first,4,0);
	Display(first);
}
