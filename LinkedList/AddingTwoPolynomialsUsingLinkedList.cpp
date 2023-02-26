#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int coeff;
	int power;
	struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void CreateFirst()
{
	int i,nz;
	struct Node *t,*last=NULL;
	printf("Enter no. of terms : ");
	scanf("%d",&nz);
	printf("\nEnter coefficiant and power : \n");
	for(i=0;i<nz;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		scanf("%d %d",&t->coeff,&t->power);
		t->next=NULL;
		if(first==NULL)
			first=last=t;
		else
		{
			last->next=t;
			last=t;
		}
	}
}

void CreateSecond()
{
	int i,nz;
	struct Node *t,*last=NULL;
	printf("\nEnter no. of terms : ");
	scanf("%d",&nz);
	printf("\nEnter coefficiant and power : \n");
	for(i=0;i<nz;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		scanf("%d %d",&t->coeff,&t->power);
		t->next=NULL;
		if(second==NULL)
			second=last=t;
		else
		{
			last->next=t;
			last=t;
		}
	}
}

void Display(struct Node *p)
{
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

int Length(struct Node *p)
{
	int cnt=0;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}
	return cnt;
}

void Add(struct Node *p,struct Node *q)
{
	struct Node *r,*last=NULL;
	
	while(p!=NULL && q!=NULL)
	{
		r=(struct Node *)malloc(sizeof(struct Node));
		r->next=NULL;
		if(p->power>q->power)
		{
			r->coeff=p->coeff;
			r->power=p->power;
			if(third==NULL)
				third=last=r;
			else
			{
				last->next=r;
				last=r;
			}
			p=p->next;
		}
		else if(p->power<q->power)
		{
			r->coeff=q->coeff;
			r->power=q->power;
			if(third==NULL)
				third=last=r;
			else
			{
				last->next=r;
				last=r;
			}
			q=q->next;
		}
		else
		{
			r->coeff=p->coeff+q->coeff;
			r->power=p->power;
			if(third==NULL)
				third=last=r;
			else
			{
				last->next=r;
				last=r;
			}
			p=p->next;
			q=q->next;	
		}	
	}
	while(p!=NULL) 
	{
		r=(struct Node *)malloc(sizeof(struct Node));
		r->next=NULL;
		r->coeff=p->coeff;
		r->power=p->power;
		if(third==NULL)
			third=last=r;
		else
		{
			last->next=r;
			last=r;
		}
		p=p->next;	
	}
	while(q!=NULL) 
	{
		r=(struct Node *)malloc(sizeof(struct Node));
		r->next=NULL;
		r->coeff=q->coeff;
		r->power=q->power;
		if(third==NULL)
			third=last=r;
		else
		{
			last->next=r;
			last=r;
		}
		q=q->next;	
	}
}

int main()
{
	CreateFirst();
	CreateSecond();
	
	printf("\n1st polynominal\n");
	Display(first);
	printf("\n\n2nd polynominal\n");
	Display(second);
	printf("\n\nSum\n");
	Add(first,second);
	Display(third);
}
