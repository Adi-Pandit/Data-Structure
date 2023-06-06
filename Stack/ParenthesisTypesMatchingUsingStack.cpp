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
		p=top;
		x=top->data;
		top=top->next;
		free(p);
	}
	return x;
}

int isBalance(char *exp)
{
	int i,j;
	char x;
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
			Push(exp[i]);
		else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
		{
			if(top==NULL)
				return 0;
			x=Pop();
			if((int)(exp[i])-(int)(x)!=1 && (int)(exp[i])-(int)(x)!=2)
				return 0;
		}
	}
	if(top==NULL)
		return 1;
	else
		return 0;
}

int main()
{
	char *exp="{a*[b+c*(d-e)/2]}";
	
	printf("%d",isBalance(exp));
	
	return 0;
}
