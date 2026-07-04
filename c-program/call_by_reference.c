#include<stdio.h>
void swap(int*a, int*b)
{
  int temp=*a;
*a=*b;
*b=temp;
}
void main()
{
  int balance1 , balance2;
printf("Enter balance for account1:");
scanf("'%d,&balance1);
printf("Enter balance for account2:");
scanf("%d",&balance2);
printf("\nBefore swapping:\n");
printf("Account 1 balance:%d\n",balance1);
printf("Account 2 balance:%d\n",balance2);
swap(&balance1,&balance2);
printf("Account 1 balance:%d\n",balance1);
printf("Account 2 balance:%d\n",balance2);
}
