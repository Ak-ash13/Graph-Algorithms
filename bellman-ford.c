#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
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
    int cost;
    struct vertex *preced;
    struct edge *ptr;
};
struct edgeOrder
{
    struct vertex *source;
    struct vertex *destination;
    int weight;
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
        printf("Cost=%d\n",v[i].cost);
        printf("Its edges are:-");
        while(temp!=NULL)
        {
            printf("%c,Weight=%d\t",temp->point->name,temp->weight);
            temp=temp->next;
        }
    }
}  
void bellmanFord(int n,struct vertex *v,int number,struct edgeOrder *ed) 
{
    for(int k=1;k<=n-1;k++)
    {
        for(int i=0;i<number;i++)    
        {
            if((ed+i)->source->cost + (ed+i)->weight < (ed+i)->destination->cost)
            {
                (ed+i)->destination->cost=(ed+i)->source->cost + (ed+i)->weight ;
                (ed+i)->destination->preced=(ed+i)->source;
            }
        }
    }
    // Check for negative edge cycle
    int f=0;
    for(int i=0;i<number;i++)    
    {
        if((ed+i)->source->cost + (ed+i)->weight < (ed+i)->destination->cost)
        {
            // ed[i].destination->cost=ed[i].source->cost + ed[i].weight;
            // ed[i].destination->preced=ed[i].source;
            f=1;
            break;
        }
    }
    if(f==1)
    {
        printf("\nNegative edge cycle exists. The Graph can't be solved by this algorithm");
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            printf("Distance of vertex %c from Source=%d\n",v[i].name,v[i].cost);
        }
    }
    char tempsource,tempdest;
    printf("\nSelect your starting point?");
    scanf(" %c",&tempsource);
    printf("Enter destination from starting point?");
    scanf(" %c",&tempdest);
    char sequence[n];
    int i=1;
    struct vertex *found;
    sequence[0]=tempdest;
    found=isFound(tempdest,n,v);
    while(found->preced !=NULL)
    {
        found=found->preced;
        sequence[i]=found->name;
        i++;

    }
    for(int j=strlen(sequence)-1;j>=0;j--)
    {
        printf("%c->",sequence[j]); 
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
    printf("Enter the vertex names\n");
    for(int i=0;i<n;i++)
    {
        scanf(" %c",&v[i].name);
        if(i==0)
        {
            v[i].cost=0;
        }
        else
        {
            v[i].cost=INT_MAX;
        }
        v[i].preced=NULL;
        v[i].ptr=NULL;
    }
    printf("\nEnter the edges for the corresponding vertex type\n");
    for(int i=0;i<n;i++)
    {
        printf("For vertex %c",v[i].name);
        printf("\nDo you want to add edge?(y/n)");
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
            printf("Want to add more?(y/n)");
            scanf(" %c",&choice);
        }
    }
    int number;
    printf("Enter the number of edge orders?");
    scanf("%d",&number);
    printf("Enter the relaxation edge order?\n");
    struct edgeOrder *ed = (struct edgeOrder *)malloc(number*sizeof(struct edgeOrder));
    char tempsource,tempdest;
    for(int i=0;i<number;i++)
    {
        printf("Enter source?");
        scanf(" %c",&tempsource);
        printf("Enter destination?");
        scanf(" %c",&tempdest);
        struct vertex *found=isFound(tempsource,n,v);
        if(found!=NULL)
        {
            struct edge *temp=found->ptr;
            while(temp->point->name!=tempdest)
            {
                temp=temp->next;
            }
            if(temp!=NULL)
            {
                (ed+i)->source=found;
                (ed+i)->destination=temp->point;
                (ed+i)->weight=temp->weight;
            }
            else
            {
                printf("\nSource->destination does not exist");
            }
            
        }
        else
        {
            printf("Source vertex doesn't exist\n");
        }
        
    }
    printf("\nDisplay the graph\n");
    displayList(v,n);
    printf("\n");
    bellmanFord(n,v,number,ed);
    // displayList(v,n);
    return 0;
}