#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

typedef struct graph
{
  char ch;
  int w;
}graph;

void printsp(int n, int d[], graph vname[])
{
  printf("\n   Vertex \tDistance from source");
  printf("\n_____________________________________\n");
  for(int i=0;i<n;i++)
  {
    printf("   %c \t\t %d\n",vname[i].ch,d[i]);
  }
  
}    

void printpath(int parent[],graph vname[],int k)
{
  if(parent[k]==-1)
  {
     printf("%c--->",vname[k].ch);
     return;
  }
    
  printpath(parent,vname,parent[k]);
  
  printf("%c--->",vname[k].ch);
  
} 

int min(int n,int d[],_Bool s[])
{
  int min = INT_MAX;
  int index;
  
  for(int i=0;i<n;i++)
  {
    if(s[i]==false && d[i]<=min)
     {
        min=d[i];
        index=i;
     }   
  }
  
  return index;  
}   

void dijkstra(int n,graph g[][n],int s,graph vname[])
{
  int d[n];
  _Bool status[n];
  int parent[n];
  
  char des;
  int i,j,k;
  
  for(i=0;i<n;i++)
  {
    d[i]=INT_MAX;
    status[i]=false;
    parent[i]=-1;
  }
  
  d[s]=0;
  
  for(i=0;i<n-1;i++)
  {
  
    k=min(n,d,status);
    status[k]=true;
    
    for(j=0;j<n;j++)
    {
      if(!status[j] && g[k][j].w && d[k]!=INT_MAX && d[k]+g[k][j].w < d[j])
       {
          d[j] = d[k]+g[k][j].w;
          parent[j]=k;
       }   
    }
  
  }
  
 printsp(n,d,vname); 
  
 printf("\n\n Enter destination:");
 scanf(" %c",&des); 
 
 for(i=0;i<n;i++)
 {
    if(des==vname[i].ch)
    {
      //s=i;
      break;
    }  
 }
 
 if(i==n)
 {
   printf("\n u have entered invalid destination!!!!!!\n Sayonara\n");
   return;
 }
 else
 { 
   printf("\nThe shortest path is:\n"); 
   printpath(parent,vname,i);
   printf("\b\b\b\n");
 }   
}

void main()
{
  int n;
  int s;
  char ch;
  printf("\n enter noo of vertex:");
  scanf("%d",&n);
  
  graph g[n][n];
  graph vname[n];
  
  printf("\n Enter Names of Vertices\n");
  for(int i=0;i<n;i++)
  {
    //printf("\n enter name:");
    scanf(" %c",&vname[i].ch);
  }  
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
       printf("\n enter distance from %c to %c (0 if not connected):",vname[i].ch,vname[j].ch);
       scanf("%d",&g[i][j].w);
    }
  }
  
  printf("\n\n Cost matrix is:\n\n   \t");
  
  for(int i=0;i<n;i++)
  {
    printf("%c\t",vname[i].ch);
  }  
  printf("\n____________________________________________\n");
  for(int i=0;i<n;i++)
  {
    printf("\n  %c  |\t",vname[i].ch);
    for(int j=0;j<n;j++)
    {
      printf("%d\t",g[i][j].w);
    }
  } 
      
  
 printf("\n\n Enter source name:");
 scanf(" %c",&ch);
 
 int i;
 for(i=0;i<n;i++)
 {
    if(ch==vname[i].ch)
    {
      s=i;
      break;
    }  
 }
 if(i==n)
 {
   printf("\n u have entered invalid source!!!!!!\n Sayonara\n");
   return;
 }
 else  
  dijkstra(n,g,s,vname);
 
}  
      
