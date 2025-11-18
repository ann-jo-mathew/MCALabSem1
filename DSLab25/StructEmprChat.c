#include <stdio.h>
#include <string.h>

// Employee structure
typedef struct {
    int eno;        
    char ename[50]; 
    float esal;     
    int dno;        
} Employee;

// Function to read employee information
void readEmployees(Employee emp[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("Employee No: ");
        scanf("%d", &emp[i].eno);
        printf("Name: ");
        scanf(" %s", emp[i].ename);
        printf("Salary: ");
        scanf("%f", &emp[i].esal);
        printf("Department No: ");
        scanf("%d", &emp[i].dno);
    }
}

// Display employee information
void displayEmployees(Employee emp[], int n) {
	int i;
    printf("\nEmployee List:\n");
    printf("ENO\tName\tSalary\tDNO\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\t%d\n", emp[i].eno, emp[i].ename, emp[i].esal, emp[i].dno);
    }
}

// Search employee by number
void searchByNo(Employee emp[], int n, int eno) {
    int i,found = 0;
    for (i = 0; i < n; i++) {
        if (emp[i].eno == eno) {
            printf("Employee found: %d %s %.2f %d\n", emp[i].eno, emp[i].ename, emp[i].esal, emp[i].dno);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Employee with number %d not found.\n", eno);
}

// Sort by name
void sortByName(Employee emp[], int n) {
    Employee temp;
    int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(emp[i].ename, emp[j].ename) > 0) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
}

// Sort by salary
void sortBySalary(Employee emp[], int n) {
    Employee temp;
    int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (emp[i].esal < emp[j].esal) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
}

// Delete employee by number
int deleteByNo(Employee emp[], int n, int eno) {
    int i,j,found = 0;
    for (i = 0; i < n; i++) {
        if (emp[i].eno == eno) {
            found = 1;
            for (j = i; j < n - 1; j++) {
                emp[j] = emp[j + 1];  // Shift left
            }
            n--;
            printf("Employee with number %d deleted.\n", eno);
            break;
        }
    }
    if (!found)
        printf("Employee with number %d not found.\n", eno);
    return n;
}

// Menu function
int menu() {
    int ch;
    printf("\n\n1 - Display Employees");
    printf("\n2 - Search by Employee No");
    printf("\n3 - Sort by Name");
    printf("\n4 - Sort by Salary");
    printf("\n5 - Delete by Employee No");
    printf("\n6 - Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

// Process all menu options
void processEmployees(Employee emp[], int n) {
    int ch, eno;
    for (ch = menu(); ch != 6; ch = menu()) {
        switch (ch) {
            case 1:
                displayEmployees(emp, n);
                break;
            case 2:
                printf("Enter Employee Number to search: ");
                scanf("%d", &eno);
                searchByNo(emp, n, eno);
                break;
            case 3:
                sortByName(emp, n);
                printf("Employees sorted by Name.\n");
                displayEmployees(emp, n);
                break;
            case 4:
                sortBySalary(emp, n);
                printf("Employees sorted by Salary.\n");
                displayEmployees(emp, n);
                break;
            case 5:
                printf("Enter Employee Number to delete: ");
                scanf("%d", &eno);
                n = deleteByNo(emp, n, eno);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Main function
int main() {
    Employee emp[100];
    int n;

    printf("EMPLOYEE MANAGEMENT SYSTEM\n");
    printf("Enter number of employees: ");
    scanf("%d", &n);

    readEmployees(emp, n);
    processEmployees(emp, n);

    return 0;
}

