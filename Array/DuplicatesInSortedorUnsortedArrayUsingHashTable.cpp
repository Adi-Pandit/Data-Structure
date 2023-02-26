#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n=10;
	int A[n]={8,3,6,4,6,5,6,8,2,7};
	int *H;
	int i,j,k,l,max,min;
	
	max=A[0];
	for(i=1;i<n;i++)
	{
		if(max<A[i])
			max=A[i];
	}
	
	min=A[0];
	for(j=1;j<n;j++)
	{
		if(min>A[j])
			min=A[j];
	}
	
	H=(int *)malloc((max+1)*sizeof(int));
	for(int z=0;z<=max;z++)
	{
		H[z]=0;
	}
	for(k=0;k<n;k++)
	{
		H[A[k]]++;
	}
	
	for(l=min;l<=max;l++)
	{
		if(H[l]>1)
			printf("%d appears %d times\n",l,H[l]);
	}
}
