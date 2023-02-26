#include<iostream>

using namespace std;

class UpperTri
{
	private:
		int *A;
		int n;
	public:
		UpperTri()
		{
			n=2;
			A=new int[n*(n+1)/2];
		}
		UpperTri(int n)
		{
			this->n=n;
			A=new int[n*(n+1)/2];
		}
		~UpperTri()
		{
			delete []A;
		}
		void Set(int i,int j,int x);
		int Get(int i,int j);
		void Display();
		int GetDimension()
		{
			return n;
		}
};

void UpperTri::Set(int i,int j,int x)
{
	if(i<=j)
		A[j*(j-1)/2+i-1]=x;
}

int UpperTri::Get(int i,int j)
{
	if(i<=j)
		return A[j*(j-1)/2+i-1];
	else
		return 0;
}

void UpperTri::Display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i<=j)
				cout<<A[j*(j-1)/2+i-1]<<" ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	}
}

int main()
{
	int n;
	cout<<"Enter Dimension : ";
	cin>>n;
	
	UpperTri UT(n);
	int x;
	
	cout<<"Enter Element : "<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			UT.Set(i,j,x);
		}
	}
	
	cout<<UT.Get(1,1)<<endl;
	UT.Display();
}
