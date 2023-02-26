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

int Middle(struct Node *p)
{
	int i,n,Len=Length(p);
	n=Len/2;
	
	for(i=0;i<n;i++)
	{
		p=p->next;
	}
	return p->data;
}

int Middle1(struct Node *p)
{
	struct Node *q=first;
	while(q!=NULL)
	{
		q=q->next;
		if(q!=NULL)
			q=q->next;
		if(q!=NULL)
			p=p->next;
	}
	return p->data;
}

int main()
{
	int A[]={1,2,3,4,5};
	Create(A,5);
	printf("%d",Middle1(first));
}
