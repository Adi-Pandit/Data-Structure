#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
  struct Node *t = (struct Node *)malloc(sizeof(struct Node));
  if(t==NULL)
    printf("Queue is full");
  else
  {
    t->data = x;
    t->next = NULL;
    if(front==NULL)
      front = rear = t;
    else
    {
      rear->next = t;
      rear = t;
    }
  }
}

int dequeue()
{
  int x = -1;
  if(front==NULL)
    printf("Queue is empty");
  else
  {
    struct Node *t = front;
    x = front->data;
    front = front->next;
    free(t);
  }
  return x;
}

void display()
{
  struct Node *p = front;
  while(p!=NULL)
  {
    printf("%d ",p->data);
    p = p->next;
  }
  printf("\n");
}

int first()
{
  if(front==NULL)
    return -1;
  return front->data;
}

int last()
{
  if(front==NULL)
    return -1;
  return rear->data;
}

int isEmpty()
{
  if(front==NULL)
    return 1;
  return 0;
}

int isFull()
{
  struct Node *t = (struct Node *)malloc(sizeof(struct Node));
  if(t==NULL)
    return 1;
  return 0;
}

int main()
{
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);
  display();

  printf("Dequeue: %d\n", dequeue());
  display();

  printf("First: %d\n", first());
  printf("Last: %d\n", last());
  printf("isEmpty: %d\n", isEmpty());
  printf("isFull: %d\n", isFull());
}