#include<stdlib.h>
#include<stdio.h>

void seive_of_eratosthenes(int prime[],int r)
{
     for(int i=0;i<=r;i++)
         prime[i]=1;

  prime[0]=0;
  prime[1]=0;

for(int i=2;i*i<=r;i++)
{
     if(prime[i]==1)
     {
	for(int j=i*i;j<=r;j=j+i)
		prime[j]=0;

     }
    
}

}

void prime_factorization(int arr[],int prime[],int r,int *count)
{   *count=0;
    for(int i=2;i<=r;i++)
  {
	 if(prime[i]==1)
           {    
                 int p=r;
                 while(p>0)
                 {
                  if( (p%i)==0)
                   {
                       arr[*count]=i;
		      *count=(*count)+1;
                        p=p/i;
                   }
                  else
			break;
            }

         }
    }

 printf("\n prime factorization of %d :  ",r);
 for(int i=0;i<*count;i++)
      printf("%d  * ",arr[i]);

}
int  GCD_prime_factors(int m,int n)
{
     int mprime[m+1];
     int nprime[n+1];
     seive_of_eratosthenes(mprime,m);
     seive_of_eratosthenes(nprime,n);
     
       int pfactorm[m+1];
       int pfactorn[n+1];

       int mcount=0,ncount=0;
 prime_factorization(pfactorm,mprime,m,&mcount);
 prime_factorization(pfactorn,nprime,n,&ncount);

int i=0;
int j=0;
int gcd=1;


while(i<mcount&&j<ncount)
{
      if((pfactorm[i]==pfactorn[j]))
      {
		gcd=gcd*pfactorm[i];
		i++;
	        j++;

       }

	else 
       {
              if(pfactorm[i]>pfactorn[j])
                  j++;
               else
                    i++;
       }     
  }
 return gcd;
  
}
void main()
{
  int m,n;
 printf("\nenter two numbers to find GCD\n");
  scanf("%d%d",&m,&n);

 int x=GCD_prime_factors(m,n);
printf("\n\n GCD of %d and %d is  %d\n\n", m,n,x);

}

