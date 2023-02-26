#include<stdio.h>
#include<stdlib.h>

struct Tridgnl
{
	int *A;
	int n;
};

void Set(struct Tridgnl *m,int i,int j,int x)
{
	if((i-j)==1)
		m->A[i-1]=x;
	else if((i-j)==0)
		m->A[m->n-1+i-1]=x;
	else if((i-j)==-1)
		m->A[2*m->n-1+i-1]=x;
}

int Get(struct Tridgnl m,int i,int j)
{
	if((i-j)==1)
		return m.A[i-1];
	else if((i-j)==0)
		return m.A[m.n-1+i-1];
	else if((i-j)==-1)
		return m.A[2*m.n-1+i-1];
	else
		return 0;
}

void Display(struct Tridgnl m)
{
	int i,j;
	for(i=0;i<m.n;i++)
	{
		for(j=0;j<m.n;j++)
		{
			if((i-j)==1)
				printf("%d ",m.A[i-1]);
			else if((i-j)==0)
				printf("%d ",m.A[m.n-1+i-1]);
			else if((i-j)==-1)
				printf("%d ",m.A[2*m.n-1+i-1]);
			else
				printf("0 ");
		}
		printf("\n");
	}
}

int main()
{
	struct Tridgnl m;
	int n,i,j,x;
	
	printf("Enter Dimension : ");
	scanf("%d",&m.n);
	
	m.A=(int *)malloc((3*m.n-2)*sizeof(int));
	
	printf("\nEnter Elements : \n");
	for(i=0;i<m.n;i++)
	{
		for(j=0;j<m.n;j++)
		{
			scanf("%d",&x);
			Set(&m,i,j,x);
		}
	}
	printf("\n\n");
	Display(m);
}
