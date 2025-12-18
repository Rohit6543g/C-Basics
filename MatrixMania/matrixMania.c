#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#define sleep(x) Sleep((x) * 1000)
#else
#include <unistd.h>
#endif

void clearScreen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
int handleAddition(void);
int handleSubtraction(void);
int handleMultiplication(void);
int handleTranspose(void);
int matrixInput(int r, int c, int[r][c]);
void matrixPrint(int r, int c, int[r][c]);
void multiply(int m, int n, int p, const int mat1[m][n], const int mat2[n][p], int res[m][p]);
void addMat(int m, int n, const int mat1[m][n], const int mat2[m][n], int res[m][n]);
void subMat(int m, int n, const int mat1[m][n], const int mat2[m][n], int res[m][n]);
void transpose(int m, int n, const int mat1[m][n], int res[n][m]);

int main()
{
    int choice = 10;
    printf("\n\n===========================================================================================================================\n");
    printf("\t\t\t\t\t -----|| MATRIX MANIA || -----\n\n");
    printf("Welcome to Matrix Mania!\n");

    while (choice)
    {
        printf("What would you like to do??\n");
        printf("1. Matrix Addition \n2. Matrix Subtraction \n3. Transpose of a Matrix \n4. Matrix Multiplication \n0. Exit\n:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
        {
            printf("Exiting program!!\n");
            sleep(2);
            printf("\n\n===========================================================================================================================\n");
            return 0;
        }
        case 1:
        {
            if (handleAddition())
                printf("Some error happened!!\n");
            break;
        }
        case 2:
        {
            if (handleSubtraction())
                printf("Some error happened!!\n");
            break;
        }
        case 3:
        {
            if (handleTranspose())
                printf("Some error happened!!\n");
            break;
        }
        case 4:
        {
            if (handleMultiplication())
                printf("Some error happened!!\n");
            break;
        }
        default:
        {
            printf("ERROR: Invalid choice! Returning to homescreen.....\n");
        }
        }
        getchar();
        printf("\n\nPress enter to go back to the Main Menu!\n");
        getchar();
        sleep(1);
        clearScreen();
    }
    return 0;
}
int handleAddition(void)
{
    // Taking input for order of matrices
    int m = 0;
    printf("Enter the rows of the matrix A(m): ");
    if (scanf("%d", &m) != 1 || m <= 0)
    {
        printf("Invalid input!\n");
        return 1;
    }
    int n = 0;
    printf("Enter the columns of the matrix A(n): ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input!\n");
        return 1;
    }

    // Allocating memory for the matrices
    int (*mat1)[n] = malloc(m * sizeof(*mat1));
    int (*mat2)[n] = malloc(m * sizeof(*mat2));
    int (*res)[n] = malloc(m * sizeof(*res));

    // Checking for memory allocation failure
    if (!mat1 || !mat2 || !res)
    {
        free(mat1);
        free(mat2);
        free(res);
        printf("ERROR: Memory allocation failed!\n");
        return 1;
    }

    // Taking input for first matrix with input caution
    printf("Enter the elements of the matrix A(m X n):\n");
    if (matrixInput(m, n, mat1))
    {
        printf("Error receiving input!\n");
        free(mat1);
        free(mat2);
        free(res);
        return 1;
    }
    // Taking input for second matrix with input caution
    printf("Enter the elements of the matrix B(m X n):\n");
    if (matrixInput(m, n, mat2))
    {
        printf("Error receiving input!\n");
        free(mat1);
        free(mat2);
        free(res);
        return 1;
    }

    // Calculating addition
    addMat(m, n, mat1, mat2, res);

    printf("The matrix A+B (mxn) will be\n");
    matrixPrint(m, n, res);

    free(mat1);
    free(mat2);
    free(res);
    return 0;
}
int handleSubtraction(void)
{
    // Taking input for order of matrices
    int m = 0;
    printf("Enter the rows of the matrix A(m): ");
    if (scanf("%d", &m) != 1 || m <= 0)
    {
        printf("Invalid input!\n");
        return 1;
    }
    int n = 0;
    printf("Enter the columns of the matrix A(n): ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input!\n");
        return 1;
    }

    // Allocating memory for the matrices
    int (*mat1)[n] = malloc(m * sizeof(*mat1));
    int (*mat2)[n] = malloc(m * sizeof(*mat2));
    int (*res)[n] = malloc(m * sizeof(*res));

    // Checking for memory allocation failure
    if (!mat1 || !mat2 || !res)
    {
        free(mat1);
        free(mat2);
        free(res);
        printf("ERROR: Memory allocation failed!\n");
        return 1;
    }

    // Taking input for first matrix with input caution
    printf("Enter the elements of the matrix A(m X n):\n");
    if (matrixInput(m, n, mat1))
    {
        printf("Error receiving input!\n");
        free(mat1);
        free(mat2);
        free(res);
        return 1;
    }
    // Taking input for second matrix with input caution
    printf("Enter the elements of the matrix B(m X n):\n");
    if (matrixInput(m, n, mat2))
    {
        printf("Error receiving input!\n");
        free(mat1);
        free(mat2);
        free(res);
        return 1;
    }

    // Calculating subtraction
    subMat(m, n, mat1, mat2, res);

    printf("The matrix A-B (mxn) will be\n");
    matrixPrint(m, n, res);

    free(mat1);
    free(mat2);
    free(res);
    return 0;
}
int handleTranspose(void)
{
    // Taking input for order of matrices
    int m = 0;
    printf("Enter the rows of the matrix A(m): ");
    if (scanf("%d", &m) != 1 || m <= 0)
    {
        printf("Invalid input!\n");
        return 1;
    }
    int n = 0;
    printf("Enter the columns of the matrix A(n): ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input!\n");
        return 1;
    }

    // Allocating memory for the matrices
    int (*mat1)[n] = malloc(m * sizeof(*mat1));
    int (*res)[m] = malloc(n * sizeof(*res));

    // Checking for memory allocation failure
    if (!mat1 || !res)
    {
        free(mat1);
        free(res);
        printf("ERROR: Memory allocation failed!\n");
        return 1;
    }

    // Taking input for first matrix with input caution
    printf("Enter the elements of the matrix A(m X n):\n");
    if (matrixInput(m, n, mat1))
    {
        printf("Error receiving input!\n");
        free(mat1);
        free(res);
        return 1;
    }
    // Calculating transpose
    transpose(m, n, mat1, res);

    printf("The matrix A transpose(nxm) will be\n");
    matrixPrint(n, m, res);

    free(mat1);
    free(res);
    return 0;
}
int handleMultiplication(void)
{
    // Taking input for order of matrices
    int m = 0;
    printf("Enter the rows of the matrix A(m): ");
    if (scanf("%d", &m) != 1 || m <= 0)
    {
        printf("Invalid input!\n");
        return 1;
    }
    int n = 0;
    printf("Enter the columns of the matrix A(n): ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input!\n");
        return 1;
    }
    int p = 0;
    printf("Enter the columns of the matrix B(p): ");
    if (scanf("%d", &p) != 1 || p <= 0)
    {
        printf("Invalid input!\n");
        return 1;
    }

    // Allocating memory for the matrices
    int (*mat1)[n] = malloc(m * sizeof(*mat1));
    int (*mat2)[p] = malloc(n * sizeof(*mat2));
    int (*res)[p] = malloc(m * sizeof(*res));

    // Checking for memory allocation failure
    if (!mat1 || !mat2 || !res)
    {
        free(mat1);
        free(mat2);
        free(res);
        printf("ERROR: Memory allocation failed!\n");
        return 1;
    }

    // Taking input for first matrix with input caution
    printf("Enter the elements of the matrix A(m X n):\n");
    if (matrixInput(m, n, mat1))
    {
        printf("Error receiving input!\n");
        free(mat1);
        free(mat2);
        free(res);
        return 1;
    }
    // Taking input for second matrix with input caution
    printf("Enter the elements of the matrix B(n X p):\n");
    if (matrixInput(n, p, mat2))
    {
        printf("Error receiving input!\n");
        free(mat1);
        free(mat2);
        free(res);
        return 1;
    }

    // Calculating multiplication
    multiply(m, n, p, mat1, mat2, res);

    printf("The matrix AXB (mxp) will be\n");
    matrixPrint(m, p, res);

    free(mat1);
    free(mat2);
    free(res);
    return 0;
}
void multiply(int m, int n, int p, const int mat1[m][n], const int mat2[n][p], int res[m][p])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transpose(int m, int n, const int mat1[m][n], int res[n][m])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[j][i] = mat1[i][j];
        }
    }
}

void addMat(int m, int n, const int mat1[m][n], const int mat2[m][n], int res[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subMat(int m, int n, const int mat1[m][n], const int mat2[m][n], int res[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

int matrixInput(int r, int c, int mat[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("At idx(%d,%d): ", i + 1, j + 1);
            if (scanf("%d", &mat[i][j]) != 1)
            {
                printf("Invalid input at (%d,%d)\n", i + 1, j + 1);
                return 1;
            }
        }
    }
    return 0;
}

void matrixPrint(int r, int c, int mat[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%4d  ", mat[i][j]);
        }
        printf("\n\n");
    }
}
