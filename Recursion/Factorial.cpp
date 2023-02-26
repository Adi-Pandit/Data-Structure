#include<stdio.h>

int fact(int n)
{
	if(n==0 || n==1)
		return 1;
	else
		return n*fact(n-1);
}

int Ifact(int n)
{
	int s=1,i;
	if(n==0)
		s=1;
	else
	{
		for(i=1;i<=n;i++)
		{
			s=s*i;
		}
	}
	return s;
}
int main()
{
	int r;
	r=Ifact(5);
	printf("%d",r);
}
