#include<stdio.h>

int main()
{
	char A[]="madam";
	int i,j;
	
	for(j=0;A[j]!='\0';j++)
	{
	}
	j=j-1;
	for(i=0;i<j;i++,j--)
	{
		if(A[i]!=A[j])
			break;
	}
	if(A[i]==A[j])
		printf("Palindrome");
	else
		printf("Not Palindrome");
}
