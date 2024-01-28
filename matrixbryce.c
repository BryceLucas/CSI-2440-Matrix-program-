#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int readMatrixFromFile(const char* filename, int*** matrix, int* rows, int* cols);
void generateRandomMatrix(int*** matrix, int size);
void multiplyMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2, int*** resultMatrix);
void writeMatrixToFile(const char* filename, int** matrix, int rows, int cols);
void printMatrix(int** matrix, int rows, int cols);
void freeMatrix(int*** matrix, int rows);
int isFileFormatCorrect(const char* filename);

int main(int argc, char *argv[]) {
    srand((unsigned int)time(NULL));
        int** matrix1;
    int** matrix2;
    int** matrixResult;
    int rows1, cols1, rows2, cols2;
    
    if (argc == 3) {
        // Check if file formats are correct before proceeding
        if (!isFileFormatCorrect(argv[1]) || !isFileFormatCorrect(argv[2])) {
            fprintf(stderr, "Error: One or both files are not properly formatted as matrices.\n");
            return 1;
        }

        // Read matrices from files
        if (!readMatrixFromFile(argv[1], &matrix1, &rows1, &cols1) ||
            !readMatrixFromFile(argv[2], &matrix2, &rows2, &cols2)) {
            return 1; // Error messages handled in readMatrixFromFile
        }

        printf("Matrix 1:\n");
        printMatrix(matrix1, rows1, cols1);
        printf("\nMatrix 2:\n");
        printMatrix(matrix2, rows2, cols2);
    } else if (argc == 2) {
        int size = atoi(argv[1]);
        if (size <= 0) {
            fprintf(stderr, "Error: Invalid size for matrix generation.\n");
            return 1;
        }

        // Generate random matrices
        generateRandomMatrix(&matrix1, size);
        generateRandomMatrix(&matrix2, size);
        rows1 = cols1 = rows2 = cols2 = size;

        printf("Randomly generated Matrix 1:\n");
        printMatrix(matrix1, rows1, cols1);
        printf("\nRandomly generated Matrix 2:\n");
        printMatrix(matrix2, rows2, cols2);
    } else {
        fprintf(stderr, "Usage: %s <file1> <file2> OR %s <size>\n", argv[0], argv[0]);
        return 1;
    }

    // Check if multiplication is possible
    if (cols1 != rows2) {
        fprintf(stderr, "Error: The number of columns in the first matrix must equal the number of rows in the second matrix.\n");
        freeMatrix(&matrix1, rows1);
        freeMatrix(&matrix2, rows2);
        return 1;
    }

    // Multiply matrices
    multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2, &matrixResult);

    // Print and save result to file
    printf("\nResultant Matrix:\n");
    printMatrix(matrixResult, rows1, cols2);
    writeMatrixToFile("matrix3.txt", matrixResult, rows1, cols2);

    // Free allocated memory
    freeMatrix(&matrix1, rows1);
    freeMatrix(&matrix2, rows2);
    freeMatrix(&matrixResult, rows1);

    return 0;
}

// Function implementations

int readMatrixFromFile(const char* filename, int*** matrix, int* rows, int* cols) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s for reading.\n", filename);
        return 0;
    }

    // Read matrix dimensions
    if (fscanf(file, "%d %d", rows, cols) != 2) {
        fprintf(stderr, "Error: Could not read matrix dimensions.\n");
        fclose(file);
        return 0;
    }

    // Allocate memory for the matrix
    *matrix = (int**)malloc(*rows * sizeof(int*));
    if (!*matrix) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        fclose(file);
        return 0;
    }
    for (int i = 0; i < *rows; ++i) {
        (*matrix)[i] = (int*)malloc(*cols * sizeof(int));
        if (!(*matrix)[i]) {
            fprintf(stderr, "Error: Memory allocation failed.\n");
            // Free any previously allocated rows
            for (int j = 0; j < i; ++j) {
                free((*matrix)[j]);
            }
            free(*matrix);
            fclose(file);
            return 0;
        }
    }

    // Read matrix data
    for (int i = 0; i < *rows; ++i) {
        for (int j = 0; j < *cols; ++j) {
            if (fscanf(file, "%d", &((*matrix)[i][j])) != 1) {
                fprintf(stderr, "Error: Could not read matrix data.\n");
                // Free allocated memory
                for (int k = 0; k <= i; ++k) {
                    free((*matrix)[k]);
                }
                free(*matrix);
                fclose(file);
                return 0;
            }
        }
    }

    fclose(file);
    return 1;
}



// Check to see if file is formatted correctly 
int isFileFormatCorrect(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s.\n", filename);
        return 0;
    }
    int rows, cols;
    if (fscanf(file, "%d %d", &rows, &cols) != 2) {
        fclose(file);
        return 0;
    }

    int value, count = 0;
    while (fscanf(file, "%d", &value) == 1) {
        count++;
    }

    fclose(file);

    if (count != rows * cols) {
        return 0;
    }

    return 1;
}
void generateRandomMatrix(int*** matrix, int size) {
    
}

void multiplyMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2, int*** resultMatrix) {
    
}

void writeMatrixToFile(const char* filename, int** matrix, int rows, int cols) {
   
}

void printMatrix(int** matrix, int rows, int cols) {
   
}

void freeMatrix(int*** matrix, int rows) {
    
}

int main(int argc, char *argv[]) {
  
    return 0;
}



