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

struct Node * Search(struct Node *p,int key)
{
	while(p!=NULL)
	{
		if(p->data==key)
			return p;
		p=p->next;
	}
	return NULL;
}

struct Node * RSearch(struct Node *p,int key)
{
	if(p==NULL)
		return NULL;
	if(p->data==key)
		return p;
	else
		return RSearch(p->next,key);
}

struct Node * LSearch(struct Node *p,int key)
{
	struct Node *q=NULL;
	while(p!=NULL)
	{
		if(key==p->data)
		{
			q->next=p->next;
			p->next=first;
			first=p;
			return p;
		}
		q=p;
		p=p->next;
	}
	return NULL;
}

int main()
{
	struct Node *temp;
	int A[]={1,2,3,4,5};
	Create(A,5);
	temp=LSearch(first,5);
	temp=LSearch(first,4);
	if(temp!=NULL)
		printf("%d\n",temp->data);
	else
		printf("Key is not found\n");
	Display(first);
	return 0;
}
