#include<stdio.h>

struct array
{
	int A[12];
	int size;
	int length;
};

int main()
{
	struct array arr={{4,5,6,9,10,11,13,14,15},12,9};
	int i,diff;
	diff=arr.A[0];
	for(i=0;i<arr.length;i++)
	{
		if((arr.A[i]-i)!=diff)
		{
			while((arr.A[i]-i)>diff)
			{
				printf("%d ",i+diff);
				diff++;
			}
		}
	}
}
