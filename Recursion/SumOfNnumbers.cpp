#include<stdio.h>

int sum(int n)
{
	if(n==0)
		return 0;
	else
		return n+sum(n-1);
}

int Isum(int n)
{
	int s=0,i;
	for(i=1;i<=n;i++)
	{
		s=s+i;
	}
	return s;
}

int main()
{
	int r;
	r=Isum(10);
	printf("%d",r);
}
