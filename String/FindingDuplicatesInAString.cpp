#include<stdio.h>

int main()
{
	char A[]="finding";
	int i,j,count;
	
	for(i=0;A[i]!='\0';i++)
	{
		if(A[i]!='0')
		{
			count=1;
			for(j=i+1;A[j]!='\0';j++)
			{
				if(A[i]==A[j])
				{
					count++;
					A[j]='0';
				}
			}
			if(count>1)
				printf("%c appears %d times\n",A[i],count);
		}
	}
}
