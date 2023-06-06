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

char pop()
{
  char x='@';
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
    printf("%c ", p->data);
    p=p->next;
  }
}

int isOperand(char x)
{
  if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')')
    return 0;
  else  
    return 1;
}

int inStkPre(char x)
{
  if(x=='+' || x=='-')
    return 2;
  else if(x=='*' || x=='/')
    return 4;
  else if(x=='^')
    return 5;
  else if(x=='(')
    return 0;
  return -1;
}

int outStkPre(char x)
{
  if(x=='+' || x=='-')
    return 1;
  else if(x=='*' || x=='/')
    return 3;
  else if(x=='^')
    return 6;
  else if(x=='(')
    return 7;
  else if(x==')')
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
    {
      postfix[j++] = infix[i++];
    }
    else
    {
      if(outStkPre(infix[i])>inStkPre(top->data))
        push(infix[i++]);
      else if(outStkPre(infix[i])==inStkPre(top->data))
      {
        pop();
        i++;
      }
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
  char *infix = "((a+b)*c)-d^e^f";
  push('#');
  char *postfix = InfixToPostfix(infix);

  printf("%s",postfix);
}