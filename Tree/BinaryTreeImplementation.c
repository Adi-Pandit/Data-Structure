#include <stdio.h>
#include "Stack.h"

struct Node *root = NULL;

void TreeCreate()
{
  struct Node *p, *t;
  int x;
  struct Queue q;
  create(&q, 100);

  printf("Enter root value: ");
  scanf("%d",&x);
  root = (struct Node *)malloc(sizeof(struct Node));
  root->lchild = root->rchild = NULL;
  root->data = x;
  enqueue(&q, root);

  while(!isEmpty(q))
  {
    p = dequeue(&q);

    printf("Enter left child of %d: ",p->data);
    scanf("%d",&x);
    if(x!=-1)
    {
      t = (struct Node *)malloc(sizeof(struct Node));
      t->data = x;
      t->lchild = t->rchild = 0;
      p->lchild = t;
      enqueue(&q,t);
    }

    printf("Enter right child of %d: ",p->data);
    scanf("%d",&x);
    if(x!=-1)
    {
      t = (struct Node *)malloc(sizeof(struct Node));
      t->data = x;
      t->lchild = t->rchild = 0;
      p->rchild = t;
      enqueue(&q,t);
    }
  }
}

void PreOrder(struct Node *p)
{
  if(p)
  {
    printf("%d ",p->data);
    PreOrder(p->lchild);
    PreOrder(p->rchild);
  }
}

void InOrder(struct Node *p)
{
  if(p)
  {
    InOrder(p->lchild);
    printf("%d ",p->data);
    InOrder(p->rchild);
  }
}

void PostOrder(struct Node *p)
{
  if(p)
  {
    PostOrder(p->lchild);
    PostOrder(p->rchild);
    printf("%d ",p->data);
  }
}

void IPreOrder(struct Node *p)
{
  struct Stack st;
  createStack(&st,100);

  while(p!=NULL || !isEmptyStack(st))
  {
    if(p!=NULL)
    {
      printf("%d ",p->data);
      push(&st,p);
      p=p->lchild;
    }
    else
    {
      p=pop(&st);
      p=p->rchild;
    }
  }
}

void IInOrder(struct Node *p)
{
  struct Stack st;
  createStack(&st,100);

  while(p!=NULL || !isEmptyStack(st))
  {
    if(p!=NULL)
    {
      push(&st,p);
      p=p->lchild;
    }
    else
    {
      p=pop(&st);
      printf("%d ",p->data);
      p=p->rchild;
    }
  }
}

void IPostOrder(struct Node *p)  //For this convert stack.h to long int instead of struct Node *
{
  struct Stack st;
  createStack(&st,100);
  long int temp;

  while(p!=NULL || !isEmptyStack(st))
  {
    if(p!=NULL)
    {
      push(&st,p);
      p=p->lchild;
    }
    else
    {
      temp = pop(&st);
      if(temp>0)
      {
        push(&st,-temp);
        p=((struct Node *)temp)->rchild;
      }
      else
      {
        printf("%d ",((struct Node *)-temp)->data);
        p=NULL;
      }
    }
  }
}

int main()
{
  TreeCreate();
  printf("\nPre-order: ");
  IPreOrder(root);
  printf("\nIn-order: ");
  IInOrder(root);
  printf("\nPost-order: ");
  IPostOrder(root);
}