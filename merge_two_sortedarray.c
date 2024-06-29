#include <stdio.h>
#include <stdlib.h>
void mergeArrays(int arr1[], int arr2[], int n1, int n2, int mergedArray[]) 
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) 
    {
        if (arr1[i] <= arr2[j]) 
        {
            mergedArray[k] = arr1[i];
            i++;
        } 
        else 
        {
            mergedArray[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1) 
    {
        mergedArray[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        mergedArray[k] = arr2[j];
        j++;
        k++;
    }
}
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int n1, n2;
    printf("Enter the number of elements in the first sorted array: ");
    scanf("%d", &n1);
    int *arr1 = (int *)malloc(n1 * sizeof(int));
    printf("Enter the elements of the first sorted array: ");
    for (int i = 0; i < n1; i++) 
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the number of elements in the second sorted array: ");
    scanf("%d", &n2);
    int *arr2 = (int *)malloc(n2 * sizeof(int));
    printf("Enter the elements of the second sorted array: ");
    for (int i = 0; i < n2; i++) 
    {
        scanf("%d", &arr2[i]);
    }
    int *mergedArray = (int *)malloc((n1 + n2) * sizeof(int));
    mergeArrays(arr1, arr2, n1, n2, mergedArray);
    printf("Merged array: ");
    printArray(mergedArray, n1 + n2);
    free(arr1);
    free(arr2);
    free(mergedArray);
    return 0;
}
