/****************************************************************
  * File:    p04.c
  * Author:  Mario Esparza
  * Date:    05/25/2020
  * Book:    Introduction to Algorithms, 3rd Edition, by Cormen
  * 
  * In this program I am solving selection sort, specified in 
  * Exercise 2.2-2 of page 29. In addition to sorting function,
  * I created two "function-helpers" as well; one that scans an
  * integer array and another one that prints it. 
  *
****************************************************************/ 
#include <stdio.h>
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
	selection_sort(L,arr);
	printf("Sorted, your array looks as follows:\n");
	printArray(L, arr);

	return 0;
}
