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

int isSorted(struct Node *p)
{
	int x=INT_MIN;
	while(p!=NULL)
	{
		if(p->data<x)
			return 0;
		x=p->data;
		p=p->next;
	}
	return 1;
}

int main()
{
	LInsert(10);
	LInsert(20);
	LInsert(30);
	LInsert(40);
	LInsert(50);
	
	if(isSorted(first))
		printf("Sorted");
	else
		printf("Not Sorted");
}
