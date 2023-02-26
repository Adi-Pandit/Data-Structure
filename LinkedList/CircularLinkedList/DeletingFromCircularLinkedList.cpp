#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
}*head;

void Create(int A[],int n)
{
	int i;
	struct Node *t,*last;
	head=(struct Node *)malloc(sizeof(struct Node));
	head->data=A[0];
	head->next=head;
	last=head;
	
	for(i=1;i<n;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=last->next;
		last->next=t;
		last=t;
	}
}

void Display(struct Node *p)
{
	do
	{
		printf("%d ",p->data);
		p=p->next;
	}while(p!=head);
}

int Length(struct Node *p)
{
	int cnt=0;
	do
	{
		cnt++;
		p=p->next;
	}while(p!=head);
	return cnt;
}

int Delete(struct Node *p,int index)
{
	struct Node *q;
	int i,x=-1;
	
	if(index<0 || index>Length(p))
		return x;
		
	if(index==1)
	{
		x=head->data;
		while(p->next!=head)
			p=p->next;
		if(head==p)
		{
			delete p;
			head=NULL;
		}
		else
		{
			p->next=head->next;
			delete head;
			head=p->next;
		}
	}
	else
	{
		for(i=0;i<index-2;i++)
		{
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		x=q->data;
		delete q;
	}
	return x;
}

int main()
{
	int A[]={1,2,3,4,5};
	Create(A,5);
	Delete(head,2);
	Display(head);
}
