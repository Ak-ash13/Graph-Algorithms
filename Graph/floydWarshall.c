#include<stdio.h>
#include<limits.h>


int main()
{
     int n;
     printf("Enter no. of vertices :\n");
     scanf("%d",&n);
     int a[n][n];
     printf("Enter edges from each vertex \nif there is no edge, then enter 0 :\n");
     for (int i = 0; i < n; i++)
     {
          a[i][i] = 0;
          for (int j = 0; j < n; j++)
          {
               printf("\nEdge from vertex %d to %d :", i,j);
               scanf(" %d", &a[i][j]);
               if (a[i][j] == 0 && i!=j)
               {
                    a[i][j] = 99999;
               }
          }

     }
     int b[n][n];
     //copy to sol matrix
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               b[i][j] = a[i][j];
          }

     }

     printf("\n\n");
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               if (b[i][j] == 99999)
				printf("%s ", "INF");
			else
                    printf("%d ", b[i][j]);
          }
          printf("\n");
     }

     for (int k = 0; k < n; k++)
     {
          for (int i = 0; i < n; i++)
          {
               for (int j = 0; j < n; j++)
               {
                   if( a[i][k] + a[k][j] < a[i][j] )
                    {
                         b[i][j]  = a[i][k] + a[k][j] ;
                    } 
               }

          }
     }

     printf("\n\n");

     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               if (b[i][j] == 99999)
				printf("%s   ", "INF");
			else
                    printf("%d   ", b[i][j]);
          }
          printf("\n");
     }

     return 0;
}
