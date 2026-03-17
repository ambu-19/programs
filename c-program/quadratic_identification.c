#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, D, root1, root2, realPart, imagPart;
    printf("Enter coefficients a, b and c:");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0)
    {
        printf("This is not a quadratic equation! 'a' cannot be zero\n");
        return 0;
    }

    D = b * b - 4 * a * c;

    if (D > 0)
    {
        root1 = (-b + sqrt(D)) / (2 * a);
        root2 = (-b - sqrt(D)) / (2 * a);
        printf("Roots are real and distinct.\n");
        printf("Root1 = %.2lf\n", root1);
        printf("Root2 = %.2lf\n", root2);
    }
    else if (D == 0)
    {
        root1 = root2 = -b / (2 * a);
        printf("Roots are real and equal.\n");
        printf("Root1 = Root2 = %.2lf\n", root1);
    }
  else
{
realPart=-b/(2*a);
imagPart=sqrt(-D)/(2*a);
printf("Roots are complex and conjugate.\n");
printf("Root1=%.2lf+%.2lfi\n",realPart,imagePart);
printf("Root2=%.2lf-%.2lfi\n",realPart,imagePart);
}
return 0;
}
