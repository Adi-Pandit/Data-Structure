#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int size;
	int Top;
	int *S;
};

void Create(struct Stack *st)
{
	printf("Enter Size : ");
	scanf("%d",&st->size);
	st->S=(int *)malloc(st->size*sizeof(int));
	st->Top=-1;
}

void Push(struct Stack *st,int x)
{
	if(st->Top==st->size-1)
		printf("\nStack overflow");
	else
	{
		st->Top++;
		st->S[st->Top]=x;
	}
}

int Pop(struct Stack *st)
{
	int x=-1;
	if(st->Top==-1)
		printf("\nStack underflow");
	else
	{
		x=st->S[st->Top];
		st->Top--;
	}
	return x;
}

int Peek(struct Stack st,int index)
{
	int x=-1;
	if(st.Top-index+1<0)
		printf("\n\nInvalid Index");
	else
		x=st.S[st.Top-index+1];
	return x;
}

int StackTop(struct Stack st)
{
	if(st.Top==-1)
		return -1;
	else
		return st.S[st.Top]; 
}

int isEmpty(struct Stack st)
{
	if(st.Top==-1)
		return 1;
	else
		return 0;
}

int isFull(struct Stack st)
{
	if(st.Top==st.size-1)
		return 1;
	else
		return 0;
}

void Display(struct Stack st)
{
	printf("\n\nDisplaying Stack\n");
	int i;
	for(i=st.Top;i>=0;i--)
	{
		printf("%d\n",st.S[i]);
	}
}

int main()
{
	struct Stack st;
	Create(&st);
	Push(&st,10);
	Push(&st,20);
	Push(&st,30);
	Push(&st,40);
	Push(&st,50);
	
	printf("\nPop item : %d",Pop(&st));
	printf("\nPop item : %d",Pop(&st));
	
	printf("\n\nPeek item : %d",Peek(st,2));
	
	printf("\n\nStack Top item : %d",StackTop(st));
	
	printf("\n\nStack empty : %d",isEmpty(st));
	printf("\n\nStack full : %d",isFull(st));
	
	Display(st);
}
