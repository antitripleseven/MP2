#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

extern void saxpy(int n, float A, float x[], float y[], float z[]);

int main() {
    int n;
    float A;
    float x[MAX_SIZE];
    float y[MAX_SIZE];
    float z[MAX_SIZE];

    printf("Enter length of array N\n");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Error: N exceeds the maximum allowed size of %d\n", MAX_SIZE);
        return 1;
    }

    printf("Enter A number\n");
    scanf("%f", &A);

    printf("Enter x array\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter y array\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }

    saxpy(n, A, x, y, z);

    printf("N = %d\n", n);
    printf("A = %f\n", A);

    printf("First ten elements of Z:\n");
    for (int i = 0; i < n && i < 10; i++) {
        printf("%f\n", z[i]);
    }

    return 0;
}