#include <stdlib.h>
#include <stdio.h>
#include "projection.h"
#include "../dot_product/dot_products.h"
#include "../magnitude/magnitude.h"


// get user input then perform a projection
void get_projection() {
    char* input = malloc(50 * sizeof(char));

    // output menu
    printf("Projection Options:\n"
           "  p: projection\n"
           "  s: scalar\n"
           "  x: back\n"
           "\n::");
    // get menu choice
    fgets(input, 50, stdin);

    // check for exit / bad input
    if (input[0] == 'x') {
        free(input);
        return;
    } else if (input[0] != 'p' && input[0] != 's') {
        printf("Input `%c` not recognized.\n", input[0]);
        free(input);
        get_projection();
        return;
    }

    // get the vectors
    Vector v1 = vector_input("Input vector 1:");
    Vector v2 = vector_input("Input vector 2:");

    // perform projection or scalar
    printf("\n");
    if (input[0] == 'p') {
        print_vector(v1);
        printf(" P ");
        print_vector(v2);
        printf(" = ");
        print_vector(projection(v1, v2));
    } else {
        print_vector(v1);
        printf(" S ");
        print_vector(v2);
        printf(" = %.3lf", scalar_projection(v1, v2));
    }

    printf("\n");

    free(input);
}

// compute projection of v1 onto v2
Vector projection(Vector v1, Vector v2) {
    double top_dot = dot_product(v1, v2);
    double bot_dot = dot_product(v2, v2);

    return scale_vector(v2, top_dot / bot_dot);
}

// compute scalar projection of v1 onto v2
double scalar_projection(Vector v1, Vector v2) {
    double dot = dot_product(v1, v2);
    double mag = magnitude(v2);

    return dot / mag;
}