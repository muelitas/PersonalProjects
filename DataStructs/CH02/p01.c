/****************************************************************
  * File:    p01.c
  * Author:  Mario Esparza
  * Date:    05/10/2020
  * Book:    Introduction to Algorithms, 3rd Edition, by Cormen
  * 
  * In this program I explore insertion sort. I have two sort
  * functions. One is the one I implemented on the get go and 
  * the second one is the one implmented by the book. I also
  * have three "function-helpers"; printArray, scanArray and
  * copyArray.
  *
****************************************************************/ 

#include <stdio.h>
#include "ch2Funcs.h"
int main(){
	//Array given by the book in page 18 is {5,2,4,6,1,3};
	int L;
	printf("How large is your array?\n");
	scanf("%d", &L);
	int A[L];
	printf("Please input the values:\n");
	scanArray(L, A);

	//Create copy so it can be used in second sort function
	int B[L];
	copyArray(L,A,B);

	//Print Arrays
	printf("Array A is:\n");
	printArray(L, A);
	printf("It's copy B is:\n");
	printArray(L, B);

	//Sort A with my method
	insert_sort_mine(L, A);
	printf("\nSorted array with my method:\n");
	printArray(L, A);
	
	//Sort B with book's method
	insert_sort_book(L, B);
	printf("Sorted array with book's method:\n");
	printArray(L, B);

	return 0;
}
