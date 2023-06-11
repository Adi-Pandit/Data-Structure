#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *lchild;
  int data;
  int height;
  struct Node *rchild;
}*root=NULL;

int NodeHeight(struct Node *p)
{
  int hl=0,hr=0;
  hl=(p && p->lchild) ? p->lchild->height : 0;
  hr=(p && p->rchild) ? p->rchild->height : 0;

  return hl>hr ? hl+1 : hr+1;
}

int BalanceFactor(struct Node *p)
{
  int hl=0,hr=0;
  hl=(p && p->lchild) ? p->lchild->height : 0;
  hr=(p && p->rchild) ? p->rchild->height : 0;

  return hl-hr;
}

struct Node *LLRotation(struct Node *p)
{
  struct Node *pl=p->lchild;
  struct Node *plr=pl->rchild;

  pl->rchild=p;
  p->lchild=plr;

  pl->height=NodeHeight(pl);
  p->height=NodeHeight(p);

  if(root==p)
    root=pl;
  return pl;
}

struct Node *LRRotation(struct Node *p)
{
  struct Node *pl=p->lchild;
  struct Node *plr=pl->rchild;

  pl->rchild=plr->lchild;
  p->lchild=plr->rchild;

  plr->lchild=pl;
  plr->rchild=p;

  p->height=NodeHeight(p);
  plr->height=NodeHeight(plr);
  pl->height=NodeHeight(pl);

  if(root==p)
    root=plr;
  return plr;
}

struct Node *RInsert(struct Node *p,int key)
{
  struct Node *t=NULL;

  if(p==NULL)
  {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=key;
    t->height=1;
    t->lchild=t->rchild=NULL;
    return t;
  }

  if(key<p->data)
    p->lchild=RInsert(p->lchild,key);
  else if(key>p->data)
    p->rchild=RInsert(p->rchild,key);

  p->height=NodeHeight(p);

  if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
    return LLRotation(p);
  else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
    return LRRotation(p);

  return p;
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
  root=RInsert(root,10);
  RInsert(root,5);
  RInsert(root,2);

  InOrder(root);
}