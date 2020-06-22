/****************************************************************
  * File:    p07.c
  * Author:  Mario Esparza
  * Date:    05/29/2020
  * Book:    Introduction to Algorithms, 3rd Edition, by Cormen
  * 
  * In this program I implement linear search through an integer
  * array (Exercise 2.1-3) and I implement Recursive Binary
  * Search (Exercise 2.3-5). In addition to my linear and binary
  * search functions, I also have printArray, scanArray, merge
  * and merge_sort. Both searches are programmed, so that if the
  * number isn't in the array, they return -1.
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

	int v;
	printf("Which value are you interested in searching for?\n");
	scanf("%d", &v);

	printf("Linear Search:\n");
	int index = linear_search(L, arr, v);
	if(index == -1){
		printf("\t%d was not found in the given array\n", v);
	}else{
		printf("\tIn your array, %d was found at index %d\n", v, index);
	}

	printf("Binary Search:\n");
	merge_sort_rec(arr, 0, L-1); //sort array using Merge-Sort
	printf("\tSorted Array: ");
	printArray(L, arr);
	index = binary_search_rec(arr, 0, L-1, v);
	if(index == -1){
		printf("\t%d was not found in the given array\n", v);
	}else{
		printf("\tIn your array, %d was found at index %d\n", v, index);
	}
	return 0;
}
