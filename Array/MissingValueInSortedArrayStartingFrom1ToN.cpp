#include<stdio.h>

struct array 
{
	int A[10];
	int size;
	int length;
};

int main()
{
	struct array arr={{1,2,3,4,5,7,8,9},10,8};
	int s,i,sum=0;
	for(i=0;i<arr.length;i++)
	{
		sum=sum+arr.A[i];
	}
	s=(arr.A[arr.length-1])*(arr.A[arr.length-1]+1)/2;
	printf("%d",s-sum);
}

