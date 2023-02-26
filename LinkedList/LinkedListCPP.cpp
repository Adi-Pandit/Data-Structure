#include<iostream>

using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

class LinkedList
{
	private:
		Node *first;
	public:
		LinkedList()
		{
			first=NULL;
		}
		LinkedList(int A[],int n);
		~LinkedList();
		void Display();
		int Length();
		void Insert(int index,int x);
		int Delete(int index);
};

LinkedList::LinkedList(int A[],int n)
{
	Node *t,*last;
	first=new Node;
	first->data=A[0];
	first->next=NULL;
	last=first;
	
	for(int i=1;i<n;i++)
	{
		t=new Node();
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

LinkedList::~LinkedList()
{
	Node *p=first;
	while(first!=NULL)
	{
		first=first->next;
		delete p;
		p=first;
	}	
} 

void LinkedList::Display()
{
	Node *p=first;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;	
	}	
} 

int LinkedList::Length()
{
	Node *p=first;
	int cnt=0;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}
	return cnt;
}

void LinkedList::Insert(int index,int x)
{
	Node *t,*p=first;
	t=new Node;
	t->data=x;
	t->next=NULL;
	
	if(index<0 || index>Length())
		return;
	if(index==0)
	{
		t->next=first;
		first=t;
	}
	else
	{
		for(int i=0;i<index-1;i++)
			p=p->next;
		t->next=p->next;
		p->next=t;
	}
}

int LinkedList::Delete(int index)
{
	Node *p=first,*q=NULL;
	int x=-1;
	if(index<0 || index>Length())
		return x;
	if(index==1)
	{
		x=p->data;
		first=first->next;
		delete p;
		return x;
	}
	else
	{
		for(int i=0;i<index-1;i++)
		{
			q=p;
			p=p->next;
		}
		x=p->data;
		q->next=p->next;
		delete p;
		return x;
	}
}

int main()
{
	int A[]={1,2,3,4,5};
	LinkedList l(A,5);
	cout<<l.Length()<<endl;
	l.Display();
}

