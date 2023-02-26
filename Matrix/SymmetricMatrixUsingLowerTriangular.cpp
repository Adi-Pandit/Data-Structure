#include<stdio.h>
#include<stdlib.h>

struct Matrix 
{
	int *A;
	int n;
};

int Swap(int *x,int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
}
void Set(struct Matrix *m,int i,int j,int x)
{
	if(i>=j)
		m->A[i*(i-1)/2+j-1]=x;
}

int Get(struct Matrix m,int i,int j)
{
	int t,x,y;
	if(i>=j)
		return m.A[i*(i-1)/2+j-1];
	else
	{
		return m.A[j*(j-1)/2+j-1];
	}
}

void Display(struct Matrix m)
{
	int i,j,x,y,t;
	for(i=1;i<=m.n;i++)
	{
		for(j=1;j<=m.n;j++)
		{
			if(i>=j)
				printf("%d ",m.A[i*(i-1)/2+j-1]);
			else
			{
				printf("%d ",m.A[j*(j-1)/2+i-1]);
			}
		}
		printf("\n");
	}
}

int main()
{
	struct Matrix m;
	int i,j,x;
	
	printf("Enter Dimension : ");
	scanf("%d",&m.n);
	
	m.A=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));
	
	printf("\nEnter elements : \n");
	for(i=1;i<=m.n;i++)
	{
		for(j=1;j<=m.n;j++)
		{
			scanf("%d",&x);
			Set(&m,i,j,x);
		}
	}
	printf("\n");
	Display(m);
	
	printf("\n%d",Get(m,4,3));
	return 0;
}
