#include<stdio.h>

int F[100];

int fib(int n)
{
	if(n<=1)
		return n;
	else
		return fib(n-1)+fib(n-2);
}

int Ifib(int n)
{
	int s,i;
	int n1=0,n2=1;
	if(n<=1)
		return n;
	for(i=0;i<n-1;i++)
	{
		s=n1+n2;
		n1=n2;
		n2=s;
	}
	return s;
}

int fib1(int n)
{
	if(n<=1)
	{
		F[n]=n;
		return F[n];
	}
	else
	{
		if(F[n-1]==-1)
			F[n-1]=fib1(n-1);
		if(F[n-2]==-1)
			F[n-2]=fib1(n-2);
		return F[n-1]+F[n-2];
	}
}

int main()
{
	int i;
	for(i=0;i<100;i++)
	{
		F[i]=-1;
	}
	int r=fib1(10);
	printf("%d",r);
}
