#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *lchild;
  int data;
  struct Node *rchild;
}*root=NULL;

void Insert(int key)
{
  struct Node *t=root;
  struct Node *r=NULL,*p;

  if(root==NULL)
  {
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    root=p;
    return;
  }

  while(t!=NULL)
  {
    r=t;
    if(t->data==key)
      return;
    else if(key<t->data)
      t=t->lchild;
    else
      t=t->rchild;
  }

  p=(struct Node *)malloc(sizeof(struct Node));
  p->data=key;
  p->lchild=p->rchild=NULL;

  if(key<r->data)
    r->lchild=p;
  else
    r->rchild=p;
}

struct Node *RInsert(struct Node *p,int key)
{
  struct Node *t;

  if(p==NULL)
  {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=key;
    t->lchild=t->rchild=NULL;
    return t;
  }
  if(key<p->data)
    p->lchild=RInsert(p->lchild,key);
  else if(key>p->data) 
    p->rchild=RInsert(p->rchild,key);
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

struct Node *Search(int key)
{
  struct Node *t=root;

  while(t!=NULL)
  {
    if(key==t->data)
      return t;
    else if(key<t->data)
      t=t->lchild;
    else  
      t=t->rchild;
  }
  return NULL;
}

int Height(struct Node *p)
{
  int x=0,y=0;
  if(p==NULL)
    return 0;
  x=Height(p->lchild);
  y=Height(p->rchild);
  return x>y?x+1:y+1;
}

struct Node *InPre(struct Node *p)
{
  while(p && p->rchild)
    p=p->rchild;
  return p;
}

struct Node *InSucc(struct Node *p)
{
  while(p && p->lchild)
    p=p->lchild;
  return p;
}

struct Node *Delete(struct Node *p,int key)
{
  struct Node *q;

  if(p==NULL)
    return NULL;

  if(p->lchild==NULL && p->rchild==NULL)
  {
    if(p==root)
      root=NULL;
    free(p);
    return NULL;
  }

  if(key<p->data)
    p->lchild=Delete(p->lchild,key);
  else if(key>p->data)
    p->rchild=Delete(p->rchild,key);
  else
  {
    if(Height(p->lchild)>Height(p->rchild))
    {
      q=InPre(q->lchild);
      p->data=q->data;
      p->lchild=Delete(p->lchild,q->data);
    }
    else
    {
      q=InSucc(q->rchild);
      p->data=q->data;
      p->rchild=Delete(p->rchild,q->data);
    }
  }
  return p;
}

struct Node *RSearch(struct Node *t,int key)
{
  if(t==NULL)
    return NULL;
  if(t->data==key)
    return t;
  else if(key<t->data)
    return RSearch(t->lchild,key);
  else
    return RSearch(t->rchild,key);
}

int main()
{
  struct Node *temp;

  root=RInsert(root,10);
  RInsert(root,5);
  RInsert(root,15);
  RInsert(root,3);
  RInsert(root,7);
  RInsert(root,13);
  RInsert(root,17);

  Delete(root,17);

  printf("In-order: ");
  InOrder(root);

  temp=RSearch(root,15);
  if(temp!=NULL)
    printf("\nElement is found");
  else
    printf("\nElement not found");
}