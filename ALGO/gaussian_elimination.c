#include <stdio.h>
#include <stdlib.h>

// Solving Ax = b using Gauss Elimination
#define ROWS 3
#define COLS 3

void print_mat(int rows, int cols, float* A);
void augment(int rows, int cols, float A[rows][cols], float b[cols], float aug[rows][cols + 1]);
void row_op(int rows, int cols, float matrix[rows][cols], float factor_a, int target_row,
            float factor_b, int source_row);
void gaussian_elim(int rows, int cols, float aug[rows][cols]);
float* back_sub(int rows, int cols, float A[rows][cols]);

int gaussian_elimination_program(void)
{
    float A[ROWS][COLS] = {{1.0, 1.0,  1.0},
                           {0.0, 2.0,  5.0},
                           {2.0, 5.0, -1.0}};
    float b[ROWS] = {6.0, -4.0, 27.0};
    float aug[ROWS][COLS + 1] = {0};

    augment(ROWS, COLS, A, b, aug);
    print_mat(ROWS, COLS + 1, *aug);

    gaussian_elim(ROWS, COLS + 1, aug);
    print_mat(ROWS, COLS + 1, *aug);

    float* ans = back_sub(ROWS, COLS + 1, aug);
    print_mat(1, COLS, ans);

    free(ans);
    return 0;
}

void augment(int rows, int cols, float A[rows][cols], float b[cols], float aug[rows][cols + 1])
{
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            aug[i][j] = A[i][j];
        }
        aug[i][cols] = b[i];
    }
}

void gaussian_elim(int rows, int cols, float aug[rows][cols])
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = i + 1; j < rows; j++)
        {
            if (aug[j][i] != 0.0f)
                row_op(rows, cols, aug, aug[i][i], j, -aug[j][i], i);
        }
    }
}

void row_op(int rows, int cols,
            float matrix[rows][cols], float factor_a,
            int target_row, float factor_b,
            int source_row)
{
    int i;
    for (i = 0; i < cols; i++) {
        matrix[target_row][i] = factor_a * matrix[target_row][i] + factor_b * matrix[source_row][i];
    }
}

float* back_sub(int rows, int cols, float A[rows][cols])
{
    float* xs = (float*)malloc(rows * sizeof(float));
    int i, j;
    for (i = rows - 1; i >= 0; i--)
    {
        float sum = 0.0f;

        for (j = i + 1; j < cols - 1; j++)
        {
            sum += A[i][j] * xs[j];
        }
        xs[i] = (A[i][cols - 1] - sum) / A[i][i];
    }
    return xs;
}

void print_mat(int rows, int cols, float* A)
{
    int i, j;
    printf("\n[%d x %d]\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%.2f\t", *(A + (i * cols) + j));
        }
        printf("\n");
    }
}
