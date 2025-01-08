#include "dsp_lecture.h"
#include <stdio.h>

void print_menu() {
    printf("Menu:\n");
    printf("1. Run add_vector_q_15_tb\n");
    printf("2. Run add_vector_s0_q15_tb\n");
    printf("3. Run mul_vector_s0_q15_tb\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Running add_vector_q_15_tb...\n");
                add_vector_q15_tb(5, 5);  // You can adjust the parameters as needed
                break;
            case 2:
                printf("Running add_vector_s0_q15_tb...\n");
                add_vector_s0_q15_tb(5, 5);  // You can adjust the parameters as needed
                break;
            case 3:
                printf("Running mul_vector_s0_q15_tb...\n");
                mul_vector_s0_q15_tb(5, 5);  // You can adjust the parameters as needed
                break;
            case 4:
                printf("Exiting...\n");
                return 0;  // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
