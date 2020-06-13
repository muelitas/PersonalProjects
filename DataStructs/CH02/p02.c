/****************************************************************
  * File:    p02.c
  * Author:  Mario Esparza
  * Date:    05/10/2020
  * Book:    Introduction to Algorithms, 3rd Edition, by Cormen
  * 
  * In this program I am solving Exercise 2.1-2 of page 22
  * "Rewrite insertion-sort procedure to sort into decreasing
  * order rather than increasing order." I ask user for length n
  * of array; calculate n random numbers (from 0 to 1000); sort
  * array in decreasing order. I am using two "function-helpers";
  * one to populate array; another one to print array.
  *
****************************************************************/ 

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "ch2Funcs.h"

int main(){
	int length;
	printf("How many values would you like your array to have? ");
	scanf("%d", &length);
	int A[length];
	populateArray(length, A);

	//Print Array
	printf("Array A is:\n");
	printArray(length, A);

	//Sort Array and Print Again
	insert_sort_back(length, A);
	printf("Sorted in descending order:\n");
	printArray(length, A);

	return 0;
}
