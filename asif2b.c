#include<stdio.h>
int main(){
int start, end,temp, sum = 0;
int i;
    printf("Enter starting number:");
    scanf("%d", &start);

    printf("Enter the ending number:");
    scanf("%d", &end);
    if (start > end)
    {
        int temp = start;
        start=end;
        end = temp;
    }
    for (i= start; i<= end; i++)
    {
        if(i % 2 !=0)
        sum += i;
    }
    printf("Sum of all odd numbers between %d and %d is: %d\n", start,end,sum);

    return 0;
}