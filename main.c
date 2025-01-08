#include "dsp_lecture.h"
#include <stdio.h>

void print_menu()
{
    printf("Menu:\n");
    printf("1. Run add_vector_q15_tb\n");
    printf("2. Run add_vector_s0_q15_tb\n");
    printf("3. Run mul_vector_s0_q15_tb\n");
    printf("4. Run add_vector_s1_q15_tb\n");
    printf("5. Run mul_vector_s15_q15_tb\n");
    printf("6. Run mul_vector_a_q15_tb\n");
    printf("7. Run mul_vector_a_cq15_tb\n");
    printf("0. Exit\n");
}

int main()
{
    int choice;

    while (1)
    {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Running add_vector_q15_tb...\n");
            add_vector_q15_tb(10, 10);
            break;
        case 2:
            printf("Running add_vector_s0_q15_tb...\n");
            add_vector_s0_q15_tb(10, 10);
            break;
        case 3:
            printf("Running mul_vector_s0_q15_tb...\n");
            mul_vector_s0_q15_tb(10, 10);
            break;
        case 4:
            printf("Running add_vector_s1_q15_tb...\n");
            add_vector_s1_q15_tb(10, 10);
            break;
        case 5:
            printf("Running mul_vector_s15_q15_tb...\n");
            mul_vector_s15_q15_tb(10, 10);
            break;
        case 6:
            printf("Running mul_vector_a_q15_tb...\n");
            mul_vector_a_q15_tb(10, 10);
            break;
        case 7:
            printf("Running mul_vector_a_cq15_tb...\n");
            mul_vector_a_cq15_tb(10, 10);
            break;
        case 0:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}
