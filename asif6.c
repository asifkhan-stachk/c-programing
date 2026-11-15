#include <stdio.h>

void counter(void)
{
    static int count = 0;

    count++;

    printf("Function called %d time(s)\n", count);
}

int main(void)
{
    counter();
    counter();
    counter();
    counter();

    return 0;
}