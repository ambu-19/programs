#include<stdio.h>
int main(){
  int marks;
printf("Enter the marks");
scanf("%d",&marks);
if(marks<0||marks>100)
  printf("Invalid marks");
else if(marks>=90)
{
printf("Student grade is A");
}
else if(marks>=75)
{
printf("Student grade is B");
}
else if(marks>=60)
{
printf("Student grade is C");
}
else if(marks>=50)
{
printf("Student grade is D");
}
else
{
printf("Student grade is F");
}
return 0;
}
