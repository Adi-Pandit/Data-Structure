#include<stdio.h>

long long Fact(int n)
{
	if(n==0)
		return 1;
	else
		return n*Fact(n-1);
}
int Pow(int x,int n)
{
	if(n==0)
		return 1;
	else
		return x*Pow(x,n-1);
}
float Taylor(int n,float x)
{
	if(n==0)
		return 1;
	else
		return ((float)Pow(x,n)/Fact(n))+Taylor(n-1,x);
}

float Taylor1(float x,int n)
{
	static float p=1,f=1;
	float r;
	if(n==0)
		return 1;
	else
	{
		r=Taylor1(x,n-1);
		p=p*x;
		f=f*n;
		return r+p/f;
	}
}

float Taylor2(float x,int n)
{
	static float s=1;
	if(n==0)
		return s;
	else
	{
		s=1+s*(x/n);
		return Taylor2(x,n-1);
	}
}

float ITaylor2(float x,int n)
{
	float s;
	for(;n>0;n--)
	{
		s=s*(x/n)+1;
	}
	return s;	
}	
int main()
{
	float r;
	r=ITaylor2(1,30);
	printf("%f",r);
	return 0;
}
