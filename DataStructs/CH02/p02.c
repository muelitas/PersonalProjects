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

//Function that prints an array of integers
void printArr(int L, int arr[L]){
	int i;
	for(i=0; i<L; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return;
}

//Sort in decreasing order
void sort(int L, int A[L]){
	int i, j, key;
	for(j=L-2;j>=0;j--){
		key = A[j];
		i = j + 1;
		while(i<L && A[i]>key){
			A[i-1] = A[i];
			i = i + 1;
		}
		A[i-1] = key;
	}
	return;
}

//Function that creates random integers and stores them in array
void populateArr(int L, int A[L]){
	srand(time(0)); //set different seed every time program runs
	int i;
	for(i=0; i<L; i++){
		A[i] = rand()%1001;
		//using "%1001" to limit numbers between 0 and 1000
	}
	return;
}

int main(){
	int length;
	printf("How many values would you like your array to have? ");
	scanf("%d", &length);
	int A[length];
	populateArr(length, A);

	//Print Array
	printf("Array A is:\n");
	printArr(length, A);

	//Sort Array and Print Again
	sort(length, A);
	printf("Sorted in descending order:\n");
	printArr(length, A);

	return 0;
}
