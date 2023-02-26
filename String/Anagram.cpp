#include<stdio.h>

int main()
{
	char A[]="Verbose";
	char B[]="Observe";
	int i,j,H[26]={0};
	for(i=0;A[i]!='\0';i++)
	{
	}
	for(j=0;B[j]!='\0';j++)
	{
	}
	if(i==j)
	{
		for(i=0;A[i]!='\0';i++)
		{
			H[A[i]-97]+=1;
		}
		for(i=0;B[i]='\0';i++)
		{
			H[B[i]-97]-=1;
			if(H[B[i]-97]<0)
			{
				printf("Not anagram");
				break;
			}
		}
		if(B[i]=='\0')
			printf("Anagram");
	}
	else
		printf("Not anagram");
}
