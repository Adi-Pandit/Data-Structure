#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Stack
{
  int top;
  int size;
  struct Node **S;
};

void createStack(struct Stack *st,int size)
{
  st->top=-1;
  st->size=size;
  st->S=(struct Node **)malloc(st->size*sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *x)
{
  if(st->top==st->size-1)
    printf("Stack Overflow");
  else
  {
    st->top++;
    st->S[st->top]=x;
  }
}

struct Node *pop(struct Stack *st)
{
  struct Node *x=NULL;
  if(st->top==-1)
    printf("Stack Underflow");
  else
  {
    x=st->S[st->top--];
  }
  return x;
}

int isEmptyStack(struct Stack st)
{
  if(st.top==-1)
    return 1;
  return 0;
}

