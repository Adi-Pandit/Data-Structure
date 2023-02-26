#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	char data;
	struct Node *next;
}*top=NULL;

void Push(char x)
{
	struct Node *t=(struct Node *)malloc(sizeof(struct Node));
	if(t==NULL)
		printf("Stack overflow");
	else
	{
		t->data=x;
		t->next=top;
		top=t;
	}
}

char Pop()
{
	int x=-1;
	struct Node *p;
	if(top==NULL)
		printf("Stack underflow");
	else
	{
		x=top->data;
		p=top;
		top=top->next;
		free(p);
	}
	return x;
}

void Display()
{
	struct Node *p=top;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
}

int isBalance(char *exp)
{
	int i;
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='(')
			Push(exp[i]);
		else if(exp[i]==')')
		{
			if(top==NULL)
				return 0;
			Pop();
		}
	}
	if(top==NULL)
		return 1;
	else
		return 0;
}

int main()
{
	char *exp="((a+b)*(c-d))";
	printf("%d",isBalance(exp));
}
