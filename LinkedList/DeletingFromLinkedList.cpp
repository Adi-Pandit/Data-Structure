#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL,*last=NULL;

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

int Delete(struct Node *p,int pos)
{
	struct Node *q;
	int x=-1,i;
	if(pos<1 || pos>Count(p))
	{
		return x;
	}
	if(pos==1)
	{
		q=first;
		x=first->data;
		first=first->next;
		free(q);
	}
	else
	{
		for(i=0;i<pos-1;i++)
		{
			q=p;
			p=p->next;
		}
		x=p->data;
		q->next=p->next;
		free(p);
	}
	return x;
}

int main()
{
	LInsert(10);
	LInsert(20);
	LInsert(30);
	LInsert(40);
	LInsert(50);
	
	printf("Deleted Element : %d\n",Delete(first,10));
	Display(first);
}
