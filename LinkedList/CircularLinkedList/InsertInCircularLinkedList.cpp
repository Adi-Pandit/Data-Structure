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
		if(head==NULL)
		{
			head=t;
			head->next=head;
		}
		else
		{		
			while(p->next!=head)
				p=p->next;
			t->next=head;
			p->next=t;
			head=t;
		}
	}
	else
	{
		for(i=0;i<index-1;i++)
			p=p->next;
		t->next=p->next;
		p->next=t;
	}
}

int main()
{
	int A[]={1,2,3,4,5};
	Create(A,5);
	Insert(head,10,0);
	Display(head);
}
