#include<stdio.h>

int main()
{
	char A[]="welcome";
	int i;
	for(i=0;A[i]!='\0';i++)
	{
		if(A[i]>=65&&A[i]<=90)
			A[i]+=32;
		else if(A[i]>='a'&&A[i]<='z')
			A[i]-=32;
	}
	printf("%s",A);
}
