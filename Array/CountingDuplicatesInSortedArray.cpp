#include<stdio.h>

int main()
{
	int A[10]={3,6,8,8,10,12,15,15,15,20};
	int i,j;
	
	for(i=0;i<9;i++)
	{
		if(A[i]==A[i+1])
		{
			j=i+1;
			while(A[i]==A[j])
				j++;
			printf("%d appears %d times\n",A[i],j-i);
			i=j-1;
		}
	}
}
