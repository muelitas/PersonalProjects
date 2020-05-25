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
//Scans integer array
void scanArray(int L, int arr[L]){
	int i;
	for(i=0;i<L;i++){
		scanf("%d", &arr[i]);
	}
	return;
}
//Prints integer array
void printArray(int L, int arr[L]){
	int i;
	for(i=0;i<L;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}
//Sorts array of integers with Selection Sort
void sort(int L, int arr[L]){
	int i, j, newIndex, min;
	for(i=0;i<L-1;i++){
		min = arr[i];
		for(j=i+1;j<L;j++){
			if(arr[j]<min){
				min = arr[j];
				newIndex = j;
			}
		}
		if(min != arr[i]){
			arr[newIndex] = arr[i];
			arr[i] = min;
		}
	}
	return;
}

int main(){
	int L;
	printf("How large is your array?\n");
	scanf("%d", &L);
	int arr[L];
	printf("Please input the values:\n");
	scanArray(L, arr);
	printf("These are the values you inputted:\n");
	printArray(L, arr);
	sort(L,arr);
	printf("Sorted, your array looks as follows:\n");
	printArray(L, arr);

	return 0;
}
