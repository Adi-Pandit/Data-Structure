#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int col;
	int data;
	struct Node *next;
};

void Display(struct Node *A[],int r,int c)
{
	int i,j;
	struct Node *p;
	
	for(i=0;i<r;i++)
	{
		p=A[i];
		for(j=0;j<c;j++)
		{
			if(p!=NULL && p->col==j)
			{
				printf("%d ",p->data);
				p=p->next;
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
}

void Create(int r,int c)
{
	int nz,i,j,c1,v;
	struct Node *A[r],*last;
	
	for(i=0;i<r;i++)
	{
		A[r]=NULL;
	}
	
	for(i=0;i<r;i++)
	{
		printf("\nEnter non-zero elements in row %d : ",i);
		scanf("%d",&nz);
		
		printf("\nEnter column no. and value : ");
		scanf("%d %d",&c1,&v);
		A[i]=(struct Node *)malloc(sizeof(struct Node));
		A[i]->col=c1;
		A[i]->data=v;
		A[i]->next=NULL;
		last=A[i];
		for(j=1;j<nz;j++)
		{
			printf("\nEnter column no. and value : ");
			scanf("%d %d",&c1,&v);
			last->next=(struct Node *)malloc(sizeof(struct Node));
			last=last->next;
			last->col=c1;
			last->data=v;
			last->next=NULL;
		}
	}
	
	printf("\n\nDisplaying sparse matrix\n");
	Display(A,r,c);
}

int main()
{
	int r,c;
	printf("Enter no. of rows : ");
	scanf("%d",&r);
	printf("\nEnter no. of columns : ");
	scanf("%d",&c);
	Create(r,c);
}
