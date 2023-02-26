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

void LastInsert(int x)
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

int main()
{
	LastInsert(1);
	LastInsert(2);
	LastInsert(3);
	Display(first);
}
