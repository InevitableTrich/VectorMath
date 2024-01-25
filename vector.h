#ifndef VECTORS_VECTOR_H
#define VECTORS_VECTOR_H


typedef struct vector {
    int threeD;
    double x, y, z;
} Vector;

Vector new_vector_2d(double, double);
Vector new_vector_3d(double, double, double);
Vector vector_input(char*);
void print_vector(Vector);

#endif //VECTORS_VECTOR_H
