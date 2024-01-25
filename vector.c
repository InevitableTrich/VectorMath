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
    char* input = malloc(50 * sizeof(char));

    printf("%s\n::", print);
    fgets(input, 50, stdin);

    // start of input, end of search, data array, num count
    char* start = input;
    char* end = start;
    double* nums = malloc(3 * sizeof(double));
    int n = 0;

    // process the input as a vector
    while (n < 3) {
        // ignore angle bracket
        if (*start == '<') {
            start++;
        }

        // read the number, go to next character
        nums[n] = strtod(start, &end);
        start = end + 1;

        // if fraction, divide by next found number
        if (*end == '/') {
            nums[n] /= strtod(start, &end);
            start = end + 1;
        }

        // increment count
        ++n;

        // detect end of vector
        if (*end == '>' || (start - input) >= strlen(input)) {
            break;
        }
    }

    // create the vector based on parameters given
    Vector v;

    if (n == 2) {
        v = new_vector_2d(nums[0], nums[1]);
    } else if (n == 3) {
        v = new_vector_3d(nums[0], nums[1], nums[2]);
    } else {
        printf("Vectors require at least 2 numbers.\n");
        v = vector_input("Re-input the last vector:");
    }

    free(input);
    free(nums);

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