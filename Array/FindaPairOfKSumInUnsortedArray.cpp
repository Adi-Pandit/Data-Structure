#include<stdio.h>
#include<stdlib.h>

int main()
{
	int A[10]={6,3,8,10,16,7,5,2,9,14};
	int n=10;
	
	int *H;
	int i,k=10,l,max,min;
	
	max=A[0];
	for(i=1;i<n;i++)
	{
		if(max<A[i])
			max=A[i];
	}
		
	H=(int *)malloc((max+1)*sizeof(int));
	for(int z=0;z<=max;z++)
	{
		H[z]=0;
	}
	
	for(l=0;l<n;l++)
	{
		if(H[k-A[l]]!=0 && (k-A[l])>=0)
		{
			printf("%d+%d=%d\n",A[l],k-A[l],k);
		}
		H[A[l]]++;
	}
}
