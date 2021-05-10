#include "hf.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

void text()
{
    FILE *fp1;
    FILE *fp2;
    fp1 = fopen("text1.txt", "w");
    fp2 = fopen("text2.txt", "w");
    int i, j;
    srand(time(NULL));
    for(i = 0;i< 1000000;i ++)
    {
        fprintf(fp1, "%d\n", rand());
    }
    for(i = 0;i< 1000000;i ++)
    {
        for(j = 0;j < 100;j ++)
        {
            fprintf(fp2, "%c", rand() % 26 + 'a');
        }
        fprintf(fp2, "\n");
    }
    fclose(fp1);
    fclose(fp2);
}

int partition(int number[], int left, int right) {
    int i = left - 1;
    int j;
    int temp;
    for(j = left; j < right; j++) {
        if(number[j] <= number[right]) {
            i++;
            temp = number[i];
            number[i] = number[j];
            number[j] = temp;
        }
    }

    temp = number[i + 1];
    number[i + 1] = number[right];
    number[right] = temp;
    return i+1;
}

void quicksort(int number[], int left, int right) {
    if(left < right) {
        int q = partition(number, left, right);
        quicksort(number, left, q-1);
        quicksort(number, q+1, right);
    }
}

void merge(int arr[], int head, int mid, int tail){
  int lenA = mid - head + 1;
  int lenB = tail - (mid + 1) + 1;
  int A[lenA];
  int B[lenB];
  int i, j, k;
  for(i = 0; i < lenA; i++){
    A[i] = arr[head + i];
  }
  for(j = 0; j < lenB; j++){
    B[j] = arr[mid + 1 + j];
  }
  i = 0;
  j = 0;
  k = head;
  while(i < lenA && j < lenB){
    if(A[i] < B[j]){
      arr[k] = A[i];
      i++;
    }
    else{
      arr[k] = B[j];
      j++;
    }
    k++;
  }
  while(i < lenA){
    arr[k] = A[i];
    i++;
    k++;
  }
  while(j < lenB){
    arr[k] = B[j];
    j++;
    k++;
  }
}
void mergesort(int arr[], int head, int tail){
  if(head < tail){
    int mid = (head + tail) / 2;
    mergesort(arr, head, mid);
    mergesort(arr, mid+1, tail);
    merge(arr, head, mid, tail);
  }
}

int findLargestNum(int array[], int size){

  int i;
  int largestNum = -1;

  for(i = 0; i < size; i++){
    if(array[i] > largestNum)
      largestNum = array[i];
  }

  return largestNum;
}

void radixsort(int array[], int size){
  int i;
  int semiSorted[size];
  int significantDigit = 1;
  int largestNum = findLargestNum(array, size);
  while (largestNum / significantDigit > 0){

    int bucket[10] = { 0 };
    for (i = 0; i < size; i++)
      bucket[(array[i] / significantDigit) % 10]++;
    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];
    for (i = size - 1; i >= 0; i--)
      semiSorted[--bucket[(array[i] / significantDigit) % 10]] = array[i];


    for (i = 0; i < size; i++)
      array[i] = semiSorted[i];

    significantDigit *= 10;
  }
}
