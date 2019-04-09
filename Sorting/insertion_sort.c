#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void gen(int* ar,int n)
{
	for(int a=0;a<n;a++)
	{
		*ar=rand()%10;
		ar++;
	}
}
void display(int* ar, int n)
{
	for(int a=0;a<n;a++)
	{
		printf("%d, ",*ar);
		ar++;
	}
	printf("\n");
}
void insertionA(int* ar, int n)
{
	int i,j,key;
	for(j=1;j<n;j++)
	{
		key=*(ar+j);
		i=j-1;
		while(i>-1 && *(ar+i)>key)
		{
			*(ar+i+1)=*(ar+i);
			i--;
		}
		*(ar+i+1)=key;
	}
}
void insertionD(int* ar, int n)
{
	int i,j,key;
	for(j=1;j<n;j++)
	{
		key=*(ar+j);
		i=j-1;
		while(i>-1 && *(ar+i)<key)
		{
			*(ar+i+1)=*(ar+i);
			i--;
		}
		*(ar+i+1)=key;
	}
}
void bestCase(int n)
{
	int *arr=(int *)malloc(n*sizeof(int));
	gen(arr,n);
	insertionA(arr,n);
	clock_t t;
	t=clock();
	insertionA(arr,n);
	t=clock()-t;
	//display(arr,n);
	double time_taken=((double)t/CLOCKS_PER_SEC);
	printf("%f",time_taken);
}
void worstCase(int n)
{
	int *arr=(int *)malloc(n*sizeof(int));
	gen(arr,n);
	insertionD(arr,n);
	clock_t t;
	t=clock();
	insertionA(arr,n);
	t=clock()-t;
	//display(arr,n);
	double time_taken=((double)t/CLOCKS_PER_SEC);
	printf("%f",time_taken);
}
void avgCase(int n)
{
	int *arr=(int *)malloc(n*sizeof(int));
	gen(arr,n);
	clock_t t;
	t=clock();
	insertionA(arr,n);
	t=clock()-t;
	//display(arr,n);
	double time_taken=((double)t/CLOCKS_PER_SEC);
	printf("%f",time_taken);
}
void tabularCase()
{
	int n;
	printf("\nS.no.\tn\tBestCase\tWorstCase\tAverageCase\n");
	for(int a=1;a<=10;a++)
	{
		printf("%d\t",a);
		scanf("%d",&n);
		printf("\t\t");
		bestCase(n);
		printf("\t");
		worstCase(n);
		printf("\t");
		avgCase(n);
		printf("\n");
	}
}

int main()
{
	int n,c;
	printf("Enter number of terms: ");
	scanf("%d",&n);
	int *arr=(int *)malloc(n*sizeof(int));
	while(1)
	{
		printf("\n0.Quit\n1.Generate n random numbers and store in array\n2.Display\n3.Arrange in ascending order\n4.Arrange in descending order.\n\n5.Best Case time\n6.Worst Case time\n7.Average Case time\n\n8.Tabular Data\n");
		scanf("%d",&c);
		switch(c)
		{
			case 0:{ printf("\nThanks for using this service.\n"); return 0;}
			case 1: gen(arr,n); break;
			case 2: display(arr,n);break;
			case 3: insertionA(arr,n);break;
			case 4: insertionD(arr,n);break;
			case 5: bestCase(n);break;
			case 6: worstCase(n);break;
			case 7: avgCase(n);break;
			case 8: tabularCase();break;
		}
		
	}
}
