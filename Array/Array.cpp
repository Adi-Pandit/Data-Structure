#include<stdio.h>
#include<stdlib.h>
struct array
{
	int *A;
	int size;
	int length;
};

void display(struct array arr)
{
	int i;
	for(i=0;i<arr.length;i++)
	{
		printf("%d ",arr.A[i]);
	}
}

void display1(struct array *arr)
{
	int i;
	for(i=0;i<arr->length;i++)
	{
		printf("%d ",arr->A[i]);
	}
	
}

void append(struct array *arr,int x)
{
	if(arr->length<arr->size)
		arr->A[arr->length++]=x;
}

void insert(struct array *arr,int index,int x)
{
	int i;
	if(index>=0 && index<=arr->length)
	{
		for(i=arr->length;i>index;i--)
			arr->A[i]=arr->A[i-1];
		arr->A[index]=x;
		arr->length++;
	}
}

int Delete(struct array *arr,int index)
{
	int x,i;
	if(index>=0 && index<arr->length)
	{
		x=arr->A[index];
		for(i=index;i<arr->length-1;i++)
		{
			arr->A[i]=arr->A[i+1];
		}
		arr->length--;
		return x;
	}
	return 0;
}

int LinearSearch(struct array arr,int key)
{
	int i;
	for(i=0;i<arr.length;i++)
	{
		if(arr.A[i]==key)
			return i;
	}
	return -1;
}

void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

int TLinearSearch(struct array *arr,int key)
{
	int i;
	for(i=0;i<arr->length;i++)
	{
		if(arr->A[i]==key)
		{
			swap(&arr->A[i],&arr->A[i-1]);
			return i;
		}
	}
	return -1;
}

int MTHLinearSearch(struct array *arr,int key)
{
	int i;
	for(i=0;i<arr->length;i++)
	{
		if(arr->A[i]==key)
		{
			swap(&arr->A[i],&arr->A[0]);
			return i;
		}
	}
	return -1;
}

int BinarySearch(struct array arr,int key)
{
	int l,h,mid;
	l=0;
	h=arr.length-1;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(key==arr.A[mid])
			return mid;
		else if(key<arr.A[mid])
			h=mid-1;
		else
			l=mid+1;
	}
	return -1;
}

int BinarySearch1(struct array *arr,int key)
{
	int l,h,mid;
	l=0;
	h=arr->length-1;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(key==arr->A[mid])
			return mid;
		else if(key<arr->A[mid])
			h=mid-1;
		else
			l=mid+1;
	}
	return -1;
}

int RBinarySearch(struct array arr,int l,int h,int key)
{
	int mid;
	if(l<=h)
	{
		mid=(l+h)/2;
		if(key==arr.A[mid])
			return mid;
		else if(key<arr.A[mid])
			return RBinarySearch(arr,l,mid-1,key);
		else
			return RBinarySearch(arr,mid+1,h,key);
	}
	return -1;
}

int Get(struct array arr,int index)
{
	if(index>=0 && index<arr.length)
		return arr.A[index];
	return -1;
}

void Set(struct array *arr,int index,int x)
{
	if(index>=0 && index<arr->length)
		arr->A[index]=x;
	else
		printf("Invalid Index\n");
}

int Max(struct array arr)
{
	int max=arr.A[0];
	int i;
	for(i=0;i<arr.length;i++)
	{
		if(arr.A[i]>max)
			max=arr.A[i];
	}
	return max;
}

int Min(struct array arr)
{
	int min=arr.A[0];
	int i;
	for(i=0;i<arr.length;i++)
	{
		if(arr.A[i]<min)
			min=arr.A[i];
	}
	return min;
}

int Sum(struct array arr)
{
	int Total=0;
	int i;
	for(i=0;i<arr.length;i++)
		Total=Total+arr.A[i];
	return Total;
}

int RSum(struct array arr, int n)
{
	if(n<0)
		return 0;
	else
		return arr.A[n]+RSum(arr,n-1);
}

int Avg(struct array arr)
{
	return (float)(Sum(arr)/arr.length);
}

