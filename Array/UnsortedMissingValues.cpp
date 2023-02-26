#include<stdio.h>
#include<stdlib.h>

struct array 
{
	int A[12];
	int size;
	int length;
};

int main()
{
	struct array arr={{3,7,4,9,12,6,1,11,2,10},12,10};
	int i,j,l,m,max,min;
	int *H;
	max=arr.A[0];
	for(i=1;i<arr.length;i++)
	{
		if(arr.A[i]>max)
		{
			max=arr.A[i];
		}
	}
	min=arr.A[0];
	for(j=1;j<arr.length;j++)
	{
		if(arr.A[j]<min)
		{
			min=arr.A[j];
		}
	}
	
	H=(int *)malloc((max+1)*sizeof(int));
	for(i=0;i<=max;i++)
	{
		H[i]=0;
	}
	for(l=0;l<=max;l++)
	{
		H[arr.A[l]]++;
	}
	for(m=min;m<=max;m++)
	{
		if(H[m]==0)
			printf("%d ",m);
	}
}
