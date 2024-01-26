#include "cross_product.h"
#include <stdio.h>


// gets the cross product between two vectors
void get_cross_product() {
    // get vector 1, force 3d
    Vector v1 = vector_input("Input first 3d vector:");
    while (!v1.threeD) {
        printf("Cross product requires 3d vectors.\n");
        v1 = vector_input("Input first 3d vector:");
    }

    // get vector 2, force 3d
    Vector v2 = vector_input("Input second 3d vector:");
    while (!v2.threeD) {
        printf("Cross product requires 3d vectors.\n");
        v2 = vector_input("Input second 3d vector:");
    }

    // output
    printf("\n");
    print_vector(v1);
    printf(" x ");
    print_vector(v2);
    printf(" = ");
    print_vector(cross_product(v1, v2));
    printf("\n\n");
}

// computes the cross product of two vectors
Vector cross_product(Vector v1, Vector v2) {
    Vector v;

    v.threeD = 1;
    v.x = v1.y * v2.z - v1.z * v2.y;
    v.y = v1.z * v2.x - v1.x * v2.z;
    v.z = v1.x * v2.y - v1.y * v2.x;

    return v;
}
