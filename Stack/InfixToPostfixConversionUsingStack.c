#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
  char data;
  struct Node *next;
}*top=NULL;

void push(char x)
{
  struct Node *t = (struct Node *)malloc(sizeof(struct Node));

  if(t==NULL)
    printf("Stack Overflow");
  else
  {
    t->data = x;
    t->next = top;
    top = t;
  }
}

int pop()
{
  char x = '@';
  if(top==NULL)
    printf("Stack Underflow");
  else
  {
    struct Node *t = top;
    x = top->data;
    top = top->next;
    free(t);
  }
  return x;
}

void display()
{
  struct Node *p = top;

  while(p!=NULL)
  {
    printf("%c ",p->data);
    p = p->next;
  }
}

int isOperand(char x)
{
  if(x=='+' || x=='-' || x=='/' || x=='*')
    return 0;
  else  
    return 1;
}

int pre(char x)
{
  if(x=='+' || x=='-')
    return 1;
  else if(x=='*' || x=='/')
    return 2;
  return 0;
}

char * InfixToPostfix(char *infix)
{
  int len = strlen(infix);
  char *postfix = (char *)malloc((len+1)*sizeof(char));
  int i=0, j=0;

  while(infix[i]!='\0')
  {
    if(isOperand(infix[i]))
      postfix[j++] = infix[i++];
    else
    {
      if(pre(infix[i])>pre(top->data))
        push(infix[i++]);
      else
        postfix[j++] = pop();
    }
  }

  while(top!=NULL)
  {
    postfix[j++] = pop();
  }

  postfix[j-1] = '\0';
  return postfix;
}

int main()
{
  char *infix = "a+b*c-d/e";

  push('#');
  char *postfix = InfixToPostfix(infix);

  printf("%s",postfix);
}