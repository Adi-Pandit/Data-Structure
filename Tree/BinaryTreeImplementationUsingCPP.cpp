#include <iostream>
#include "QueueCPP.h"

using namespace std;

class Tree
{
  public:
    Node *root;
    Tree()
    {
      root=NULL;
    }
    void TreeCreate();
    void PreOrder(Node *p);
    void InOrder(Node *p);
    void PostOrder(Node *p);
};

void Tree::TreeCreate()
{
  Node *p,*t=NULL;
  int x;
  cout<<"Enter root value: ";
  cin>>x;
  root=new Node;
  root->data=x;
  root->lchild=root->rchild=NULL;
  Queue q(100);
  q.enqueue(root);

  while(!q.isEmpty())
  {
    p=q.dequeue();

    cout<<"Enter left child of "<<p->data<<": ";
    cin>>x;
    if(x!=-1)
    {
      t=new Node;
      t->data=x;
      t->lchild=t->rchild=NULL;
      p->lchild=t;
      q.enqueue(t);
    }

    cout<<"Enter right child of "<<p->data<<": ";
    cin>>x;
    if(x!=-1)
    {
      t=new Node;
      t->data=x;
      t->lchild=t->rchild=NULL;
      p->rchild=t;
      q.enqueue(t);
    }
  }
}

void Tree::PreOrder(Node *p)
{
  if(p)
  {
    cout<<p->data<<" ";
    PreOrder(p->lchild);
    PreOrder(p->rchild);
  }
}

void Tree::InOrder(Node *p)
{
  if(p)
  {
    InOrder(p->lchild);
    cout<<p->data<<" ";
    InOrder(p->rchild);
  }
}

void Tree::PostOrder(Node *p)
{
  if(p)
  {
    PostOrder(p->lchild);
    PostOrder(p->rchild);
    cout<<p->data<<" ";
  }
}

int main()
{
  Tree t;
  t.TreeCreate();
  cout<<"Pre-order: ";
  t.PreOrder(t.root);
  cout<<endl;
  cout<<"In-order: ";
  t.InOrder(t.root);
  cout<<endl;
  cout<<"Post-order: ";
  t.PostOrder(t.root);
  cout<<endl;
}