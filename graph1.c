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
            return v;
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
        scanf("%c",&v[i].name);
        v[i].ptr=NULL;
    }
    printf("\nEnter the edges for the corresponding vertex type\n");
    for(int i=0;i<n;i++)
    {
        printf("For vertex %c",v[i].name);
        do
        {
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
            printf("Want to add?");
            scanf(" %c",&choice);
            
        }while(choice=='y');
    }
}