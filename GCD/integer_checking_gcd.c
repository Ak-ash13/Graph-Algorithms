#include<stdlib.h>
#include<stdio.h>

int integer_checking_GCD(int m,int n)
{
 // int a,b,r;
int s; 
if(m>n)
     s=n;
 else
    s=m;

while(s>0)
{
 	 if((m%s==0) && (n%s==0))
   		  return s;
 	else
	 {
  		
   		   s=s-1;

  	}
}
 return 1;
}

void main()
{
  int m,n;
 printf("\nenter two numbers to find GCD\n");
  scanf("%d%d",&m,&n);

 int x=integer_checking_GCD(m,n);
printf("\n GCD of %d and %d is  %d\n\n", m,n,x);


}
