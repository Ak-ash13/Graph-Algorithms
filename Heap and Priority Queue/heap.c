#include<stdio.h>
#include<stdlib.h>
int left(int i)
{
	return (2*i)+1;
}
int right(int i)
{
	return (2*i)+2;
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;	
}
void max_heapify(int arr[],int n,int i)
{
    
	int largest;
	int l=left(i);
	int r=right(i);
	if(l<n && arr[l]>arr[i])
	{
		largest=l;
	}
	else
	{
		largest=i;
	}
	if(r<n && arr[r]>arr[largest])
	{
		largest=r;
	}	
	if(i!=largest)
	{
		swap(&arr[i],&arr[largest]);
		max_heapify(arr,n,largest);
	}
}
void build_max_heap(int arr[],int n)
{
	for(int i=(n/2)-1;i>=0;i--)
	{
		max_heapify(arr,n,i);
	}
}
void heapSort(int arr[],int n)
{
	build_max_heap(arr,n);
	for(int i=n-1;i>=0;i--)
	{
		//printf("%d,",arr[0]);
		swap(&arr[0],&arr[i]);
		max_heapify(arr,i,0);
	}
}
void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d,",arr[i]);
	}
}
int main()
{
	int n;
	printf("Enter the number of elements?");
	scanf("%d",&n);
	//int *arr=(int *)malloc(n*sizeof(int));
	int arr[n];
	printf("Emter the elements?");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nDisplay before heapify\n");
	display(arr,n);
	printf("\n\n\n");
	heapSort(arr,n);
	//build_max_heap(arr,n);
	printf("\nDisplay after heapSort\n");
	display(arr,n);
	return 0;
}
