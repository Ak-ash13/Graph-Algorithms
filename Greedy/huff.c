#include<stdio.h>
#include<stdlib.h>

typedef struct heap
{
  char ch;
  int freq;
  
  struct heap *left;
  struct heap *right;
}heap;

heap* node[50];
int size=0;

void sort(int n,heap* h[])
{
  int i,j;
  heap* key;
  
  for(i=1;i<n;i++)
  {
    key=h[i];
    j=i-1;
    
    while(j>=0 && h[j]->freq>key->freq)
    {
      h[j+1]=h[j];
      j=j-1;
    }
    
    h[j+1]=key;
  }
}    


void create(heap* new)
{

  node[size++]=new;
  sort(size,node);
}

void display(int n,heap* h[])
{
  printf("\n *************\n");
  for(int i=0;i<n;i++)
  {
    printf("|%c|%d|-",h[i]->ch,h[i]->freq);
  }
}      
  
void swap(heap* *a, heap* *b) 
{ 
    heap* temp = *a; 
    *a = *b; 
    *b = temp; 
}

heap* Extract_min()
{
  swap(&node[0],&node[size-1]);	
  heap* min=node[size-1];		
  size=size-1;		
  sort(size,node);
  
  return min;
}

void printarr(int arr[],int n)
{ 
  for(int i=0;i<n;i++)
  printf("%d",arr[i]);
  
  printf("\n");
}  

 

void printcode(heap* root,int arr[],int top)
{
  if(root->left)
  {
    arr[top]=0;
    printcode(root->left,arr,top+1);
  }
  
  if(root->right)
  {
    arr[top]=1;
    printcode(root->right,arr,top+1);
  }
  
  if(root->left==NULL && root->right==NULL)
  {
    printf("  %c: ",root->ch);
    printarr(arr,top);
  }      

}


void Huffman(int n)
{
  int i;
  
  for(i=0;i<n-1;i++)
  {
    heap * left=Extract_min();
    heap * right=Extract_min();
    
    heap* temp=(heap *)malloc(sizeof(heap));
    temp->ch=0;
    temp->left=left;
    temp->right=right;
    temp->freq=left->freq+right->freq;
 
    create(temp);
  }
  
  int arr[50];
  printf("\n\n Huffman Codes:\n");
  printcode(node[size-1],arr,0);
}    
  
  

void main()
{
  int n;
  printf("\n Enter no of data:");
  scanf("%d",&n);
  
  for(int i=0;i<n;i++)
  {
    heap* new = (heap*)malloc(sizeof(heap));
    printf("\n Enter name:");
    scanf(" %c",&new->ch);
    printf("\n Enter Frequency:");
    scanf("%d",&new->freq);
    new->left=NULL;
    new->right=NULL; 
    
    create(new);
  }
  
  display(size,node);
  
  Huffman(n);
  
}  
  
