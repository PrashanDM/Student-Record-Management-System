#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void save_to_file(Student* head, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing!\n", filename);
        return;
    }

    Student* current = head;
    while (current != NULL) {
        fprintf(file, "%d %.2f %s\n", current->student_id, current->gpa, current->name);
        current = current->next;
    }

    fclose(file);
    printf("All student records successfully backed up to '%s'.\n", filename);
}

void load_from_file(Student** head, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return; 
    }

    int id;
    float gpa;
    char name[50];

    while (fscanf(file, "%d %f %[^\n]", &id, &gpa, name) == 3) {
        insert_student(head, id, name, gpa);
    }

    fclose(file);
    printf("Successfully restored previous student records from storage.\n");
}