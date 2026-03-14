#include <stdio.h>

int calculation(int a, int b, int choice);

int main()
{
    int choice, a, b;

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    printf("\n1. Sum");
    printf("\n2. Difference");
    printf("\n3. Multiplication");
    printf("\n4. Division");

    printf("\nEnter the choice (1-4): ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 4)
        printf("Result = %d", calculation(a, b, choice));
    else
        printf("Invalid choice");

    return 0;
}

int calculation(int a, int b, int choice)
{
    if (choice == 1)
        return a + b;

    else if (choice == 2)
        return a - b;

    else if (choice == 3)
        return a * b;

    else if (choice == 4)
    {
        if (b != 0)
            return a / b;
        else
        {
            printf("Division not possible");
            return 0;
        }
    }

    return 0;
}
