#include<stdio.h>
#include<math.h>
#define PI 3.14
int main()
{
  float x,nume,term,sum;
int deg,i,fact;
printf("Enter degree\n");
scanf("%d",&deg);
x=(deg*PI)/180;
i=2;
nume=x;
fact=1;
sum=x;
do
{
fact=fact*i*(i+1);
nume=-nume*x*x;
term=nume/fact;
sum=sum+term;
i=i+2;
}
  while(fabs(term)>=0.0001);
printf("Sum=%f",sum);
return 0;
}
