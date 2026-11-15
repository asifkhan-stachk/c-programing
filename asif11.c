
#include <stdio.h>
#include <string.h>

struct Employee
{
    int id;
    char name[50];
    char department[30];
    float salary;
};

struct Employee e[100];
int n = 0;

void addEmployee()
{
    int id, i;

    printf("\nEnter Employee ID: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (e[i].id == id)
        {
            printf("Employee ID already exists!\n");
            return;
        }
    }

    if (n >= 100)
    {
        printf("Database is full!\n");
        return;
    }

    e[n].id = id;

    printf("Enter Employee Name: ");
    scanf(" %49[^\n]", e[n].name);

    printf("Enter Department: ");
    scanf(" %29[^\n]", e[n].department);

    printf("Enter Salary: ");
    scanf("%f", &e[n].salary);

    if (e[n].salary < 0)
    {
        printf("Invalid Salary!\n");
        return;
    }

    n++;
    printf("\nEmployee added successfully!\n");
}

void displayEmployees()
{
    int i;

    if (n == 0)
    {
        printf("\nNo employee records found!\n");
        return;
    }

    printf("\n===== EMPLOYEE RECORDS =====\n");

    for (i = 0; i < n; i++)
    {
        printf("\nEmployee ID   : %d\n", e[i].id);
        printf("Employee Name : %s\n", e[i].name);
        printf("Department    : %s\n", e[i].department);
        printf("Salary        : %.2f\n", e[i].salary);
        printf("-----------------------------\n");
    }
}

void searchEmployee()
{
    int id, i, found = 0;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (e[i].id == id)
        {
            printf("\nEmployee Found!\n");
            printf("ID         : %d\n", e[i].id);
            printf("Name       : %s\n", e[i].name);
            printf("Department : %s\n", e[i].department);
            printf("Salary     : %.2f\n", e[i].salary);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Employee not found!\n");
}

void updateEmployee()
{
    int id, i, found = 0;

    printf("\nEnter Employee ID to update: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (e[i].id == id)
        {
            printf("Enter New Name: ");
            scanf(" %49[^\n]", e[i].name);

            printf("Enter New Department: ");
            scanf(" %29[^\n]", e[i].department);

            printf("Enter New Salary: ");
            scanf("%f", &e[i].salary);

            if (e[i].salary < 0)
            {
                printf("Invalid Salary!\n");
                return;
            }

            printf("Employee updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Employee not found!\n");
}

void deleteEmployee()
{
    int id, i, j, found = 0;

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (e[i].id == id)
        {
            for (j = i; j < n - 1; j++)
                e[j] = e[j + 1];

            n--;
            found = 1;
            printf("Employee deleted successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Employee not found!\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== EMPLOYEE DATABASE =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6:
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
