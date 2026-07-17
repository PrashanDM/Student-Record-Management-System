#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void initialize_queue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue* q, int id, const char* name, float gpa) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    if (new_student == NULL) {
        printf("Error: Memory allocation failed for Queue!\n");
        return;
    }

    new_student->student_id = id;
    strcpy(new_student->name, name);
    new_student->gpa = gpa;
    new_student->next = NULL;

    if (q->rear == NULL) {
        q->front = new_student;
        q->rear = new_student;
        printf("Student %d added to the pending registration queue.\n", id);
        return;
    }

    q->rear->next = new_student;
    q->rear = new_student;
    printf("Student %d added to the pending registration queue.\n", id);
}

Student* dequeue(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }

    Student* temp = q->front;
    
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    temp->next = NULL; 
    return temp;
}

void display_queue(Queue* q) {
    if (q->front == NULL) {
        printf("\n--- No students currently waiting in the registration queue. ---\n");
        return;
    }

    printf("\n==================================================\n");
    printf("           PENDING REGISTRATION QUEUE             \n");
    printf("==================================================\n");
    printf("%-10s %-30s %-5s\n", "ID", "Name", "GPA");
    printf("--------------------------------------------------\n");

    Student* current = q->front;
    while (current != NULL) {
        printf("%-10d %-30s %-5.2f\n", current->student_id, current->name, current->gpa);
        current = current->next;
    }
    printf("==================================================\n");
}