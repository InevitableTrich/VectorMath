#include <stdio.h>
#include <string.h>
#include "dot_product/dot_products.h"

// print menu
void menu();

// main menu / calc loop
int main() {
    char input[50];

    do {
        menu();
        strcpy(input, "");
        fgets(input, 50, stdin);
        printf("\n");

        switch (input[0]) {
            case 'd':
                get_dot_product();
                break;
            default:
                printf("Input `%s` not recognized\n\n", input);
                break;
        }

    } while (input[0] != 'x');

    return 0;
}

void menu() {
    printf("Vector Calculation Options\n"
           "  d: dot product\n"
           "\n::");
}
