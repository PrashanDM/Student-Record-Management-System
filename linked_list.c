#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void insert_student(Student** head, int id, const char* name, float gpa) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    if (new_student == NULL) {
        printf("Error: Memory allocation failed!\n");
        return;
    }

    new_student->student_id = id;
    strcpy(new_student->name, name);
    new_student->gpa = gpa;
    new_student->next = NULL;

    if (*head == NULL) {
        *head = new_student;
        printf("Student %d successfully registered in master database.\n", id);
        return;
    }

    Student* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_student;
    printf("Student %d successfully registered in master database.\n", id);
}

void display_students(Student* head) {
    if (head == NULL) {
        printf("\n--- No records found in the database. ---\n");
        return;
    }

    printf("\n==================================================\n");
    printf("               ACTIVE STUDENT RECORDS             \n");
    printf("==================================================\n");
    printf("%-10s %-30s %-5s\n", "ID", "Name", "GPA");
    printf("--------------------------------------------------\n");

    Student* current = head;
    while (current != NULL) {
        printf("%-10d %-30s %-5.2f\n", current->student_id, current->name, current->gpa);
        current = current->next;
    }
    printf("==================================================\n");
}

Student* search_student(Student* head, int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->student_id == id) {
            return current; // Student found!
        }
        current = current->next;
    }
    return NULL; // Student not found
}

int delete_student(Student** head, int id, Student** temp_deleted) {
    if (*head == NULL) {
        return 0; // List is empty
    }

    Student* current = *head;
    Student* previous = NULL;

    if (current != NULL && current->student_id == id) {
        *head = current->next;    
        current->next = NULL;     
        *temp_deleted = current;   
        return 1;                  
    }

    while (current != NULL && current->student_id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return 0;
    }

    previous->next = current->next;
    current->next = NULL;          
    *temp_deleted = current;       
    return 1;                     
}