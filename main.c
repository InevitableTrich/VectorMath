#include <stdio.h>
#include <string.h>
#include "dot_product/dot_products.h"
#include "magnitude/magnitude.h"
#include "projection/projection.h"
#include "angle/angle.h"


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

            case 'p':
                get_projection();
                break;

            case 'a':
                get_angle();
                break;

            case 'x':
                break;

            default:
                printf("Input `%c` not recognized\n", input[0]);
                break;
        }

    } while (input[0] != 'x');

    return 0;
}

void menu() {
    printf("Vector Calculation Options\n"
           "  m: magnitude\n"
           "  d: dot product\n"
           "  p: projection\n"
           "  a: angle\n"
           "  x: exit\n"
           "\n::");
}
