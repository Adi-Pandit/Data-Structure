#include<iostream>

using namespace std;

class Queue
{
  private:
    int size;
    int front;
    int rear;
    int *Q;
  public:
    Queue()
    {
      size = 10;
      front = rear = -1;
      Q = new int[size];
    }
    Queue(int size)
    {
      this->size = size;
      front = rear = -1;
      Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
    int first();
    int last();
    int isEmpty();
    int isFull();
};

void Queue::enqueue(int x)
{
  if(rear==size-1)
    cout<<"Queue is full";
  else
  {
    Q[rear+1] = x;
    rear++;
  }
}

int Queue::dequeue()
{
  int x = -1;
  if(front==rear)
    cout<<"Queue is empty";
  else
  {
    x = Q[front+1];
    front++;
  }
  return x;
}

void Queue::display()
{
  for(int i=front+1; i<=rear; i++)
    cout<<Q[i]<<" ";
  cout<<endl;
}

int Queue::first()
{
  if(front==rear)
    return -1;
  return Q[front+1];
}

int Queue::last()
{
  if(front==rear)
    return -1;
  return Q[rear];
}

int Queue::isEmpty()
{
  if(front==rear)
    return 1;
  return 0;
}

int Queue::isFull()
{
  if(rear==size-1)
    return 1;
  return 0;
}

int main()
{
  Queue q;

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.display();

  cout<<"Dequeue: "<<q.dequeue()<<endl;
  q.display();

  cout<<"First: "<<q.first()<<endl;
  cout<<"Last: "<<q.last()<<endl;

  cout<<"isEmpty: "<<q.isEmpty()<<endl;
  cout<<"isFull: "<<q.isFull()<<endl;
}