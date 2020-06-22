/****************************************************************
  * File:    p05.c
  * Author:  Mario Esparza
  * Date:    05/25/2020
  * Book:    Introduction to Algorithms, 3rd Edition, by Cormen
  * 
  * With the help of pages 30 - 34, I created the merge sort
  * algorithm (with some personal tweaks). Composed of two
  * functions (merge_sort and merge), it grabs an integer array
  * and sorts its values. As usual, also using two "function-
  * helpers"; printArray and scanArray. This program can be used
  * to solve excercise 2.3-1. Without knowing, I did excercise
  * 2.3-2.
  *
****************************************************************/ 
#include <stdio.h>
#include <math.h>
#include "ch2Funcs.h"

int main(){
	int L;
	printf("How large is your array?\n");
	scanf("%d", &L);
	int arr[L];
	printf("Please input the values:\n");
	scanArray(L, arr);

	printf("These are the values you inputted:\n");
	printArray(L, arr);

	merge_sort_rec(arr, 0, L-1);
	printf("Sorted, your array looks as follows:\n");
	printArray(L, arr);

	return 0;
}
