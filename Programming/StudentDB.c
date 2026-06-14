#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Macro
#define MAX_MARKS 5
 
// typedef and struct
typedef struct
{
    int id;
    char name[50];
    int marks[MAX_MARKS];
    float average;
} Student;
 
// enum
enum Grade
{
    FAIL,
    PASS,
    FIRST_CLASS
};
 
// Function declaration
void inputStudent(Student *s);
void calculateAverage(Student *s);
enum Grade findGrade(float avg);
void displayStudent(Student s);
void writeToFile(Student s);
 
int main()
{
    int choice;
    Student *student;
 
    // Dynamic memory allocation
    student = (Student *)malloc(sizeof(Student));
 
    if (student == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
 
    do
    {
        printf("\n===== C Concepts Demo Program =====\n");
        printf("1. Enter Student Details\n");
        printf("2. Display Student Details\n");
        printf("3. Save Student Details to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        // switch case
        switch (choice)
        {
        case 1:
            inputStudent(student);
            calculateAverage(student);
            break;
 
        case 2:
            displayStudent(*student);
            break;
 
        case 3:
            writeToFile(*student);
            break;
 
        case 4:
            printf("Exiting program...\n");
            break;
 
        default:
            printf("Invalid choice. Try again.\n");
        }
 
    } while (choice != 4);   // do-while loop
 
    // Free allocated memory
    free(student);
 
    return 0;
}
 
// Function with pointer
void inputStudent(Student *s)
{
    int i;
 
    printf("\nEnter Student ID: ");
    scanf("%d", &s->id);
 
    printf("Enter Student Name: ");
    scanf("%s", s->name);
 
    printf("Enter %d subject marks:\n", MAX_MARKS);
 
    // for loop and array
    for (i = 0; i < MAX_MARKS; i++)
    {
        printf("Subject %d: ", i + 1);
        scanf("%d", &s->marks[i]);
    }
}
 
// Function to calculate average
void calculateAverage(Student *s)
{
    int i, total = 0;
 
    for (i = 0; i < MAX_MARKS; i++)
    {
        total = total + s->marks[i];
    }
 
    s->average = total / (float)MAX_MARKS;
}
 
// Function returning enum
enum Grade findGrade(float avg)
{
    if (avg < 40)
    {
        return FAIL;
    }
    else if (avg < 75)
    {
        return PASS;
    }
    else
    {
        return FIRST_CLASS;
    }
}
 
// Function with structure argument
void displayStudent(Student s)
{
    int i;
    enum Grade grade;
 
    grade = findGrade(s.average);
 
    printf("\n===== Student Details =====\n");
    printf("ID      : %d\n", s.id);
    printf("Name    : %s\n", s.name);
 
    printf("Marks   : ");
    for (i = 0; i < MAX_MARKS; i++)
    {
        printf("%d ", s.marks[i]);
    }
 
    printf("\nAverage : %.2f\n", s.average);
 
    printf("Grade   : ");
 
    if (grade == FAIL)
    {
        printf("Fail\n");
    }
    else if (grade == PASS)
    {
        printf("Pass\n");
    }
    else
    {
        printf("First Class\n");
    }
}
 
// File handling
void writeToFile(Student s)
{
    FILE *fp;
 
    fp = fopen("student.txt", "w");
 
    if (fp == NULL)
    {
        printf("File opening failed\n");
        return;
    }
 
    fprintf(fp, "Student ID: %d\n", s.id);
    fprintf(fp, "Student Name: %s\n", s.name);
    fprintf(fp, "Average Marks: %.2f\n", s.average);
 
    fclose(fp);
 
    printf("Student details saved to student.txt\n");
}
 
