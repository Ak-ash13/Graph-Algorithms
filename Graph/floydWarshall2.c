// C Program for Floyd Warshall Algorithm 
#include<stdio.h> 

// Number of vertices in the graph 
#define V 4 




// A function to print the solution matrix 
void printSolution(int dist[][V]); 


void floydWarshall (int graph[][V]) 
{ 
	
	int dist[V][V], i, j, k; 

	
	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 

	
	for (k = 0; k < V; k++) 
	{ 
		
		for (i = 0; i < V; i++) 
		{ 
			
			for (j = 0; j < V; j++) 
			{ 
				
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 

	
	printSolution(dist); 
} 


void printSolution(int dist[][V]) 
{ 
	printf ("The following matrix shows the shortest distances"
			" between every pair of vertices \n"); 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == 99999) 
				printf("%7s ", "INF"); 
			else
				printf ("%7d ", dist[i][j]); 
		} 
		printf("\n"); 
	} 
} 

// driver program to test above function 
int main() 
{ 
	
        int n;
        printf("Enter no. of vertices :\n");
        scanf("%d",&n);
        int graph[n][n];
        printf("Enter edges from each vertex \nif there is no edge, then enter 0 :\n");
        for (int i = 0; i < n; i++)
        {
                graph[i][i] = 0;
                for (int j = 0; j < n; j++)
                {
                printf("\nEdge from vertex %d to %d :", i,j);
                scanf(" %d", &graph[i][j]);
                if (graph[i][j] == 0 && i!=j)
                {
                        graph[i][j] = 99999;
                }
                }

        }

	floydWarshall(graph); 
	return 0; 
} 
