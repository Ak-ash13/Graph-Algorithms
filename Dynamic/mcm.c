#include<stdio.h>
#include<stdlib.h>
struct result
{
    int mvalue;
    int kvalue;
};
struct result minimum(int temp1[],int temp2[],int n)
{
    int min=temp1[0];
    int k=temp2[0];
    for(int i=1;i<n;i++)
    {
        if(temp1[i]<min)
        {
            min=temp1[i];
            k=temp2[i];
        }
    }
    struct result res;
    res.mvalue=min;
    res.kvalue=k;
    return res;
}
void print_optimal_parenthesis(int i,int j,int n,int s[n][n])
{
    if(i==j)
    {
        printf("A%d,",i+1);
        return;
    }
    else
    {
        printf("(");
        print_optimal_parenthesis(i,s[i][j],n,s);
        print_optimal_parenthesis(s[i][j]+1,j,n,s);
        printf(")");
    }
}
void matrix_chain_multiplication(int p[],int n)
{
    int m[n][n],s[n][n];
    int k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            m[i][j]=0;
            s[i][j]=0;
        }
    }
    for(int z=1;z<n;z++)
    {
        for(int i=0;i<n-z;i++)
        {
            int j=i+z;
            int *temp1=(int *)malloc((j-i)*sizeof(int));
            int *temp2=(int *)malloc((j-i)*sizeof(int));
            int x=0;
            for(int k=i;k<j;k++)
            {
                temp1[x]=m[i][k]+m[k+1][j]+(p[i]*p[k+1]*p[j+1]);
                temp2[x]=k;
                x++;
            }
            struct result res=minimum(temp1,temp2,j-i);
            m[i][j]=res.mvalue;
            s[i][j]=res.kvalue;
        }
    }
    printf("M matrix:-\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    printf("\nTotal Cost of matrix multiplication=%d\n",m[0][n-1]);
    printf("\nS matrix:-\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }
    print_optimal_parenthesis(0,n-1,n,s);
}
int main()
{
    int n;
    printf("Enter the number of matrices?");
    scanf("%d",&n);
    int p[n+1];
    printf("Enter the sequence of dimensions?");
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    matrix_chain_multiplication(p,n);
    return 0;
}