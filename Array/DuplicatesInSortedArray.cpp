#include<stdio.h>

int main()
{
	int A[10]={3,6,8,8,10,12,15,15,20};
	int lastDuplicate=0,i;
	for(i=0;i<9;i++)
	{
		if(A[i]==A[i+1] && A[i]!=lastDuplicate)
		{
			printf("%d\n",A[i]);
			lastDuplicate=A[i];
		}
	}
}
