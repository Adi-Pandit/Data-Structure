#include<stdio.h>

void swap(char *a,char *b)
{
	char t;
	t=*a;
	*a=*b;
	*b=t;
}

void Perm(char S[],int l,int h)
{
	static int n=0;
	int i;
	if(l==h)
		printf("%s %d\n",S,++n);
	else
	{
		for(i=l;i<=h;i++)
		{
			swap(&S[l],&S[i]);
			Perm(S,l+1,h);
			swap(&S[l],&S[i]);
		}
	}
}

int main()
{
	char S[]="ABC";
	int i;
	for(i=0;S[i]!='\0';i++)
	{
	}
	Perm(S,0,i-1);
}
