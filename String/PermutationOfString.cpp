#include<stdio.h>

void Perm(char S[],int k)
{
	static int A[10]={0};
	static char Res[10];
	int i;
	if(S[k]=='\0')
	{
		Res[k]='\0';
		printf("%s\n",Res);	
	}
	else
	{
		for(i=0;S[i]!='\0';i++)
		{
			if(A[i]==0)
			{
				Res[k]=S[i];
				A[i]=1;
				Perm(S,k+1);
				A[i]=0;
			}
		}
	}
}

int main()
{
	char S[]="AB";
	Perm(S,0);
}
