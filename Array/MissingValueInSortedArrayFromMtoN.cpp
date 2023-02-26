#include<stdio.h>

struct array
{
	int A[10];
	int size;
	int length;
};

int main()
{
	struct array arr={{6,7,8,9,10,11,12,14,15},10,9};
	int i,diff;
	diff=arr.A[0];
	for(i=0;i<arr.length;i++)
	{
		if((arr.A[i]-i)!=diff)
		{
			printf("%d",i+diff);
			break;
		}
	}
}
