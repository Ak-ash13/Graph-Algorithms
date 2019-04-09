#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void randomArray(int arr[], int n)
{
	srand(time(0));
	for(int i = 0; i<n; i++)
	{
		arr[i] = rand();
	}
}

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
void max_heapify(int arr[], int n, int i)
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
void heapSortAsc(int arr[],int n)
{
	build_max_heap(arr,n);
	for(int i=n-1;i>=0;i--)
	{
		//printf("%d,",arr[0]);
		swap(&arr[0],&arr[i]);
		max_heapify(arr,i,0);
	}
}

void min_heapify(int arr[], int n, int i)
{

	int smallest;
	int l=left(i);
	int r=right(i);
	if(l<n && arr[l]<arr[i])
	{
		smallest=l;
	}
	else
	{
		smallest=i;
	}
	if(r<n && arr[r]<arr[smallest])
	{
		smallest=r;
	}
	if(i!=smallest)
	{
		swap(&arr[i],&arr[smallest]);
		max_heapify(arr,n,smallest);
	}
}
void build_min_heap(int arr[],int n)
{
	for(int i=(n/2)-1;i>=0;i--)
	{
		min_heapify(arr,n,i);
	}
}
void heapSortDesc(int arr[],int n)
{
	build_min_heap(arr,n);
	for(int i=n-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		min_heapify(arr,i,0);
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
	int n, choice; char ans = 'y';
	printf("Enter the number of elements?");
	scanf("%d",&n);

	int arr[n];
	clock_t start, end;
	do
	{
		//menu
		printf("\n	  || Max heap & priority queue menu ||\n");
		printf("\n 0. Quit \n1. generate random no array \n2. display \n3. sort ascending \n4. sort descending \n5. time complexity of sorting random data in ascending");
		printf("\n 6. time complexity of sorting in ascending of data already sorted in ascending");
		printf("\n 7. time complexity of sorting in ascending of data already sorted in descending");
		printf("\n 8. time complexity of sorting in ascending of data in all cases");
		printf("\n 9. extract largest element");
		printf("\n10. replace value at a node with a new node");
		printf("\n11. insert a new element");
		printf("\n12. delete an element");

		printf("\n\nEnter choice :");
		scanf("%d", &choice);
		switch(choice)
		{
			case 0: exit(1);
			case 1: randomArray(arr,n);
				   break;
			case 2: display(arr,n);
				   break;
			case 3: heapSortAsc(arr,n);
				   break;
			case 4: heapSortDesc(arr,n);
				   break;
			case 5: heapSortAsc(arr,n);
				   start = clock();
				   heapSortAsc(arr,n);
				   end = clock();
				   printf("\ntime: %lf", ((double)(start-end))/CLOCKS_PER_SEC);
				   break;

		}
		printf("\nContinue?(y/n) ");
		scanf(" %c", &ans);
	} while(ans == 'y' || ans == 'Y');
	// printf("\nDisplay before heapify\n");
	// display(arr,n);
	// printf("\n\n\n");
	// heapSort(arr,n);
	// //build_max_heap(arr,n);
	// printf("\nDisplay after heapSort\n");
	// display(arr,n);
	return 0;
}
