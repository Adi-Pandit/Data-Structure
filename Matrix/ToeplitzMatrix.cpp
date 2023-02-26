#include<stdio.h>
#include<stdlib.h>

struct Tridgnl
{
	int *A;
	int n;
};

void Set(struct Tridgnl *m,int i,int j,int x)
{
	if(i<=j)
		m->A[j-i]=x;
	else
		m->A[m->n+i-j-1]=x;
}

int Get(struct Tridgnl m,int i,int j)
{
	if(i<=j)
		return m.A[j-i];
	else
		return m.A[m.n+i-j-1];
}

void Display(struct Tridgnl m)
{
	int i,j;
	for(i=0;i<m.n;i++)
	{
		for(j=0;j<m.n;j++)
		{
			if(i<=j)
				printf("%d ",m.A[j-i]);
			else 
				printf("%d ",m.A[m.n+i-j-1]);
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
	
	m.A=(int *)malloc((2*m.n-1)*sizeof(int));
	
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
