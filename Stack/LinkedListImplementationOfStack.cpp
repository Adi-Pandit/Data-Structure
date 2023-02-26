#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
};

void Push(struct Node **top,int x)
{
	struct Node *t;
	t=(struct Node *)malloc(sizeof(struct Node));
	
	if(t==NULL)
		printf("Stack overflow");
	else
	{
		t->data=x;
		t->next=*top;
		*top=t;
	}
}

int Pop(struct Node **top)
{
	struct Node *p;
	int x=-1;
	if(*top==NULL)
		printf("Stack underflow");
	else
	{
		p=*top;
		x=p->data;
		*top=(*top)->next;
		free(p);
	}
	return x;
}

int Peek(struct Node *p,int index)
{
	int i;
	for(i=0;i<index-1 && p!=NULL;i++)
		p=p->next;
	if(p!=NULL)
		return p->data;
	else
		return -1; 
}

void Display(struct Node *p)
{
	printf("\n\nDisplaying stack\n");
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

int StackTop(struct Node *top)
{
	if(top!=NULL)
		return top->data;
	return -1;
}

int isEmpty(struct Node *top)
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

int isFull(struct Node *top)
{
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	int r;
	if(t==NULL)
		r=1;
	else
		r=0;
	free(t);
	return r;
}

int main()
{
	struct Node *top=NULL;
	
	Push(&top,10);
	Push(&top,20);
	Push(&top,30);
	Push(&top,40);
	Push(&top,50);
	
	Display(top);
	
	printf("\nPopped item : %d",Pop(&top));
	printf("\nPopped item : %d",Pop(&top));
		
	Display(top);
	
	printf("\nPeeked item : %d",Peek(top,2));
	
	printf("\n\nStack Top : %d",StackTop(top));
	printf("\n\nEmpty : %d",isEmpty(top));
	printf("\n\nFull : %d",isFull(top));
}
