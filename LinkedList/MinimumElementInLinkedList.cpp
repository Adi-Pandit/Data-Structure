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

int Min(struct Node *p)
{
	int m=INT_MAX;
	while(p!=NULL)
	{
		if(m>p->data)
			m=p->data;
		p=p->next;
	}
	return m;
}

int RMin(struct Node *p)
{
	int x=0;
	if(p==NULL)
		return INT_MAX;
	x=RMin(p->next);
	return x<p->data?x:p->data; 
}

int main()
{
	int A[]={1,2,3,4,5};
	Create(A,5);
	printf("%d",RMin(first));
}
