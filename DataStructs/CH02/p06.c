/****************************************************************
  * File:    p06.c
  * Author:  Mario Esparza
  * Date:    05/29/2020
  * Book:    Introduction to Algorithms, 3rd Edition, by Cormen
  * 
  * This program is the answer to Excercise 2.3-4. I implement
  * insertion sort once again, but this time recursively. With
  * the aid of two "function-helpers" (scanArray and printArray).
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

	insert_sort_mine_rec(arr, L-1);
	printf("Sorted, these are the values you inputted:\n");
	printArray(L, arr);

	return 0;
}
