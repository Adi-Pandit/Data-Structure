#include<stdio.h>

int main()
{
	char A[]="finding";
	long int H=0,X=0;
	int i;
	
	for(i=0;A[i]!='\0';i++)
	{
		X=1;
		X=X<<(A[i]-97);
		if((X&H)>0)
			printf("%c\n",A[i]);
		else
			H=X|H;
	}
}
