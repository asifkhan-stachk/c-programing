
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student
{
    int id;
    char name[50];
    float marks1, marks2, marks3;
    float total, average;
    char grade;
};

int main()
{
    struct Student s[MAX];

    int choice, n = 0;
    int i, j, id, found;
    int ch;

    do
    {
        printf("\n===== Student Grade and Result Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Delete Student by ID\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");

        if(scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input!\n");

            while((ch = getchar()) != '\n' && ch != EOF);

            continue;
        }

        switch(choice)
        {
            // ADD STUDENT
            case 1:

                if(n >= MAX)
                {
                    printf("\nStudent record limit reached.\n");
                    break;
                }

                printf("\nEnter Student ID: ");

                if(scanf("%d", &id) != 1)
                {
                    printf("\nInvalid Student ID!\n");

                    while((ch = getchar()) != '\n' && ch != EOF);

                    break;
                }

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(s[i].id == id)
                    {
                        found = 1;
                        break;
                    }
                }

                if(found)
                {
                    printf("\nStudent ID already exists.\n");
                    break;
                }

                s[n].id = id;

                // Clear input buffer
                while((ch = getchar()) != '\n' && ch != EOF);

                printf("\nEnter Student Name: ");

                if(fgets(s[n].name, sizeof(s[n].name), stdin) == NULL)
                {
                    printf("\nName input error.\n");
                    break;
                }

                // Remove newline from name
                s[n].name[strcspn(s[n].name, "\n")] = '\0';

                // Check empty name
                if(strlen(s[n].name) == 0)
                {
                    printf("\nStudent name cannot be empty.\n");
                    break;
                }

                printf("\nEnter Marks in Subject 1: ");
                if(scanf("%f", &s[n].marks1) != 1)
                {
                    printf("\nInvalid marks input.\n");
                    while((ch = getchar()) != '\n' && ch != EOF);
                    break;
                }

                printf("Enter Marks in Subject 2: ");
                if(scanf("%f", &s[n].marks2) != 1)
                {
                    printf("\nInvalid marks input.\n");
                    while((ch = getchar()) != '\n' && ch != EOF);
                    break;
                }

                printf("Enter Marks in Subject 3: ");
                if(scanf("%f", &s[n].marks3) != 1)
                {
                    printf("\nInvalid marks input.\n");
                    while((ch = getchar()) != '\n' && ch != EOF);
                    break;
                }

                if(s[n].marks1 < 0 || s[n].marks1 > 100 ||
                   s[n].marks2 < 0 || s[n].marks2 > 100 ||
                   s[n].marks3 < 0 || s[n].marks3 > 100)
                {
                    printf("\nInvalid Marks! Enter marks between 0 and 100.\n");
                    break;
                }

                s[n].total = s[n].marks1 +
                             s[n].marks2 +
                             s[n].marks3;

                s[n].average = s[n].total / 3.0;

                if(s[n].average >= 90)
                    s[n].grade = 'A';

                else if(s[n].average >= 80)
                    s[n].grade = 'B';

                else if(s[n].average >= 70)
                    s[n].grade = 'C';

                else if(s[n].average >= 60)
                    s[n].grade = 'D';

                else if(s[n].average >= 50)
                    s[n].grade = 'E';

                else
                    s[n].grade = 'F';

                n++;

                printf("\nStudent added successfully!\n");

                break;


            // DISPLAY ALL STUDENTS
            case 2:

                if(n == 0)
                {
                    printf("\nNo student records found.\n");
                }
                else
                {
                    printf("\n========== STUDENT RECORDS ==========\n");

                    for(i = 0; i < n; i++)
                    {
                        printf("\n-------------------------------------\n");

                        printf("\nStudent ID   : %d\n", s[i].id);

                        printf("Student Name : %s\n", s[i].name);

                        printf("\n--------- SUBJECT MARKS ---------\n");

                        printf("\nSubject 1    : %.2f\n", s[i].marks1);

                        printf("Subject 2    : %.2f\n", s[i].marks2);

                        printf("Subject 3    : %.2f\n", s[i].marks3);

                        printf("\n--------- STUDENT RESULT ---------\n");

                        printf("\nTotal        : %.2f\n", s[i].total);

                        printf("Average      : %.2f\n", s[i].average);

                        printf("Grade        : %c\n", s[i].grade);

                        if(s[i].grade == 'F')
                            printf("Result       : Fail\n");
                        else
                            printf("Result       : Pass\n");

                        printf("\n-------------------------------------\n");
                    }
                }

                break;


            // SEARCH STUDENT
            case 3:

                if(n == 0)
                {
                    printf("\nNo student records available.\n");
                    break;
                }

                printf("\nEnter Student ID to search: ");

                if(scanf("%d", &id) != 1)
                {
                    printf("\nInvalid Student ID!\n");
                    while((ch = getchar()) != '\n' && ch != EOF);
                    break;
                }

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(s[i].id == id)
                    {
                        printf("\n========== STUDENT FOUND ==========\n");

                        printf("\nStudent ID   : %d\n", s[i].id);

                        printf("Student Name : %s\n", s[i].name);

                        printf("\nSubject 1    : %.2f\n", s[i].marks1);

                        printf("Subject 2    : %.2f\n", s[i].marks2);

                        printf("Subject 3    : %.2f\n", s[i].marks3);

                        printf("\nTotal        : %.2f\n", s[i].total);

                        printf("Average      : %.2f\n", s[i].average);

                        printf("Grade        : %c\n", s[i].grade);

                        if(s[i].grade == 'F')
                            printf("Result       : Fail\n");
                        else
                            printf("Result       : Pass\n");

                        found = 1;

                        break;
                    }
                }

                if(!found)
                {
                    printf("\nStudent ID not found.\n");
                }

                break;


            // DELETE STUDENT
            case 4:

                if(n == 0)
                {
                    printf("\nNo student records available.\n");
                    break;
                }

                printf("\nEnter Student ID to delete: ");

                if(scanf("%d", &id) != 1)
                {
                    printf("\nInvalid Student ID!\n");
                    while((ch = getchar()) != '\n' && ch != EOF);
                    break;
                }

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(s[i].id == id)
                    {
                        for(j = i; j < n - 1; j++)
                        {
                            s[j] = s[j + 1];
                        }

                        n--;

                        found = 1;

                        printf("\nStudent deleted successfully.\n");

                        break;
                    }
                }

                if(!found)
                {
                    printf("\nStudent ID not found.\n");
                }

                break;


            // EXIT
            case 5:

                printf("\nExiting program...\n");

                break;


            default:

                printf("\nInvalid choice! Please try again.\n");
        }

    } while(choice != 5);

    return 0;
}

