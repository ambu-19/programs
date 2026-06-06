#include<stdio.h>
int main()
{
  int i,j,n,temp;
printf("Enter number of scores to be stored\n");
scanf("%d",&n);
int score[n];
printf("Enter %d scores",n);
for(i=0;i<n;i++)
  scanf("%d",&score[i]);
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if (score[j]<score[j+1])
{
temp=score[j];
score[j]=score[j+1];
score[j+1]=temp;
}
}
}
printf("Sorted scores\n");
for (i=0;i<n;i++)
  printf("%d",score[i]);
return 0;
}
