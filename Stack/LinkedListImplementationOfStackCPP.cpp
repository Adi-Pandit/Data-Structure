#include<iostream>

using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

class Stack
{
	private:
		Node *top;
	public:
		Stack()
		{
			top=NULL;
		}
		void Push(int x);
		int Pop();
		void Display();
		int Peek(int index);
		int StackTop();
		int isEmpty();
		int isFull();
};

void Stack::Push(int x)
{
	Node *t=new Node;
	if(t==NULL)
		cout<<"Stack overflow"<<endl;
	else
	{
		t->data=x;
		t->next=top;
		top=t;
	}
}

int Stack::Pop()
{
	int x=-1;
	if(top==NULL)
		cout<<"Stack underflow"<<endl;
	else
	{
		Node *t=top;
		x=top->data;
		top=top->next;
		delete t;
	}
	return x;
}

void Stack::Display()
{
	Node *p=top;
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		p=p->next;
	}
}

int Stack::Peek(int index)
{
	Node *p=top;
	int i;
	for(i=0;p!=NULL && i<index-1;i++)
	{
		p=p->next;
	}
	if(p!=NULL)
		return p->data;
	else
		return -1;
}

int Stack::StackTop()
{
	if(top==NULL)
		return -1;
	else
		return top->data;
}

int Stack::isEmpty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

int Stack::isFull()
{
	Node *t=new Node();
	if(t==NULL)
		return 1;
	else
		return 0;
}

int main()
{
	Stack stk;
	stk.Push(10);
	stk.Push(20);
	stk.Push(30);
	stk.Push(40);
	stk.Push(50);
	
	cout<<"Popped item : "<<stk.Pop()<<endl<<endl;
	
	cout<<"Peeked item : "<<stk.Peek(5)<<endl<<endl;
	
	cout<<"Is empty : "<<stk.isEmpty()<<endl<<endl;
	
	cout<<"Is full : "<<stk.isFull()<<endl<<endl;
	
	stk.Display();
}
