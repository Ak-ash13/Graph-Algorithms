#include<stdio.h>
#include<stdlib.h>
int G[20][20];
int queue[20];
int visited[20];
int n;
int f=0;
int r=-1;;
void  DFS(int i);
void BFS(int v);
void display(int n,int edges);
void getvalues(int n,int edges);
void display2(int n,int edges);
void getvalues2(int n,int edges);
void main()
{	
	
	int i,j,vertex,edges;
	printf("\nEnter the no. of Vertex?");
	scanf("%d",&n);
	printf("\nEnter the number of edges");
	scanf("%d",&edges);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			G[i][j]=0;
			
			
		}
	}
	printf("\nKindly choose the type of Graph.\n 1. Directed Graph\n 2. Undirected Graph\n");
	int choose;
	scanf("%d",&choose);
	switch(choose)
	{
		case 1: getvalues(n,edges);
				display(n,edges);
				break;
				
		case 2: getvalues2(n,edges);
				display2(n,edges);
				break;
	}
	
	
	
	char ch='Y';
	do{
	
		printf("\nMenu :\n 1. Depth First tree\n 2. Breadth First tree\n");
		int option;
		scanf("%d",&option);
		switch(option)
		{
			case 1:	
						for(int i=0;i<n;i++)
							visited[i]=0;
							
					
					
					 printf("\nYou have selected Depth First traversal");
					printf("\nEnter the starting index to  start traversal");
					int start;
					scanf("%d",&start);
					DFS(start);
					break;
					
					
			case 2: 
						
							for(int i=0;i<n;i++)
							visited[i]=0;
				printf("\nYou have selected Breadth First traversal\n");
					
				 printf("\n Enter the starting vertex:\n");
				 int v;
				 scanf("%d", &v);
				 printf("\n The node which are reachable are:\n");
				 BFS(v);
				 
				 /*
				 for(i=0; i < n; i++) {
					 if(visited[i]==1)
					 printf("%d-->", i);
					 else 
					 printf("\n BFS Traversal not possible.All nodes are not  reachable");
					 break;
				 			
				 }*/
				 break;
				 
		 default: printf("\nYou presses a wrong key...Please try again!!");
		 
	 }
	 	printf("\n Do you want to continue Press Y or N?");
	 	scanf(" %c",&ch);
	 	}while(ch=='Y');
}
	
void getvalues(int n,int edges)
	{	
		int src,dest,weight;
		for(int i=0;i<edges;i++)
		{
			printf("\nEnter sources,destination for %d edges: \n",i);
			scanf("%d%d",&src,&dest);
			G[src][dest]=1;
			//G[dest][src]=1;
			
		}
		
		for(int i=0;i<n;i++)
		{
		visited[i]=0;
		}
	}
	
	void getvalues2(int n,int edges)
	{	
		int src,dest,weight;
		for(int i=0;i<edges;i++)
		{
			printf("\nEnter sources,destination for %d edges: \n",i);
			scanf("%d%d",&src,&dest);
			G[src][dest]=1;
			G[dest][src]=1;
			
		}
		
		for(int i=0;i<n;i++)
		{
		visited[i]=0;
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
		printf("\n----------------------------------------------------");
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
void display2(int n,int edges)
{
	char c;
		printf("\n");
		c='A';
		for(int i=1;i<=n;i++)
		{
			printf(" %c\t",c);
			c++;
		}
		printf("\n----------------------------------------------------");
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

void DFS(int i)
{		
	int j;
	printf("%d---->\t",i);
	visited[i]=1;
		
		for(j=0;j<n;j++)
		{
			if(!visited[j] && G[i][j]==1)
				DFS(j);
		}
}



	void BFS(int i) {
	
		int j;
		printf("\t%d--->",i);
		visited[i]=1;
		
 for(int j = 0; j<n;j++)
 	if(G[i][j]==1 && !visited[j])
	 	queue[++r] = j;
	 	if(f <= r) {
			 visited[queue[f]] = 1;
			 BFS(queue[f++]);
			 }
	}

	
	


	
	
	
