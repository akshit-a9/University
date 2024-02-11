#include <stdio.h>
void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) 
{
  for (int i = 0; i < size - 1; i++) 
  {
    int min_idx = i;
    for (int j = i + 1; j < size; j++) 
    {
      if (array[j] < array[min_idx])
        min_idx = j;
    }
    swap(&array[min_idx], &array[i]);
  }
}

void printArray(int array[], int size) 
{
  for (int i = 0; i < size; ++i) 
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() 
{
  int size;
  printf("Enter the number of elements in the array to be sorted (max 50) : \n");
  scanf("%d", &size);
  int data[50];
  for(int i = 0; i<size; i++)
  {
    printf("Enter num : ");
    scanf("%d", &data[i]);
  }
  selectionSort(data, size);
  printf("Sorted array in Acsending Order:\n");
  printArray(data, size);
}