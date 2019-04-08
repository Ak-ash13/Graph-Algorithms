// code all the four functions of priority queue using heap
// 1.Return Maximum
// 2.Extract Maximum
// 3.Change key of priority queue
// 4.Max heap insert
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int left(int i)
{
  return (2*i)+1;
}
int right(int i)
{
  return (2*i)+2;
}
int parent(int i)
{
  return (i/2)-1;
}
void swap(int *a, int *b)
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
  if(largest!=i)
  {
    swap(&arr[largest],&arr[i]);
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
int return_maximum(int arr[],int n)
{
  return arr[0];
}
int heap_extract_max(int arr[],int n)
{
  if(n<1)
  {
    printf("Error\n");
  }
  else
  {
    int max;
    max=arr[0];
    arr[0]=arr[n-1];
    n--;
    max_heapify(arr,n,0);
    return max;
  }
}
// void heap_change_key(int arr[],int n,int i,int key)
// {
//   arr[i]=key;
//   while(i>1 && arr[i]>)
//   max_heapify(arr,n,0);
// }
void heap_increase_key(int arr[],int n,int i,int key)
{
  if(key<=arr[i])
  {
    printf("Error: new value is lesser tghan the old");
  }
  else
  {
    arr[i]=key;
    while(i>0 && arr[i]>arr[parent(i)] )
    {
      swap(&arr[i],&arr[parent(i)]);
      i=parent(i);
    }
  }
  
}
void heap_insert(int arr[],int n,int key)
{
  if(n<1)
  {
    printf("Error");
  }
  else
  {
    arr[n]=INT_MIN; 
    heap_increase_key(arr,n+1,n-1,key);
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
  int n,pos,key;
  printf("Enter the number of elements?");
  scanf("%d",&n);
  int *arr=(int *)malloc(n*sizeof(int));
  printf("Enter the elements?");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  display(arr,n);
  printf("\nAfter max heapify:-\n");
  build_max_heap(arr,n);
  display(arr,n);
  printf("\nPriority queue functions:-\n");
  printf("1.Return maximum:-%d\n",return_maximum(arr,n));
  printf("2.Extract heap max:-%d\n",heap_extract_max(arr,n));
  printf("Array after extracting max\n");
  display(arr,n-1);
  printf("\nFor increase key:-\n");
  printf("Enter position and new value?");
  scanf("%d%d",&pos,&key);
  heap_increase_key(arr,n,pos,key);
  printf("New array\n");
  display(arr,n-1);
  printf("\nFor inserting a new value\n");
  printf("Enter value\n");
  scanf("%d",&key);
  heap_insert(arr,n,key);
  display(arr,n);
  return 0;
}
