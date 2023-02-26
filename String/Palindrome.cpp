#include<stdio.h>

int main()
{
	char A[]="madam";
	char B[6];
	int i,j;
	
	for(j=0;A[j]!='\0';j++)
	{
	}
	j=j-1;
	for(i=0;j>=0;i++,j--)
	{
		B[i]=A[j];
	}
	B[i]='\0';
	
	for(i=0,j=0;A[i]!='\0' && B[j]!='\0';i++,j++)
	{
		if(A[i]!=B[j])
			break;
	}
	if(A[i]==B[j])
		printf("Palindrome");
	else
		printf("Not palindrome");
}
