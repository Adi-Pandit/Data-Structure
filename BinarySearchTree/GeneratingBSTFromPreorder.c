#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void createPre(int pre[],int n)
{
  struct Stack stk;
  struct Node *p,*t;
  int i=0;

  createStack(&stk,100);
  root=(struct Node *)malloc(sizeof(struct Node));
  root->data=pre[i++];
  root->lchild=root->rchild=NULL;
  p=root;

  while(i<n)
  {
    if(pre[i]<p->data)
    {
      t=(struct Node *)malloc(sizeof(struct Node));
      t->data=pre[i++];
      t->lchild=t->rchild=NULL;
      p->lchild=t;
      Push(&stk,p);
      p=t;
    }
    else
    {
      if(pre[i]>p->data && pre[i]<(isEmpty(stk)?32000:stackTop(stk)->data))
      {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=pre[i++];
        t->lchild=t->rchild=NULL;
        p->rchild=t;
        p=t;
      }
      else
      {
        p=stackTop(stk);
        Pop(&stk);
      }
    }
  }
}

void InOrder(struct Node *p)
{
  if(p!=NULL)
  {
    InOrder(p->lchild);
    printf("%d ",p->data);
    InOrder(p->rchild);
  }
}

int main()
{
  int pre[]={30,20,10,15,25,40,50,45};
  createPre(pre,8);
  InOrder(root);
}