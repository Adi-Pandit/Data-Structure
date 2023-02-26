#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*first=NULL;

int Count(struct Node *p)
{
	int cnt=0;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;	
	}	
	return cnt;
}

void Display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

void Insert(struct Node *p,int index,int x)
{
	int i;
	struct Node *t;
	t=(struct Node *)malloc(sizeof(struct Node));
	t->data=x;
	
	if(index<0 || index>Count(p))
		return;
	if(index==0)
	{
		t->next=first;
		first=t;
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
	Insert(first,0,1);
	Insert(first,1,2);
	
	printf("Before Insertion : ");
	Display(first);
	
	printf("\nAfter Insertion : ");
	Insert(first,0,8);
	Display(first);
}
