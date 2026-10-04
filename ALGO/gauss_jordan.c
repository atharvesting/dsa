#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void augment(int rows, int cols, float A[rows][cols], float b[cols], float aug[rows][cols + 1])
{
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            aug[i][j] = A[i][j];
        }
    }
    for (i = 0; i < cols; i++) {
        aug[i][cols] = b[i];
    }
}

void print_matrix(int rows, int cols, float mat[rows][cols])
{
    int i, j;
    printf("\n[%d x %d]\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%.2f\t", mat[i][j]);
        }
        printf("\n");
    }
}

void row_op(int rows, int cols, float mat[rows][cols], float factor_a, int r_a, float factor_b, int r_b)
{
    int i;
    for (i = 0; i < cols; i++) {
        mat[r_a][i] = factor_a * mat[r_a][i] - factor_b * mat[r_b][i];
    }
}

void gauss_jordan(int rows, int cols, float mat[rows][cols])
{
    int i, j;
    for (i = 0; i < cols - 1; i++)
    {
        for (j = i + 1; j < rows; j++)
        {
            if (mat[j][i] != 0)
                row_op(rows, cols, mat, mat[i][i], j, mat[j][i], i);
        }
    }

    for (i = cols - 2; i > 0; i--)
    {
        for (j = i - 1; j >= 0; j--)
        {
            if (mat[j][i] != 0)
                // printf("%.2f\n", mat[j][i]);
                row_op(rows, cols, mat, mat[i][i], j, mat[j][i], i);
        }
    }
    for (i = 0; i < rows; i++)
    {
        float tmp = mat[i][i];
        mat[i][i] /= tmp;
        mat[i][cols - 1] /= tmp;
    }
}

int gauss_jordan_program()
{
    float A[ROWS][COLS] = {{1.0, 1.0,  1.0},
                           {0.0, 2.0,  5.0},
                           {2.0, 5.0, -1.0}};
    float b[3] = {6.0, -4.0, 27.0};
    float aug[ROWS][COLS + 1] = {0};

    augment(ROWS, COLS, A, b, aug);
    print_matrix(ROWS, COLS + 1, aug);

    gauss_jordan(ROWS, COLS + 1, aug);
    print_matrix(ROWS, COLS + 1, aug);

    int i;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("x%d = %.2f\n", i, aug[i][COLS]);
    }

    return 0;
}
