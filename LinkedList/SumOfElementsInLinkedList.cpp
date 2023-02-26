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

int Sum(struct Node *p)
{
	int sum=0;
	while(p!=NULL)
	{
		sum=sum+p->data;
		p=p->next;
	}
	return sum;
}

int RSum(struct Node *p)
{
	if(p!=NULL)
		return RSum(p->next)+p->data;
	else
		return 0;	
}

int main()
{
	int A[]={1,2,3,4,5};
	Create(A,5);
	printf("%d",RSum(first));
}
