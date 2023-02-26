#include<stdio.h>
#include<stdlib.h>

struct Term
{
	int coeff;
	int exp;
};

struct Poly
{
	int n;
	struct Term *t;
};

void Create(struct Poly *p)
{
	int i;
	printf("Enter no. of non-zero element : ");
	scanf("%d",&p->n);
	p->t=(struct Term *)malloc(p->n*sizeof(struct Term));
	printf("\nEnter coefficiant and exponent : \n");
	for(i=0;i<p->n;i++)
	{
		printf("Enter %d term : ",i+1);
		scanf("%d %d",&p->t[i].coeff,&p->t [i].exp);
	}
}

void Display(struct Poly p)
{
	int i;
	printf("\n");
	for(i=0;i<p.n;i++)
	{
		if(i==p.n-1)
			printf("%dX%d = 0",p.t[i].coeff,p.t[i].exp);
		else
			printf("%dX%d + ",p.t[i].coeff,p.t[i].exp);
	}
	printf("\n");
}

struct Poly * Add(struct Poly *p1,struct Poly *p2)
{
	int i,j,k;
	struct Poly *sum;
	sum = (struct Poly *)malloc(sizeof(struct Poly));
	sum->t=(struct Term *)malloc((p1->n+p2->n)*sizeof(struct Term));
	i=j=k=0;
	
	while(i<p1->n && j<p2->n)
	{
		if(p1->t[i].exp>p2->t[j].exp)
			sum->t[k++]=p1->t[i++];
		else if(p1->t[i].exp<p2->t[j].exp)
			sum->t[k++]=p2->t[j++];
		else
		{
			sum->t[k].exp=p1->t[i].exp;
			sum->t[k++].coeff=p1->t[i++].coeff+p2->t[j++].coeff;
		}
	}
	
	for(;i<p1->n;)  sum->t[k++]=p1->t[i++];
	for(;j<p2->n;)  sum->t[k++]=p2->t[j++];
	
	sum->n=k;
	return sum;
}

int main()
{
	struct Poly p1,p2,*p3;
	Create(&p1);
	printf("\n");
	Create(&p2);
	p3=Add(&p1,&p2);
	
	printf("\n");
	Display(p1);
	printf("\n");
	Display(p2);
	printf("\n");
	Display(*p3);
	return 0;
}
