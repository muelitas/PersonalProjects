/****************************************************************
  * File:    p01.c
  * Author:  Mario Esparza
  * Date:    05/10/2020
  * Book:    Introduction to Algorithms, 3rd Edition, by Cormen
  * 
  * In this program I explore insertion sort. I have two sort
  * functions. One is the one I implemented on the get go and 
  * the second one is the one implmented by the book. I also
  * have two "function-helpers"; one prints an integer array,
  * the other one copies one array into another one.
  *
****************************************************************/ 

#include <stdio.h>
//Function that copies array X into Y
void copyArr(int L, int X[L], int Y[L]){
	int i;
	for(i=0; i<L; i++){
		Y[i] = X[i];
	}
	return;
}

//Function that prints an array of integers
void printArr(int L, int arr[L]){
	int i;
	for(i=0; i<L; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return;
}

//Insertion sort; method from the book
void sort2(int L, int A[L]){
	int i, j, key;
	for(j=1;j<L;j++){
		key = A[j];
		i = j - 1;
		while(i>=0 && A[i]>key){
			A[i+1] = A[i];
			i = i - 1;
		}
		A[i+1] = key;
	}
	return;
}

//Insertion sort; my method
void sort1(int L, int arr[L]){
	int i, j, k, val1, val2;
	for(i=1;i<L;i++){
		val1 = arr[i];
		k=i;
		for(j=i-1;j>=0;j--){
			val2 = arr[j];
			if(val1<val2){
				arr[k] = val2;
				arr[j] = val1;
				k--;
			}else{
				break;
			}
		}
	}
}

int main(){
	//Array given by the book in page 18
	int A[] = {5,2,4,6,1,3};
	int length = sizeof(A)/sizeof(A[0]);
	//Create copy so it can be used in second sort function
	int B[length];
	copyArr(length,A,B);

	//Print Arrays
	printf("Array A is:\n");
	printArr(length, A);
	printf("It's copy B is:\n");
	printArr(length, B);

	//Sort A with my method
	sort1(length, A);
	printf("\nSorted array with my method:\n");
	printArr(length, A);
	
	//Sort B with book's method
	sort2(length, B);
	printf("Sorted array with book's method:\n");
	printArr(length, B);

	return 0;
}
