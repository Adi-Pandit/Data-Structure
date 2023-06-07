#include<stdio.h>
#include<stdlib.h>

struct Queue
{
  int size;
  int front;
  int rear;
  int *Q;
};

void create(struct Queue *q, int size)
{
  q->size = size;
  q->front = q->rear = -1;
  q->Q = (int *)malloc(size*sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
  if(q->rear==q->size-1)
    printf("Queue is full");
  else
  {
    q->rear++;
    q->Q[q->rear] = x;
  }
}

int dequeue(struct Queue *q)
{
  int x=-1;
  if(q->front==q->rear)
    printf("Queue is empty");
  else
  {
    q->front++;
    x = q->Q[q->front];
  }
  return x;
}

void display(struct Queue q)
{
  for(int i=q.front+1; i<=q.rear; i++)
  {
    printf("%d ",q.Q[i]);
  }
  printf("\n");
}

int first(struct Queue q)
{
  if(q.front==q.rear)
    return -1;
  return q.Q[q.front+1];
}

int last(struct Queue q)
{
  if(q.front==q.rear)
    return -1;
  return q.Q[q.rear];
}

int isEmpty(struct Queue q)
{
  if(q.front==q.rear)
    return 1;
  return 0;
}

int isFull(struct Queue q)
{
  if(q.rear==q.size-1)
    return 1;
  return 0;
}

int main()
{
  struct Queue q;
  create(&q,5);

  enqueue(&q,10);
  enqueue(&q,20);
  enqueue(&q,30);
  display(q);

  printf("Dequeue: %d\n", dequeue(&q));
  display(q);

  printf("First: %d\n", first(q));
  printf("Last: %d\n", last(q));
  printf("isEmpty: %d\n", isEmpty(q));
  printf("isFull: %d\n", isFull(q));
}