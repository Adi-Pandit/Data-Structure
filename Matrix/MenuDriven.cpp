#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *A,n,ch,i,j,x;
	
	printf("Enter Dimension : ");
	scanf("%d",&n);
	
	A=(int *)malloc(n*sizeof(int));
	
	do
	{
		printf("\nMenu\n1.Create\n2.Get\n3.Set\n4.Display\n5.Exit\n");
		printf("Enter choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("\nEnter elements : \n");
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=n;j++)
					{
						scanf("%d",&x);
						if(i==j)
							A[i-1]=x;
					}
				}
				break;
			case 2:
				printf("\nEnter ith jth position : ");
				scanf("%d %d",&i,&j);
				if(i==j)
					printf("\n%d",A[i-1]);
				else
					printf("\n0");
				break;
			case 3:
				printf("\nEnter ith jth position and element : ");
				scanf("%d %d %d",&i,&j,&x);
				if(i==j)
					A[i-1]=x;
				break;
			case 4:
				printf("\n");
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=n;j++)
					{
						if(i==j)
							printf("%d ",A[i-1]);
						else
							printf("0 ");
					}
					printf("\n");
				}
				break;
		}
	}while(ch<5 && ch>0);
}
