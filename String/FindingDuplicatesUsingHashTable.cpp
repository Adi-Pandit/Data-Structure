#include<stdio.h>

int main()
{
	char A[]="aditya";
	int HL[26],HU[26];
	int i;
	for(i=0;i<26;i++)
	{
		HU[i]=HL[i]=0;
	}
	for(i=0;A[i]!='\0';i++)
	{
		if(A[i]>=97 && A[i]<=122)
		{
			HL[A[i]-97]+=1;
		}
		else if(A[i]>=65 && A[i]<=90)
		{
			HU[A[i]-65]+=1;
		}
	}
	for(i=0;i<26;i++)
	{
		if(HL[i]>1)
			printf("%c appears %d times\n",i+97,HL[i]);
		if(HU[i]>1)
			printf("%c appears %d times\n",i+65,HU[i]);
	}
}
