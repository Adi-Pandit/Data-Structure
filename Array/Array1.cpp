#include<iostream>

using namespace std;
template <class T>
class array
{
	private:
		T *A;
		int size;
		int length;
	
	public:
		array()
		{
			int size=10;
			int length=0;
			A=new T[size];
		}
		array(int sz)
		{
			int size=sz;
			int length=0;
			A=new T[size];
		}
		~array()
		{
			delete []A;
		}
		void Display();
		void Insert(int index,T x);
		T Delete(int index);
};

template <class T>
void array<T>::Display()
{
	for(int i=0;i<length;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
}

template<class T>
void array<T>::Insert(int index,T x)
{
	if(index>=0 && index<=length)
	{
		for(int i=length-1;i>index;i--)
		{
			A[i+1]=A[i];
		}
		A[index]=x;
		length++;
	}
	else
	{
		cout<<"Invalid index"<<endl;
	}
}

template<class T>
T array<T>::Delete(int index)
{
	T x;
	if(index>=0 && index<length)
	{
		x=A[index];	
		for(int i=index;i<length-1;i++)
		{
			A[i]=A[i+1];
		}
		length--;
		return x;
	}
	return -1;
}

int main()
{
	array<char> A(10);
	
	A.Insert(0,'a');
	A.Insert(1,'b');
	A.Insert(2,'c');
	
	A.Display();
	
	cout<<A.Delete(0)<<endl;
	A.Display();
}
