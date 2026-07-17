#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
    int student_id;
    char name[50];
    float gpa;
    struct Student* next;
} Student;

typedef struct Queue {
    Student* front;
    Student* rear;
} Queue;

typedef struct Stack {
    Student* top;
} Stack;


void insert_student(Student** head, int id, const char* name, float gpa);
int delete_student(Student** head, int id, Student** temp_deleted);
void display_students(Student* head);
Student* search_student(Student* head, int id);

void initialize_queue(Queue* q);
void enqueue(Queue* q, int id, const char* name, float gpa);
Student* dequeue(Queue* q);
void display_queue(Queue* q);

void initialize_stack(Stack* s);
void push(Stack* s, Student* node);
Student* pop(Stack* s);

#endif