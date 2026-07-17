#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void save_to_file(Student* head, const char* filename);
void load_from_file(Student** head, const char* filename);

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Student* master_head = NULL;
    Queue registration_queue;
    Stack undo_stack;

    initialize_queue(&registration_queue);
    initialize_stack(&undo_stack);

    load_from_file(&master_head, "students.txt");

    int choice;
    int id;
    char name[50];
    float gpa;
    Student* temp_node = NULL;

    while (1) {
        printf("\n==================================================\n");
        printf("        STUDENT RECORD MANAGEMENT SYSTEM          \n");
        printf("==================================================\n");
        printf(" [1] Add Student to Pending Queue (Admissions)\n");
        printf(" [2] Process Next Pending Registration (FIFO)\n");
        printf(" [3] Display Pending Registration Queue\n");
        printf(" [4] Display All Active Students (Linked List)\n");
        printf(" [5] Search Student by ID (Linear Search)\n");
        printf(" [6] Remove Student from Active Database\n");
        printf(" [7] Undo Last Deletion (LIFO Stack)\n");
        printf(" [8] Exit & Save Records\n");
        printf("==================================================\n");
        printf("Enter your choice (1-8): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clear_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                printf("\n--- Add Student to Pending Queue ---\n");
                printf("Enter Student ID: ");
                scanf("%d", &id);
                clear_buffer();
                printf("Enter Student Name: ");
                scanf("%[^\n]", name);
                printf("Enter Student GPA: ");
                scanf("%f", &gpa);
                
                enqueue(&registration_queue, id, name, gpa);
                break;

            case 2:
                printf("\n--- Processing Pending Registration ---\n");
                temp_node = dequeue(&registration_queue);
                if (temp_node == NULL) {
                    printf("No pending registrations to process.\n");
                } else {
                    printf("Processing application for: %s\n", temp_node->name);
                    insert_student(&master_head, temp_node->student_id, temp_node->name, temp_node->gpa);
                    free(temp_node); 
                }
                break;

            case 3:
                display_queue(&registration_queue);
                break;

            case 4:
                display_students(master_head);
                break;

            case 5:
                printf("\n--- Search Student ---\n");
                printf("Enter Student ID to find: ");
                scanf("%d", &id);
                
                temp_node = search_student(master_head, id);
                if (temp_node != NULL) {
                    printf("\nRecord Found:\n");
                    printf("ID: %d | Name: %s | GPA: %.2f\n", temp_node->student_id, temp_node->name, temp_node->gpa);
                } else {
                    printf("Student with ID %d not found in master database.\n", id);
                }
                break;

            case 6:
                printf("\n--- Remove Student ---\n");
                printf("Enter Student ID to remove: ");
                scanf("%d", &id);
                
                if (delete_student(&master_head, id, &temp_node)) {
                    printf("Student %d removed from active database.\n", id);
                    push(&undo_stack, temp_node); 
                } else {
                    printf("Student ID %d not found.\n", id);
                }
                break;

            case 7:
                printf("\n--- Undo Last Deletion ---\n");
                temp_node = pop(&undo_stack);
                if (temp_node == NULL) {
                    printf("Nothing to undo. Undo history stack is empty!\n");
                } else {
                    printf("Restoring student: %s (ID: %d)\n", temp_node->name, temp_node->student_id);
                    insert_student(&master_head, temp_node->student_id, temp_node->name, temp_node->gpa);
                    free(temp_node);
                }
                break;

            case 8:
                printf("\nSaving system state and cleaning up allocations...\n");
                save_to_file(master_head, "students.txt");
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option! Please pick a number between 1 and 8.\n");
        }
    }
    return 0;
}