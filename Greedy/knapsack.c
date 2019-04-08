#include<stdio.h>
#include<stdlib.h>
void swap1(float *a,float *b)
{
    float temp=*a;
    *a=*b;
    *b=temp;
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int n;
    printf("Enter the number of articles?");
    scanf("%d",&n);
    int item[n];
    float v[n],w[n],rate[n],capacity,x[n],u,profit=0;
    for(int i=0;i<n;i++)
    {
        item[i]=i+1;
        printf("For item %d\n",i+1);
        printf("Enter value?");
        scanf("%f",&v[i]);
        printf("Enter weight available?");
        scanf("%f",&w[i]);
        rate[i]=v[i]/w[i];
    }
    printf("Enter the capacity of the bag?");
    scanf("%f",&capacity);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(rate[j]<rate[j+1])
            {
                swap1(&rate[j],&rate[j+1]);
                swap1(&w[j],&w[j+1]);
                swap(&item[j],&item[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        x[i]=0;
    }
    u=capacity;
    for(int i=0;i<n;i++)
    {  
        if(w[i]<=u)
        {
            x[item[i]-1]=1;
            u=u-w[i];
        }
        else
        {
            x[item[i]-1]=u/w[i];
            u=0;
            break;
        }
        
    }
    printf("\nSolution Vector:-\n");
    for(int i=0;i<n;i++)
    {
        printf("%f,",x[i]);
    }
    for(int i=0;i<n;i++)
    {
        profit=profit+(x[i]*v[i]);
    }
    printf("\n\nTotal Profit=%f",profit);
    return 0;
}