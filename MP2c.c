#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // For gettimeofday()

#define MAX_SIZE 100
#define REPEAT_COUNT 10000 // Repeat saxpy to amplify execution time

extern void saxpy(int n, float A, float x[], float y[], float z[]);

int main() {
    int n;
    float A;
    float x[MAX_SIZE];
    float y[MAX_SIZE];
    float z[MAX_SIZE];

    printf("Enter length of array N (max %d):\n", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Error: N exceeds the maximum allowed size of %d\n", MAX_SIZE);
        return 1;
    }

    printf("Enter A number:\n");
    scanf("%f", &A);

    printf("Enter x array (size %d):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter y array (size %d):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }

    // Measure execution time of only the saxpy kernel (function)
    struct timeval start, end;
    gettimeofday(&start, NULL);

    for (int i = 0; i < REPEAT_COUNT; i++) {
        saxpy(n, A, x, y, z);
    }

    gettimeofday(&end, NULL);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) * 1e-6;

    

    // Output the results
    printf("N = %d\n", n);
    printf("A = %f\n", A);

    printf("First ten elements of Z:\n");
    for (int i = 0; i < n && i < 10; i++) {
        printf("%f\n", z[i]);
    }

    printf("Total time taken for saxpy kernel: %f seconds\n", time_taken);

    return 0;
}
