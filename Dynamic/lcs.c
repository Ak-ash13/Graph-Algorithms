#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print_lcs(int i,int j,char x[],int l2,int l1,int seq[l2][l1])
{
    if(i==-1 || j==-1)
    {
        return;
    }
    else
    {
        if(seq[i][j]==0)
        {
            print_lcs(i-1,j-1,x,l2,l1,seq);
            printf("%c",x[j]);
        }
        else if(seq[i][j]==1)
        {
            print_lcs(i-1,j,x,l2,l1,seq);
        }
        else
        {
            print_lcs(i,j-1,x,l2,l1,seq);
        }
    }
    
}
void lcs(char x[],char y[])
{
    int l1=strlen(x);
    int l2=strlen(y);
    int m[l2+1][l1+1];
    int seq[l2][l1];
    for(int i=0;i<=l1;i++)
    {
        m[0][i]=0;
    }
    for(int j=0;j<=l2;j++)
    {
        m[j][0]=0;
    }
    int i=1,j=1;
    for(int p=0;p<l2;p++)
    {
        for(int q=0;q<l1;q++)
        {
            if(x[q]==y[p])
            {
                m[i][j]=m[i-1][j-1]+1;
                seq[i-1][j-1]=0;
            }
            else
            {
                if(m[i-1][j]>=m[i][j-1])
                {
                    m[i][j]=m[i-1][j];
                    seq[i-1][j-1]=1;
                }
                else
                {
                    m[i][j]=m[i][j-1];
                    seq[i-1][j-1]=2;
                }
            }
            j++;
        }
        i++;
        j=1;
    }
    printf("\n m Matrix\n");
    for(int p=0;p<=l2;p++)
    {
        for(int q=0;q<=l1;q++)
        {
            printf("%d ",m[p][q]);
        }
        printf("\n");
    }
    printf("Sequence matrix:-\n");
    for(int p=0;p<l2;p++)
    {
        for(int q=0;q<l1;q++)
        {
            printf("%d ",seq[p][q]);
        }
        printf("\n");
    }
    printf("length of largest subsequence=%d\n",m[l2][l1]);
    print_lcs(l2-1,l1-1,x,l2,l1,seq);
}
int main()
{
    char x[999],y[999];
    printf("Enter first sequence?");
    scanf("%s",x);
    printf("Enter second sequence?");
    scanf("%s",y);
    printf("First sequence:-%s\n",x);
    printf("Second sequence:-%s\n",y);
    lcs(x,y);
}
