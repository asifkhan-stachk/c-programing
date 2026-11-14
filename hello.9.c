#include <stdio.h>

#define N 5

/* Structure to hold one student's record */
struct student_record {
    char  name[50];
    int   roll_number;
    float total_marks;
};

int main(void)
{
    struct student_record students[5];
    struct student_record topper;
    int i;

    /* Read data of N students */
    for (i = 0; i < N; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Name:");
        scanf(" %49[^\n]", students[i].name);   /* allows spaces in name */

        printf("Roll number:");
        scanf("%d", &students[i].roll_number);

        printf("Total marks:");
        scanf("%f", &students[i].total_marks);
    }

    /* Find the topper (student with the highest total marks) */
    topper = students[0];
    for (i = 1; i < N; i++) {
        if (students[i].total_marks > topper.total_marks) {
            topper = students[i];
        }
    }

    /* Display the topper */
    printf("\n===== TOPPER =====\n");
    printf("Name: %s\n", topper.name);
    printf("Roll number : %d\n", topper.roll_number);
    printf("Total marks: %.2f\n", topper.total_marks);

    return 0;
}