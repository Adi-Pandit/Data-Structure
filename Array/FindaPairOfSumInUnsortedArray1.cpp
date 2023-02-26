#include<stdio.h>

int main()
{
	int A[10]={6,3,8,10,16,7,5,2,9,14};
	int k=10,i,j;
	
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(A[i]+A[j]==k)
				printf("%d+%d=%d\n",A[i],A[j],k);
		}
	}
}
