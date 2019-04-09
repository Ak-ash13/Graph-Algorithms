#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int n;
  
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
   	*b = temp; 
}
	void Print_array(int arr[])
		{
			for(int i=0;i<n;i++)
			{
			printf("%d\t",arr[i]);
			}
		}
	void max_heapify(int i,int arr[])
	{
		int largest=i;
		int l=2*i+1;
		int r=2*i+2;
		if(l<n && arr[l]>arr[largest])
		largest=l;
		if(r<n && arr[r]>arr[largest])
		largest=r;
		if(largest!=i)
		{
			int temp=arr[largest];
			arr[largest]=arr[i];
			arr[i]=temp;
			max_heapify(largest,arr);
		}
	}
	
	void min_heapify(int i,int arr[])
	{
		int largest=i;
		int l=2*i+1;
		int r=2*i+2;
		if(l<n && arr[l]>arr[largest])
		largest=l;
		if(r<n && arr[r]>arr[largest])
		largest=r;
		if(largest!=i)
		{
			int temp=arr[largest];
			arr[largest]=arr[i];
			arr[i]=temp;
			min_heapify(largest,arr);
		}
	}
	
		void build_maxheap(int arr[])
		{
			for(int i=(n/2)-1;i>=0;i--)
			{	
				max_heapify(i,arr);
			}
			//print_array(arr,n);
		}
		
		void build_minheap(int arr[])
		{
			for(int i=(n/2)-1;i>=0;i--)
			{	
				min_heapify(i,arr);
			}
			//print_array(arr,n);
		}
		int Extract_Max(int arr[])
		{
		swap(&arr[0],&arr[n-1]);	
		int max=arr[n-1];
		
		//printf("%d",max);
		n=n-1;
		printf("\nAfter first extract %d\n:",max);
		//Print_array(arr,n);
		
		max_heapify(0,arr);
		printf("]nAgain after heapify");
		Print_array(arr);
		return max;
		}
		
		int Extract_Min(int arr[])
		{
		//swap(&arr[0],&arr[n-1]);	
		int max=arr[n-1];
		
		//printf("%d",max);
		n=n-1;
		printf("\nAfter first extract %d\n:",max);
		//Print_array(arr,n);
		
		max_heapify(0,arr);
		printf("]nAgain after heapify");
		Print_array(arr);
		return max;
		}
	
	
	void largest_3(int arr[],int k)
	{
		for(int i=0;i<=k-1;i++)
		{	
			int s;
			s=Extract_Min(arr);
			printf("\n%d larggest elements is :  %d\n",i+1,s);
		}
	}
	
	void largest_4(int arr[],int k)
	{
		for(int i=0;i<=k-1;i++)
		{	
			int s;
			s=Extract_Max(arr);
			printf("\n%d largest elements is :  %d\n",i+1,s);
		}
	}
				
		void largest_1(int arr[],int n,int k)
		{	
			
			for(int i=0;i<n;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(arr[i]>arr[j])
					{
						int temp=arr[j];
						arr[j]=arr[i];
						arr[i]=temp;
					}
				}
				if(i==k-1)
				{
					printf("\nThe %dth largest elements is %d",k,arr[i]);
					break;
				}
			}
		}
				
		

// order of (n+log n) using quick sort//

		int partition(int arr[], int l, int r); 
  

int largest_2(int arr[], int l, int r, int k) 
{ 
    
    if (k > 0 && k <= r - l + 1) 
    { 
       
        int pos = partition(arr, l, r); 
  
        
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  
            return largest_2(arr, l, pos-1, k); 
  			
        return largest_2(arr, pos+1, r, k-pos+l-1); 
    } 
  
    
    return INT_MAX; 
} 

  
int partition(int arr[], int l, int r) 
{ 
    int x = arr[r], i = l; 
    for (int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 

void main()
{
	printf("\nEnter the length of array");
	int k;
	scanf("%d",&n);
	int p=n;
	
	printf("\nEnter the elements of array:");
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("\nEnter the kth largest element to be found:?");
	scanf("%d",&k);
	int option,t;
	char ch='y';
	do{
		
		printf("\nMenu");
		printf("\n1. Time complexity  O(kn)....\n2. time complexity....O(klogn)....\n3. Time complexity(Using Max-Heap) ...O(n-k)*logk.....\n4.Time Complexity(Using Min-heap).....O(n+klogn)\n");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1: largest_1(arr,p,k);
					break;
					
			case 2: t=largest_2(arr,0,p-1,k);
			printf("\n %dth Largest elements is : %d",k,t); 
					break;
					
			case 3: printf("\n Using Max-Heap");
					build_maxheap(arr);
					printf("\nAfter heapfiy");
					
					Print_array(arr);
					//printf("The %dth largest elements is:",k);
					printf("\nEntering into function");
					largest_3(arr,k);
					break;
			case 4: printf("\nUsing min Heap\n");
					build_minheap(arr);
					printf("\nAfter heapfiy");
					
					Print_array(arr);
					//printf("The %dth largest elements is:",k);
					printf("\nEntering into function");
					largest_4(arr,k);
					break;
					
					
			
		}
		
		printf("\n Do you want to continue Press y or n?:");
		scanf(" %c",&ch);
		}while(ch=='y');
}
		
					
	
	
