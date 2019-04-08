#include<stdio.h>
void swap1(char *a,char *b)
{
    char temp=*a;
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
    printf("Enter the number of activities?");
    scanf("%d",&n);
    int s[n],f[n];
    char id[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the activity id?(A single character)");
        scanf(" %c",&id[i]);
        printf("For id %c\n",id[i]);
        printf("Enter the starting time?");
        scanf("%d",&s[i]);
        printf("Enter the finishing time?");
        scanf("%d",&f[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(f[j]>f[j+1])
            {
                swap(&f[j],&f[j+1]);
                swap(&s[j],&s[j+1]);
                swap1(&id[j],&id[j+1]);
            }
        }
    }
    char x[n];
    for(int i=0;i<n;i++)
    {
        x[i]=0;
    }
    int i=0;
    x[0]=id[0];
    int p=1;
    for(int m=1;m<n;m++)
    {
        if(s[m]>=f[i])
        {
            x[p]=id[m];
            i=m;
            p++;
        }
    }
    printf("\nActivity sequence:-\n(");
    for(i=0;i<p;i++)
    {
        if(x[i]!=0)
        {
            printf("%c,",x[i]);
        }
    }
    printf(")");
    return 0;
}