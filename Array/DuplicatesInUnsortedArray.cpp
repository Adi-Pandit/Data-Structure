#include<stdio.h>
#include<stdlib.h>

int main()
{
	int A[10]={8,3,6,4,6,5,6,8,2,7};
	int i,j,count;
	for(i=0;i<10;i++)
	{
		if(A[i]!=-1)
		{
			count=1;
			for(j=i+1;j<10;j++)
			{
				if(A[i]==A[j])
				{
					count++;
					A[j]=-1;
				}
			}
			if(count>1)
				printf("%d appears %d times\n",A[i],count);
		}
	}
}
