#include<stdio.h>
int i,j,n,t=3; 
int p[10],l[10],temp,m,tape[10][10]; 
int itemcount[10]; 


float mrt[10];
void getvalue()
{
	printf("Enter no of programs\n");
	scanf("%d",&n);
	printf("Enter number of tapes");
	scanf("%d",&t);
		for(i=0;i<n;i++)
		{
		printf("Enter length of program %d",i+1);
		scanf("%d",&l[i]);
		p[i]=i;
		}

		for(i=1;i<=t;i++) 	
		{
			for(j=0;j<30;j++)
			tape[i][j]=0;
		}
}
void sort()
{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-1;j++)
			{
				if(l[j]>l[j+1])
				{
					temp=l[j];
					l[j]=l[j+1];
					l[j+1]=temp;

					m=p[j];
					p[j]=p[j+1];
					p[j+1]=m;
				}
			}
}
		for(i=0;i<n;i++)
		{
		printf("program %d\t",p[i]);
		printf("length %d\n",l[i]);

		}

}

void arrange()
	{ 
		int count=0;
		int r=0;
		for(i=0;i<10;i++)
		itemcount[i]=0;
		for(i=0;i<n;i++)
		{
			count++;
			tape[count][r]=l[i];
			itemcount[count]++;

			if(count==t)
			{
			r++;
			count=0;
			}

		}
}
void printtape()
{
		int r=0;
		for(i=1;i<=t;i++)
		{ 
			printf("\ntape %d",i);
				while(tape[i][r]!=0)
				{
				printf("%d\t",tape[i][r]);
				r++;
				}
				printf("\n");
				r=0;
		}
}
void calmrt()
{
		int r=0,k;
		float sum[10]; //to save sum of each tape
		for(i=0;i<10;i++) //init sum
		{
		sum[i]=0;
		}
		j=0;
		for(i=1;i<=t;i++)
		{
			for(j=0;j<itemcount[i];j++)
			{
				for(k=0;k<=j;k++)
					{
					sum[i]=sum[i]+tape[i][k];

					}

					r++;
					
			}
			r=0;
			mrt[i]=sum[i]/itemcount[i];
			printf("MRT of tape %d is %f\n",i,mrt[i]);
			
			}

}

int main()
{

getvalue();
sort();
arrange();
printtape();
calmrt();
//finalmrt();
return 0;

}
