#include "angle.h"
#include "math.h"
#include "../input/input.h"
#include "../dot_product/dot_products.h"
#include "../magnitude/magnitude.h"
#include <stdio.h>


// gets the angle between two vectors
void get_angle() {
    // determine output unit
    char option = get_char_input("Unit:\n"
                                 "  r: radians\n"
                                 "  d: degrees\n"
                                 "  x: back\n", "xrd");

    // return if requested
    if (option == 'x') {
        return;
    }

    // get vectors
    Vector v1 = vector_input("Input vector 1:");
    Vector v2 = vector_input("Input vector 2:");

    // compute radians
    double rads = angle(v1, v2);

    // output start
    print_vector(v1);
    printf(" a ");
    print_vector(v2);
    printf(" = ");

    // output differently based on unit chosen
    if (option == 'd') {
        printf("%.3lf°", degrees(rads));
    } else {
        printf("%.3lf rads", rads);
    }

    printf("\n\n");
}

double angle(Vector v1, Vector v2) {
    double dot = dot_product(v1, v2);
    double mags = magnitude(v1) * magnitude(v2);

    return acos(dot / mags);
}

#define DEG_CONV (180/M_PI)
double degrees(double rad) {
    return DEG_CONV * rad;
}