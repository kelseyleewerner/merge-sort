#include <stdio.h>

#define SIZE 10

void mergesort(int * arr, int lo, int hi);
void merge(int * arr, int lo1, int hi1, int lo2, int hi2);



int main()
{
  int arr[SIZE] = {54, 6, 22, 8, 0, 11, 44, 3, 11, 10};

  mergesort(arr, 0, SIZE - 1);

  printf("SORTED ARRAY:\n");
  for(int i = 0; i < SIZE; ++i)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}



void mergesort(int * arr, int lo, int hi)
{
  int mid;

  if (lo < hi) {
    mid = (lo + hi) / 2;
    mergesort(arr, lo, mid);
    mergesort(arr, mid + 1, hi);
    merge(arr, lo, mid, mid + 1, hi);
  }
}




void merge(int * arr, int lo1, int hi1, int lo2, int hi2)
{
  int temp[SIZE];
  int c1 = lo1;
  int c2 = lo2;
  int t_index = 0;
  int i, j;

  while (c1 <= hi1 && c2 <=hi2) {
    if (arr[c1] < arr[c2])
      temp[t_index++] = arr[c1++];
    else
      temp[t_index++] = arr[c2++];
  }

  while (c1 <= hi1)
    temp[t_index++] = arr[c1++];

  while (c2 <= hi2)
    temp[t_index++] = arr[c2++];

  for (i = lo1, j = 0; i <= hi2; ++i, ++j)
    arr[i] = temp[j];
}











