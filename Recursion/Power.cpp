#include<stdio.h>

int pow(int m,int n)
{
	if(n==0)
		return 1;
	else
		return m*pow(m,n-1);
}

int Ipow(int m,int n)
{
	int s=1,i;
	for(i=1;i<=n;i++)
		s=s*m;
	return s;
}

int pow1(int m,int n)
{
	if(n==0)
		return 0;
	if(n%2==0)
		return pow(m*m,n/2);
	else
		return m*pow(m*m,(n-1)/2);
}

int main()
{
	int r;
	r=pow1(4,3);
	printf("%d",r);
	return 0;
}
