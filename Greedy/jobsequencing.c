#include<stdio.h>
#include<stdlib.h>
void swap2(char *a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}
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
    printf("Enter the number of jobs?");
    scanf("%d",&n);
    char id[n];
    int deadline[n];
    float profit[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the job id?(A single character)");
        scanf(" %c",&id[i]);
        printf("For job id %c\n",id[i]);
        printf("Enter job deadline?");
        scanf("%d",&deadline[i]);
        printf("Enter profit?");
        scanf("%f",&profit[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(profit[j]<profit[j+1])
            {
                swap1(&profit[j],&profit[j+1]);
                swap(&deadline[j],&deadline[j+1]);
                swap2(&id[j],&id[j+1]);
            }
        }
    }
    printf("\nJob id:-\n");
    for(int i=0;i<n;i++)
    {
        printf("%c,",id[i]);
    }
    printf("\nJob Deadline:-\n");
    for(int i=0;i<n;i++)
    {
        printf("%d,",deadline[i]);
    }
    printf("\nJob Profit:-\n");
    for(int i=0;i<n;i++)
    {
        printf("%f,",profit[i]);
    }
    int max=deadline[0];
    for(int i=1;i<n;i++)
    {   
        if(deadline[i]>max)
        {
            max=deadline[i];
        }
    }
    printf("\nMaximum deadline:-%d",max);
    int pos;
    char x[max];
    for(int i=0;i<max;i++)
    {
        x[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        pos=deadline[i]-1;
        while(x[pos]!=0)
        {
            pos--;
        }
        x[pos]=id[i];
    }
    printf("\nJob sequence:-\n");
    for(int i=0;i<max;i++)
    {
        if(x[i]!=0)
        {
            printf("%c,",x[i]);
        }
    }
    return 0;
}