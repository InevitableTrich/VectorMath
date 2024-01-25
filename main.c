#include <stdio.h>
#include <string.h>
#include "dot_product/dot_products.h"
#include "magnitude/magnitude.h"

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
            case 'm':
                get_magnitude();
                break;

            case 'd':
                get_dot_product();
                break;

            case 'x':
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
           "  m: magnitude\n"
           "  d: dot product\n"
           "  x: exit\n"
           "\n::");
}
