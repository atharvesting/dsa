#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_POINTS 5

struct Point {
    float x;
    float y;
};

int lagrange_interpolation(void) {
    int i, j, k;
    struct Point points[NUM_POINTS] = {{2, 3}, {4, 43}, {5, 138}, {7, 778}, {8, 1515}};
    float final[NUM_POINTS] = {0};

    printf("Lagrange Interpolation Begins!\n");

    // For each lagrange term L_i
    for (i = 0; i < NUM_POINTS; i++)
    {
        float lagrange[NUM_POINTS] = {0};
        lagrange[0] = 1;

        // Build the coefficient
        float coefficient = points[i].y;
        for (j = 0; j < NUM_POINTS; j++)
            if (i != j) coefficient /= (points[i].x - points[j].x);

        printf("Coefficient for l%d = %f\n", i, coefficient);
        int degree = 0;

        // For each point
        for (j = 0; j < NUM_POINTS; j++)
        {
            // ...except the focus point
            if (j == i) continue;

            float tmp[NUM_POINTS] = {0};
            float pt[2] = {-points[j].x, 1};

            int a, b;
            for (a = 0; a <= degree; a++)
            {
                for (b = 0; b < 2; b++)
                {
                    tmp[a + b] += lagrange[a] * pt[b];
                }
            }
            memcpy(lagrange, tmp, sizeof(tmp));
            degree++;
        }
        printf("\nLagrange so far: ");
        for (k = 0; k < NUM_POINTS; k++)
            printf("%f\t", lagrange[k]);

        // Multiply lagrange term by coefficient
        for (j = 0; j < NUM_POINTS; j++) lagrange[j] *= coefficient;

        // Add lagrange polynomial to final polynomial
        for (j = 0; j < NUM_POINTS; j++) final[j] += lagrange[j];

    }
    printf("\n");
    for (i = NUM_POINTS - 1; i >= 0; i--) {
        if (i == 0) {
            printf("%f\n", final[i]);
            break;
        }
        printf("%fx^%d + ", final[i], i);
    }

    return 0;
}

int main() {
    // int i, j;
    // int f[] = {20, -9, 1};
    // int g[] = {-6, 1};
    // int c[4] = {0};

    // for (i = 0; i < 3; i++) {
    //     for (j = 0; j < 2; j++) {
    //         c[i + j] += f[i] * g[j];
    //     }
    // }

    // for (i = 4 - 1; i >= 0; i--) {
    //     if (i == 0) {
    //         printf("%d\n", c[i]);
    //         break;
    //     }
    //     printf("%dx^%d + ", c[i], i);
    // }

    lagrange_interpolation();

    return 0;
}
