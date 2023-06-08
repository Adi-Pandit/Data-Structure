#include<stdio.h>
#include "Queue.h"

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

int main()
{
  TreeCreate();
  printf("\nPre-order: ");
  PreOrder(root);
  printf("\nIn-order: ");
  InOrder(root);
  printf("\nPost-order: ");
  PostOrder(root);
}