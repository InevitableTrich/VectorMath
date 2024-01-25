#include "magnitude.h"
#include <math.h>
#include <stdio.h>

void get_magnitude() {
    // get the vector from user
    Vector v = vector_input("Input vector:");

    // output and calculate
    printf("\n|");
    print_vector(v);
    printf("| = %.3lf\n\n", magnitude(v));
}

// computes the magnitude of a vector
double magnitude(Vector v) {
    // square and sum the x and y components
    double sq_sum = v.x * v.x + v.y * v.y;

    // if 3d, add z^2
    if (v.threeD) {
        sq_sum += v.z * v.z;
    }

    return sqrt(sq_sum);
}
