#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void initialize_stack(Stack* s) {
    s->top = NULL;
}

void push(Stack* s, Student* node) {
    if (node == NULL) return;

    node->next = s->top;

    s->top = node;
    
    printf("Student %d moved to the Undo History Stack.\n", node->student_id);
}

Student* pop(Stack* s) {
    if (s->top == NULL) {
        return NULL;
    }

    // Isolate the top node
    Student* temp = s->top;
    
    s->top = s->top->next;
    
    temp->next = NULL; 
    
    return temp;
}