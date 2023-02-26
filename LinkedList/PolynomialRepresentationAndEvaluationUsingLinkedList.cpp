#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node
{
	int coeff;
	int power;
	struct Node *next;
}*first=NULL;

void Create()
{
	int nz,i,c,p1;
	struct Node *t,*last;
	printf("Enter no. of terms : ");
	scanf("%d",&nz);
	printf("\nEnter Coefficiant and power : \n");
	
	for(i=0;i<nz;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		scanf("%d %d",&t->coeff,&t->power);
		t->next=NULL;
		if(first==NULL)
		{
			first=last=t;
		}
		else
		{
			last->next=t;
			last=t;
		}
	}
}

void Display(struct Node *p)
{
	printf("\n\nDisplaying Polynomial\n");
	while(p!=NULL)
	{
		if(p->next!=NULL)
		{
			printf("%dX%d + ",p->coeff,p->power);
			p=p->next;
		}
		else
		{
			printf("%dX%d = 0",p->coeff,p->power);
			p=p->next;
		}
	}
}

float Eval(struct Node *p,float x)
{
	float sum=0.0;
	while(p!=NULL)
	{
		sum+=p->coeff*pow(x,p->power);
		p=p->next;
	}
	return sum;
}

int main()
{
	//struct Node *first;
	Create();
	Display(first);
	printf("\n\nSum : %.2f",Eval(first,2));
}