void Reverse(struct array *arr)
{
	int *B;
	int i,j;
	B=(int *)malloc(arr->length*sizeof(int));
	for(i=arr->length-1,j=0;i>=0;i--,j++)
		B[j]=arr->A[i];
	for(i=0;i<arr->length;i++)
		arr->A[i]=B[i];
}

void Reverse1(struct array *arr)
{
	int i,j;
	for(i=0,j=arr->length-1;i<j;i++,j--)
		swap(&arr->A[i],&arr->A[j]);
}

void LeftShift(struct array *arr, int n)
{
	int i,temp;
	while(n>0)
	{
		temp=arr->A[0];
		for(i=1;i<arr->length;i++)
			arr->A[i-1]=arr->A[i];
		arr->A[arr->length-1]=0;
		n--;
	}
}

void LeftRotation(struct array *arr, int n)
{
	int i,temp;
	while(n>0)
	{
		temp=arr->A[0];
		for(i=1;i<arr->length;i++)
			arr->A[i-1]=arr->A[i];
		arr->A[arr->length-1]=temp;
		n--;
	}
}

void RightShift(struct array *arr, int n)
{
	int i,temp;
	while(n>0)
	{
		temp=arr->A[arr->length-1];
		for(i=arr->length-2;i>=0;i--)
			arr->A[i+1]=arr->A[i];
		arr->A[0]=0;
		n--;
	}
}

void RightRotation(struct array *arr, int n)
{
	int i,temp;
	while(n>0)
	{
		temp=arr->A[arr->length-1];
		for(i=arr->length-2;i>=0;i--)
			arr->A[i+1]=arr->A[i];
		arr->A[0]=temp;
		n--;
	}
}

void InsertSorted(struct array *arr, int x)
{
	int i;
	i=arr->length-1;
	if(arr->length==arr->size)
		return;
	while(arr->A[i]>x)
	{
		arr->A[i+1]=arr->A[i];
		i--;
	}
	arr->A[i+1]=x;
	arr->length++;
}

int isSorted(struct array arr)
{
	int i;
	for(i=0;i<arr.length-1;i++)
	{
		if(arr.A[i]>arr.A[i+1])
			return 0;
	}
	return 1;
}

void Rearrange(struct array *arr)
{
	int i,j;
	i=0;
	j=arr->length-1;
	while(i<j)
	{
		while(arr->A[i]<0)
		{
			i++;
		}
		while(arr->A[j]>=0)
		{
			j--;
		}
		if(i<j)
		{
			swap(&arr->A[i],&arr->A[j]);
		}
	}
}

struct array* Merge(struct array *arr1,struct array *arr2)
{
	int i,j,k;
	i=j=k=0;
	
	struct array *arr3;
	arr3 = (struct array *)malloc(sizeof(struct array));
	
	while(i<arr1->length && j<arr2->length)
	{
		if(arr1->A[i]<arr2->A[j])
			arr3->A[k++]=arr1->A[i++];
		else
			arr3->A[k++]=arr2->A[j++];
	}
	for(;i<arr1->length;i++)
		arr3->A[k++]=arr1->A[i];
	for(;j<arr2->length;j++)
		arr3->A[k++]=arr2->A[j];
	arr3->length=arr1->length+arr2->length;
	arr3->size=10;
	return arr3;
}



struct array* Union(struct array *arr1,struct array *arr2)
{
	int i,j,k;
	i=j=k=0;
	
	struct array *arr3;
	arr3 = (struct array *)malloc(sizeof(struct array));
	
	while(i<arr1->length && j<arr2->length)
	{
		if(arr1->A[i]<arr2->A[j])
			arr3->A[k++]=arr1->A[i++];
		else if(arr1->A[i]>arr2->A[j])
			arr3->A[k++]=arr2->A[j++];
		else
		{
			arr3->A[k++]=arr1->A[i++];
			j++;
		}
	}
	for(;i<arr1->length;i++)
		arr3->A[k++]=arr1->A[i];
	for(;j<arr2->length;j++)
		arr3->A[k++]=arr2->A[j];
	arr3->length=k;
	arr3->size=10;
	return arr3;
}

