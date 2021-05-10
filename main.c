#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hf.h"

int number1[1000000], number2[1000000], number3[1000000];

int main()
{
	text();	
	char a[102];
  FILE *fp1;
  fp1 = fopen("text1.txt", "r");
  int i;
    for(i = 0;i < 1000000;i ++)
    {
        fgets(a, 102, fp1);
        sscanf(a, "%d", &number1[i]);
        number2[i] = number1[i];
        number3[i] = number1[i];
    }
    struct timeval tv_begin, tv_end;
    gettimeofday(&tv_begin, NULL);
    quicksort(number1, 0, 1000000 - 1);
    gettimeofday(&tv_end, NULL);
    printf("quick sort(int): %d", tv_end.tv_usec - tv_begin.tv_usec);
    gettimeofday(&tv_begin, NULL);
    mergesort(number2, 0, 1000000 - 1);
    gettimeofday(&tv_end, NULL);
    printf("merge sort(int): %d", tv_end.tv_usec - tv_begin.tv_usec);
    gettimeofday(&tv_begin, NULL);
    radixsort(number3, 1000000);
    gettimeofday(&tv_end, NULL);
    printf("radix sort(int): %d", tv_end.tv_usec - tv_begin.tv_usec);
}
