#include <stdio.h>
#include "dot_products.h"

// get user input to then perform dot product
void get_dot_product() {
    // get the vectors from user
    Vector v1 = vector_input("Input vector 1:");
    Vector v2 = vector_input("Input vector 2:");

    // check for same dimensionality
    if (v1.threeD != v2.threeD) {
        printf("The vectors must have the same dimensions.\n\n");
        return;
    }

    // output and calculate
    printf("\n");
    print_vector(v1);
    printf(" · ");
    print_vector(v2);
    printf(" = %.3lf\n\n", dot_product(v1, v2));
}

// perform a dot product on two vectors
double dot_product(Vector v1, Vector v2) {
    // do the 2d dot product
    double dot = (v1.x * v2.x) + (v1.y * v2.y);

    // if 3d, add the third dimension
    if (v1.threeD) {
        dot += v1.z * v2.z;
    }

    return dot;
}