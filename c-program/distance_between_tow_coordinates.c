#include<stdio.h>
#include<math.h>
int main()
{
  double x1,x2,y1,y2,distance;
printf("Enter the x1 and y1\n");
scanf("%lf %lf",&x1,&y1);
printf("Enter the x2 and y2\n");
scanf("%lf %lf",&x2,&y2);
distance=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
printf("The value of the distance between two coordinates is %.2lf\n",distance);
return 0;
}
