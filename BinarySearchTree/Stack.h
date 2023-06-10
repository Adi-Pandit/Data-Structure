#include <stdio.h>
#include <stdlib.h>

struct Node 
{
  struct Node *lchild;
  int data;
  struct Node *rchild;
}*root=NULL;

struct Stack
{
  int size;
  int top;
  struct Node **S;
};

void createStack(struct Stack *st, int size)
{
  st->top=-1;
  st->size=size;
  st->S=(struct Node **)malloc(sizeof(struct Node *));
}

void Push(struct Stack *st, struct Node *x)
{
  if(st->top==st->size-1)
    printf("Stack Full");
  else
  {
    st->top++;
    st->S[st->top]=x;
  }
}

struct Node *Pop(struct Stack *st)
{
  struct Node *x=NULL;
  if(st->top==-1)
    printf("Stack Empty");
  else
  {
    x=st->S[st->top];
    st->top--;
  }
  return x;
}

int isEmpty(struct Stack st)
{
  if(st.top==-1)
    return 1;
  return 0;
}

struct Node *stackTop(struct Stack st)
{
    return st.S[st.top]; 
}