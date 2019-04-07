#include<stdio.h>
#include<stdlib.h>

int G[20][20];
int visited[20];
void getvalues(int n,int edges);
void display(int n,int edges);
void Prims(int n,int edges);
void main()
{
	printf("\nEnter the no. of Vertex?");
	int n,edges;
	scanf("%d",&n);
	printf("\nEnter total no of edges?");
	scanf("%d",&edges);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			G[i][j]=0;
			
			
		}
	}
	
	getvalues(n,edges);
	printf("\nThe entered graph is ");
	
	display(n,edges);
	Prims(n,edges);
}

	void getvalues(int n,int edges)
	{	
		int src,dest,weight;
		for(int i=0;i<edges;i++)
		{
			printf("\nEnter sources,destination,and weight\n");
			scanf("%d%d%d",&src,&dest,&weight);
			G[src][dest]=weight;
			G[dest][src]=weight;
			
		}
	}
	
	void display(int n,int edges)
	{	
		char c;
		printf("\n");
		c='A';
		for(int i=1;i<=n;i++)
		{
			printf(" %c\t",c);
			c++;
		}
		printf("\n");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d\t",G[i][j]);
			}
			printf("\n");
		}
	}
	
	void Prims(int n,int edges)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
			if(G[i][j]==0)
			{
				G[i][j]=9999;
			}
		}
	}
	
				
		
		int src,dest,min;
		for(int i=0;i<n;i++)
		{
			visited[i]=0;
		}
		int i,j;
	
		printf("\nEnter the source to start the minimum spanning tree");
		scanf("%d",&src);
		visited[src]=1;
		edges=n-1;
		int total=0;
		while(edges>0)
		{
			min=9999;
			for( i=0;i<n;i++)
			{
				if(visited[i]==1)
				{
					for( j=0;j<n;j++)
					{
						if(visited[j]!=1)
						{
							if(min>G[i][j])
							{
								
								min=G[i][j];
								src=i;
								dest=j;
							}
						}
					}
				}
				
				
			}
			visited[dest]=1;
			total=total+G[src][dest];
				printf("\nEdges in Spanning tree is  %d---> %d \tand cost:  %d",src,dest,min);
	
			edges--;
		}
		
		printf("\nTotal Cost is %d\n",total);
	}
						
		
	
		
			
				
				
	

