#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
struct Student {
    int rollNumber;
    char name[50];
    int age;
    char grade;
};
void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    struct Student newStudent;

    printf("Enter Roll Number: ");
    scanf("%d", &newStudent.rollNumber);

    printf("Enter Name: ");
    scanf(" %[^\n]", newStudent.name); 

    printf("Enter Age: ");
    scanf("%d", &newStudent.age);

    printf("Enter Grade: ");
    scanf(" %c", &newStudent.grade);

    students[*count] = newStudent;
    (*count)++;

    printf("Student added successfully!\n");
}
void findStudentByRollNumber(struct Student students[], int count, int rollNumber) {
    int found = 0,i;
	for(i = 0; i < count;i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student Found!\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Grade: %c\n", students[i].grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}
int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice, rollNumber;

    while (1) {
        printf("\nSchool Management System\n");
        printf("1. Add Student\n");
        printf("2. Find Student by Roll Number\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                printf("Enter Roll Number to search: ");
                scanf("%d", &rollNumber);
                findStudentByRollNumber(students, studentCount, rollNumber);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
