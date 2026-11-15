
#include <stdio.h>

int main()
{
    int a[100], n, i, largest;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("\nEnter array elements:\n");

    for(i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    largest = a[0];

    for(i = 1; i < n; i++)
    {
        if(a[i] > largest)
        {
            largest = a[i];
        }
    }

    printf("\nLargest element in the array = %d\n", largest);

    return 0;
}
