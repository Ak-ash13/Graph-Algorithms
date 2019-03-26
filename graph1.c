#include<stdio.h>
#include<stdlib.h>
struct vertex;
struct edge
{
    struct vertex *point;
    int weight;
    struct edge *next;
};
struct vertex
{
    char name;
    struct edge *ptr;
};
struct edge *e;
struct vertex * isFound(char vname,int n,struct vertex *v)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(v[i].name == vname)
        {
            flag=1;
            return &v[i];
        }
    }
    if(flag==0)
    {
        return NULL;
    }
}
void createNewNode(struct vertex *v,struct vertex *found,int i)
{
    struct edge *new=(struct edge *)malloc(sizeof(struct edge));
    new->point=found;
    printf("Enter weight of the edge?");
    scanf("%d",&new->weight);
    new->next=NULL;
    struct edge *temp;
    if((v+i)->ptr==NULL)
    {
        (v+i)->ptr=new;
    }
    else
    {
        struct edge *temp=(v+i)->ptr;
        while(temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
}
void displayList(struct vertex *v,int n)
{
    for(int i=0;i<n;i++)
    {
        struct edge *temp=(v+i)->ptr;
        printf("\nVertex:-%c\n",v[i].name);
        printf("Its edges are:-");
        while(temp!=NULL)
        {
            printf("%c,Weight=%d\t",temp->point->name,temp->weight);
            temp=temp->next;
        }
    }
}
void adjacencyMatrix(struct vertex *v,int n)
{
    int adj[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            adj[i][j]=0;
        }
    }
    int j;
    for(int i=0;i<n;i++)
    {
        struct edge *temp=(v+i)->ptr;
        while(temp!=NULL)
        {
            struct vertex *p=isFound(temp->point->name,n,v);  
            j=((p-v)/sizeof(struct vertex))-1;
            temp=temp->next;
            adj[i][j]=temp->weight;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n;k++)
        {
            printf("%d\t",adj[i][k]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    char choice='y';
    char vname;
    printf("Enter the number of vertices?");
    scanf("%d",&n);
    struct vertex *v=(struct vertex *)malloc(n*sizeof(struct vertex));
    struct edge *e=(struct edge *)malloc(n*sizeof(struct edge));
    printf("Enter the vertex names\n");
    for(int i=0;i<n;i++)
    {
        scanf(" %c",&v[i].name);
        v[i].ptr=NULL;
    }
    printf("\nEnter the edges for the corresponding vertex type\n");
    for(int i=0;i<n;i++)
    {
        printf("For vertex %c",v[i].name);
        printf("\nDo you want to add edge?");
        scanf(" %c",&choice);
        while(choice=='y')
        {
            printf("Enter vertex name to be connected?\n");
            scanf(" %c",&vname);
            struct vertex *found=isFound(vname,n,v);
            if(found!=NULL)
            {
                // Create new node at the list
                createNewNode(v,found,i);
            }
            else
            {
                printf("The vertex does not exist");
            }
            printf("Want to add more?");
            scanf(" %c",&choice);
            
        }
    }
    printf("\nDisplay the graph\n");
    displayList(v,n);
    adjacencyMatrix(v,n);
}