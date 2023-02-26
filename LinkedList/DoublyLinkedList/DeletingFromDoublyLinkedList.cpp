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
	first->data=A[0];
	first->prev=first->next=NULL;
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

int Delete(struct Node *p,int index)
{
	int x=-1,i;
	
	if(index<1 || index>Length(p))
		return x;
	
	if(index==1)
	{
		x=p->data;
		first=first->next;
		free(p);
		if(first!=NULL)
			first->prev=NULL;
	}
	else
	{
		for(i=0;i<index-1;i++)
			p=p->next;
		p->prev->next=p->next;
		if(p->next!=NULL)
			p->next->prev=p->prev;
		x=p->data;
		free(p);
	}
	return x;
}

int main()
{
	int A[]={1,2,3,4,5};
	Create(A,5);
	printf("%d\n",Delete(first,3));
	Display(first);
}
