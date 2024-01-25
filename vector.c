#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// creates a new 2d vector
Vector new_vector_2d(double x, double y) {
    return (Vector) {0, x, y, 0};
}

// creates a new 3d vector
Vector new_vector_3d(double x, double y, double z) {
    return (Vector) {1, x, y, z};
}

// prompts user for vector
Vector vector_input(char* print) {
    char input[50];

    printf("%s\n::", print);
    fgets(input, 50, stdin);

    // start of input, end of search, data array, num count
    char* start = input;
    char* end = start;
    double nums[3];
    int n = 0;

    // process a vector in the form <x, y, z> or <x, y>
    while (n < 3) {
        // ignore angle bracket
        if (*start == '<') {
            start++;
        }

        // read the number, skip over the comma and space
        nums[n] = strtod(start, &end);
        start = end + 2;
        n++;

        // detect end of vector
        if (*end == '>' || (start - input) == strlen(input)) {
            break;
        }
    }

    // create a vector and set x,y
    Vector v;
    v.x = nums[0];
    v.y = nums[1];

    // if the vector is 2d, set threeD to
    // false, else read z and set to 3d
    if (n == 2) {
        v.threeD = 0;
    } else {
        v.z = nums[2];
        v.threeD = 1;
    }

    return v;
}

// prints a vector
void print_vector(Vector v) {
    if (v.threeD) {
        printf("<%.3lf, %.3lf, %.3lf>", v.x, v.y, v.z);
    } else {
        printf("<%.3lf, %.3lf>", v.x, v.y);
    }
}