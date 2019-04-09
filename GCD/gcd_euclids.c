#include<stdlib.h>
#include<stdio.h>

int euclids_GCD(int m,int n)
{
  int a,b,r;
 if(m>n)
   {
      	 a=m;
       	 b=n;
   }
 else
   {
      	 a=n;
       	 b=m;
   }

while(b!=0)
{
     r=a%b;
     a=b;
     b=r;
}
return a;

}

void main()
{
  int m,n;
 printf("\nenter two numbers to find GCD\n");
  scanf("%d%d",&m,&n);

 int x=euclids_GCD(m,n);
printf("\n GCD of %d and %d is  %d\n\n", m,n,x);


}
