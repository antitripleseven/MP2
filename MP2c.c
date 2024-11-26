#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> 

#define MAX_SIZE (1 << 30) 
#define REPEAT_COUNT 10000 // Number of times to repeat saxpy to amplify execution time

extern void saxpy(int n, float A, float x[], float y[], float z[]);

int main() {
    int n;
    float A;
    float *x, *y, *z;

   
    printf("Enter length of array N (max %d):\n", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Error: N exceeds the maximum allowed size of %d\n", MAX_SIZE);
        return 1;
    }

    
    x = (float *)malloc(n * sizeof(float));
    y = (float *)malloc(n * sizeof(float));
    z = (float *)malloc(n * sizeof(float));

    
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

    // for saxpy kernel
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // saxpy kernel for repeated
    for (int i = 0; i < REPEAT_COUNT; i++) {
        saxpy(n, A, x, y, z);
    }

    gettimeofday(&end, NULL);
    
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) * 1e-6;

    
    double avg_time = time_taken / REPEAT_COUNT;

    // Output the results
    printf("N = %d\n", n);
    printf("A = %f\n", A);

    // Display the first ten elements of the resulting array z
    printf("First ten elements of Z:\n");
    for (int i = 0; i < n && i < 10; i++) {
        printf("%f\n", z[i]);
    }

    printf("Time taken: %.9f seconds\n", time_taken);
    printf("Average time per saxpy call: %.9f seconds\n", avg_time);

    // Free allocated memory
    free(x);
    free(y);
    free(z);

    return 0;
}
