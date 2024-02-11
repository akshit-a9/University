#include <stdio.h>

void bubbleSort(int array[], int n) 
{
  for (int i = 0; i < n - 1; ++i) 
  {
    for (int j = 0; j < n - i - 1; ++j) 
    {
      if (array[j] > array[j + 1]) 
      {
        int temp = array[j];
        array[j]= array[j + 1];
        array[j + 1] = temp;
      }
    }
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
  bubbleSort(data, size);
  printf("Sorted array in Acsending Order:\n");
  printArray(data, size);
}