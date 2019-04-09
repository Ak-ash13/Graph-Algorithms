#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void matrixMultiplication(int n,int a[n][n],int b[n][n],int c[n][n])
{
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        c[i][j]=0;
                        for(int k=0;k<n;k++)
                        {
                                c[i][j]+=(a[i][k]*b[k][j]);
                        }
                }
        }
}
void strassen(int n,int a[n][n],int b[n][n],int c[n][n])
{
       int m1= (a[0][0] + a[1][1])*(b[0][0]+b[1][1]);
        int m2= (a[1][0]+a[1][1])*b[0][0];
        int m3= a[0][0]*(b[0][1]-b[1][1]);
        int m4= a[1][1]*(b[1][0]-b[0][0]);
        int m5= (a[0][0]+a[0][1])*b[1][1];
        int m6= (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
        int m7= (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);

        c[0][0]=m1+m4-m5+m7;
        c[0][1]=m3+m5;
        c[1][0]=m2+m4;
        c[1][1]=m1-m2+m3+m6;

}
// int divide_matrix(int n,int r1,int r1mid,int c1,int cmid,int a[n][n],int r2,int r2mid,int c2,int c2mid, int b[n][n],int c[n][n])
// {
//         if(n<=2)
//         {
//                 // calculate
//                 for(int i=r1;i<n;i++)
//                 {
//                         for(int j=c1;j<n;j++)
//                         {
//                                 c[i][j]=0;
//                                 for(int k=r1;k<n;k++)
//                                 {
//                                         c[i][j]+=(a[i][k]*b[k][j]);
//                                 }
//                         }
//                 }
//         }
//         else
//         {
//                 // recursively call the function
//                 divide_matrix(n/2,0,n/2,0,n/2,a,0,n/2,0,n/2,b,c)+divide_matrix(n/2,0,n/2,n/2,n,a,n/2,n,0,n/2,b,c);
//                 divide_matrix(n/2,0,n/2,0,n/2,a,n/2,n,0,n/2,b,c)+divide_matrix(n/2,0,n/2,n/2,n,a,n/2,n,n/2,n,b,c);
//                 divide_matrix(n/2,n/2,n,0,n/2,a,0,n/2,0,n/2,b,c)+divide_matrix(n/2,n/2,n,n/2,n, a,n/2,n,0,n/2,b,c);
//                 divide_matrix(n/2,n/2,n,0,n/2,a,n/2,n,0,n/2,b,c)+divide_matrix(n/2,n/2,n,n/2,n,a,n/2,n,n/2,n,b,c);
//         }
        
// }
int main()
{
        int n;
        printf("Enter the dimension of square matrix?");
        scanf("%d",&n);
        int a[n][n],b[n][n],c[n][n];
        printf("Enter the elements for first matrix?");
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        scanf("%d",&a[i][j]);
                }
        }
        printf("Enter the elements for second matrix?");
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        scanf("%d",&b[i][j]);
                }
        }
        printf("Elements for first matrix?\n");
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        printf("%d ",a[i][j]);
                }
                printf("\n");
        }
        printf("Elements for second matrix:-\n");
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        printf("%d ",b[i][j]);
                }
                printf("\n");
        }
        matrixMultiplication(n,a,b,c);
        printf("Elements for resultant matrix:-\n");
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        printf("%d ",c[i][j]);
                }
                printf("\n");
        }
        // divide_matrix(n,0,n,0,n,a,0,n,0,n,b,c);
        strassen(n,a,b,c);
        printf("Elements for resultant matrix using Straseen:-\n");
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        printf("%d ",c[i][j]);
                }
                printf("\n");
        }
        return 0;
}