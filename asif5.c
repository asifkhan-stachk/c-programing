#include <stdio.h>

// Recursive function to find Fibonacci number
int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int N, i;
    int t1 = 0, t2 = 1, nextTerm;

    printf("Enter the number of terms: ");
    scanf("%d", &N);

    if (N <= 0)
    {
        printf("Please enter a positive integer.\n");
    }
    else
    {
        // Iterative method
        printf("\nFibonacci Series using Iterative Method:\n");

        for (i = 1; i <= N; i++)
        {
            printf("%d ", t1);
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
        }

        // Recursive method
        printf("\n\nFibonacci Series using Recursive Method:\n");

        for (i = 0; i < N; i++)
        {
            printf("%d ", fibonacci(i));
        }

        printf("\n");
    }

    return 0;
}