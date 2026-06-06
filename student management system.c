#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent() {
    FILE *fp;
    struct Student s;

    fp = fopen("students.dat", "ab");

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);

    fclose(fp);

    printf("\nRecord Added Successfully!\n");
}

void displayStudents() {
    FILE *fp;
    struct Student s;

    fp = fopen("students.dat", "rb");

    if(fp == NULL) {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n----- STUDENT RECORDS -----\n");

    while(fread(&s, sizeof(s), 1, fp)) {
        printf("\nRoll No : %d", s.roll);
        printf("\nName    : %s", s.name);
        printf("\nMarks   : %.2f\n", s.marks);
    }

    fclose(fp);
}

void searchStudent() {
    FILE *fp;
    struct Student s;
    int roll, found = 0;

    fp = fopen("students.dat", "rb");

    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);

    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.roll == roll) {
            printf("\nRecord Found!\n");
            printf("Roll No : %d\n", s.roll);
            printf("Name    : %s\n", s.name);
            printf("Marks   : %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if(!found)
        printf("Student Not Found!\n");
}

void updateStudent() {
    FILE *fp;
    struct Student s;
    int roll, found = 0;

    fp = fopen("students.dat", "rb+");

    printf("Enter Roll Number to Update: ");
    scanf("%d", &roll);

    while(fread(&s, sizeof(s), 1, fp)) {

        if(s.roll == roll) {

            printf("Enter New Name: ");
            scanf("%s", s.name);

            printf("Enter New Marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);

            fwrite(&s, sizeof(s), 1, fp);

            found = 1;

            printf("Record Updated Successfully!\n");
            break;
        }
    }

    fclose(fp);

    if(!found)
        printf("Student Not Found!\n");
}

void deleteStudent() {
    FILE *fp, *temp;
    struct Student s;
    int roll, found = 0;

    fp = fopen("students.dat", "rb");
    temp = fopen("temp.dat", "wb");

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    while(fread(&s, sizeof(s), 1, fp)) {

        if(s.roll == roll) {
            found = 1;
            continue;
        }

        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if(found)
        printf("Record Deleted Successfully!\n");
    else
        printf("Student Not Found!\n");
}

int main() {

    int choice;

    do {
        printf("\n\n===== STUDENT MANAGEMENT SYSTEM =====");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Exit");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}