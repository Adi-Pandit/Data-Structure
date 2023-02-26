#include<stdio.h>

int main()
{
	int A[10]={5,8,3,9,6,2,10,7,-1,4};
	int max,min,i;
	max=A[0];
	min=A[0];
	
	for(i=0;i<10;i++)
	{
		if(A[i]<min)
			min=A[i];
		else if(A[i]>max)
			max=A[i];			
	}
	printf("min=%d max=%d",min,max);
}
