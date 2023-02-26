#include<stdio.h>

int fact(int n)
{
	if(n<=1)
		return 1;
	else
		return n*fact(n-1);
}
int C(int n,int r)
{
	if(r==0 || r==n)
		return 1;
	else
		return C(n-1,r-1)+C(n-1,r);
}

int iC(int n,int r)
{
	if(r==0 || r==n)
		return 1;
	else
		return fact(n)/(fact(n-r)*fact(r));	
}

int main()
{
	int r;
	r=iC(5,3);
	printf("%d",r);
}