bool elementPresentOrNot(int arr[],int l,int x)
{
	int i;
	for(i=0;i<l;i++)
	{
		if(arr[i]==x)
			return true;
	}
	return false;
}

struct array* Union1(struct array *arr1,struct array *arr2)
{
	int i,j,k;
	i=j=k=0;
	
	struct array *arr3;
	arr3 = (struct array *)malloc(sizeof(struct array));
	
	while(i<arr1->length)
	{
		arr3->A[k++]=arr1->A[i++];
	}
	while(j<arr2->length)
	{
		if(!elementPresentOrNot(arr3->A,arr1->length,arr2->A[j]))
			arr3->A[k++]=arr2->A[j++];
		else
			j++;
	}
	arr3->length=k;
	arr3->size=10;
	return arr3;
}

struct array* Intersection(struct array *arr1,struct array *arr2)
{
	int i,j,k;
	i=j=k=0;
	
	struct array *arr3;
	arr3 = (struct array *)malloc(sizeof(struct array));
	
	while(i<arr1->length && j<arr2->length)
	{
		if(arr1->A[i]<arr2->A[j])
			i++;
		else if(arr1->A[i]>arr2->A[j])
			j++;
		else
		{
			arr3->A[k++]=arr1->A[i++];
			j++;
		}
	}
	arr3->length=k;
	arr3->size=10;
	return arr3;
}

struct array* Intersection1(struct array *arr1,struct array *arr2)
{
	int i,k;
	i=k=0;
	
	struct array *arr3;
	arr3=(struct array *)malloc(sizeof(struct array));
	while(i<arr1->length)
	{
		if(elementPresentOrNot(arr2->A,arr2->length,arr1->A[i]))
			arr3->A[k++]=arr1->A[i++];
		else
			i++;
	}
	arr3->length=k;
	arr3->size=10;
	return arr3;
}

struct array* Difference(struct array *arr1,struct array *arr2)
{
	int i,j,k;
	i=j=k=0;
	
	struct array *arr3;
	arr3 = (struct array *)malloc(sizeof(struct array));
	
	while(i<arr1->length && j<arr2->length)
	{
		if(arr1->A[i]<arr2->A[j])
			arr3->A[k++]=arr1->A[i++];
		else if(arr1->A[i]>arr2->A[j])
			j++;
		else
		{
			i++;
			j++;
		}
	}
	for(;i<arr1->length;i++)
		arr3->A[k++]=arr1->A[i];
	arr3->length=k;
	arr3->size=10;
	return arr3;
}

struct array* Difference1(struct array *arr1,struct array *arr2)
{
	int i,k;
	i=k=0;
	
	struct array *arr3;
	arr3=(struct array *)malloc(sizeof(struct array));
	
	while(i<arr1->length)
	{
		if(!elementPresentOrNot(arr2->A,arr2->length,arr1->A[i]))
			arr3->A[k++]=arr1->A[i++];
		else
			i++;
	}
	arr3->length=k;
	arr3->size=10;
	return arr3;
}

int main()
{
	struct array arr;
	int x,index;
	printf("Enter size : ");
	scanf("%d",&arr.size);
	arr.A=(int *)malloc(arr.size*sizeof(int));
	int ch;
	do
	{
		printf("\n1.Insert\n2.Delete\n3.Search\n4.Sum\n5.Display\n6.Exit\n");
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter element and position : ");
				scanf("%d %d",&x,&index);
				insert(&arr,index,x);
				break;
			case 2:printf("\nEnter index : ");
				scanf("%d",&index);
				x=Delete(&arr,index);
				printf("\nDeleted element : %d",x);
				break;
			case 3:printf("\nEnter element to search : ");
				scanf("%d",&x);
				index=LinearSearch(arr,x);
				printf("\nElement present at %d",index);
				break;
			case 4:printf("\nSum : %d",Sum(arr));
				break;
			case 5:display(arr);
				break;
		}
	}while(ch<6);
	
}

