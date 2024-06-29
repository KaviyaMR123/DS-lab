#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int row;
    int col;
    int value;
} Element;
typedef struct
{
    int rows;
    int cols;
    int numElements;
    Element *elements;
} SparseMatrix;
SparseMatrix createSparseMatrix(int rows, int cols, int numElements) 
{
    SparseMatrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.numElements = numElements;
    matrix.elements = (Element*)malloc(numElements * sizeof(Element));
    return matrix;
}
void inputSparseMatrix(SparseMatrix *matrix) 
{
    printf("Enter the non-zero elements (row, column, value):\n");
    for (int i = 0; i < matrix->numElements; i++) 
    {
        scanf("%d %d %d", &matrix->elements[i].row, &matrix->elements[i].col, &matrix->elements[i].value);
    }
}
void displaySparseMatrix(SparseMatrix matrix) 
{
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < matrix.numElements; i++) 
    {
        printf("%d\t%d\t%d\n", matrix.elements[i].row, matrix.elements[i].col, matrix.elements[i].value);
    }
}
SparseMatrix transposeSparseMatrix(SparseMatrix matrix) 
{
    SparseMatrix transpose = createSparseMatrix(matrix.cols, matrix.rows, matrix.numElements);
    int k = 0;
    for (int i = 0; i < matrix.cols; i++)
    {
        for (int j = 0; j < matrix.numElements; j++) 
        {
            if (matrix.elements[j].col == i)
            {
                transpose.elements[k].row = matrix.elements[j].col;
                transpose.elements[k].col = matrix.elements[j].row;
                transpose.elements[k].value = matrix.elements[j].value;
                k++;
            }
        }
    }
    return transpose;
}
SparseMatrix addSparseMatrices(SparseMatrix matrix1, SparseMatrix matrix2)
{
    if (matrix1.rows != matrix2.rows || matrix1.cols != matrix2.cols)
    {
        printf("Matrices cannot be added due to different dimensions.\n");
        exit(1);
    }
    SparseMatrix sum = createSparseMatrix(matrix1.rows, matrix1.cols, matrix1.numElements + matrix2.numElements);
    int i = 0, j = 0, k = 0;
    while (i < matrix1.numElements && j < matrix2.numElements) 
    {
        if (matrix1.elements[i].row < matrix2.elements[j].row || 
            (matrix1.elements[i].row == matrix2.elements[j].row && matrix1.elements[i].col < matrix2.elements[j].col)) 
            {
            sum.elements[k++] = matrix1.elements[i++];
        } 
        else if (matrix1.elements[i].row > matrix2.elements[j].row || 
                   (matrix1.elements[i].row == matrix2.elements[j].row && matrix1.elements[i].col > matrix2.elements[j].col)) 
                   {
            sum.elements[k++] = matrix2.elements[j++];
        } 
        else 
        {
            sum.elements[k] = matrix1.elements[i];
            sum.elements[k++].value = matrix1.elements[i++].value + matrix2.elements[j++].value;
        }
    }

    while (i < matrix1.numElements) 
    {
        sum.elements[k++] = matrix1.elements[i++];
    }
    while (j < matrix2.numElements) 
    {
        sum.elements[k++] = matrix2.elements[j++];
    }
    sum.numElements = k;
    return sum;
}
int main() 
{
    int rows, cols, numElements;
    printf("Enter the number of rows and columns for the sparse matrix: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter the number of non-zero elements for the first matrix: ");
    scanf("%d", &numElements);
    SparseMatrix matrix1 = createSparseMatrix(rows, cols, numElements);
    printf("Enter the elements of the first matrix:\n");
    inputSparseMatrix(&matrix1);
    printf("Enter the number of non-zero elements for the second matrix: ");
    scanf("%d", &numElements);
    SparseMatrix matrix2 = createSparseMatrix(rows, cols, numElements);
    printf("Enter the elements of the second matrix:\n");
    inputSparseMatrix(&matrix2);
    printf("\nFirst Sparse Matrix:\n");
    displaySparseMatrix(matrix1);
    printf("\nSecond Sparse Matrix:\n");
    displaySparseMatrix(matrix2);
    SparseMatrix sum = addSparseMatrices(matrix1, matrix2);
    printf("\nSum of Sparse Matrices:\n");
    displaySparseMatrix(sum);
    SparseMatrix transpose1 = transposeSparseMatrix(matrix1);
    printf("\nTranspose of the First Sparse Matrix:\n");
    displaySparseMatrix(transpose1);
    free(matrix1.elements);
    free(matrix2.elements);
    free(sum.elements);
    free(transpose1.elements);
    return 0;
}
