/****************************************************************
  * File:    p08.c
  * Author:  Mario Esparza
  * Date:    06/13/2020
  * Book:    Introduction to Algorithms, 3rd Edition, by Cormen
  * 
  * Back in p01.c I implemented two versions of insertion sort
  * (one was my version, the other one the book's). To solve
  * Exercise 2.3-6 I will use my version, removing some un-
  * necessary variables. Btw, this exercise is about implemen-
  * ting binary search inside insertion sort to see if we can
  * make it nlogn.
  *
  * I use both methods (insertion sort + binary search and
  * insert sort + linear search) and there is not difference.
  * With 1,000,000 samples, both algorithms finished the task
  * in essentially the same time. Thus, no, adding binary search
  * does not make insert sort into nlogn.
****************************************************************/ 

#include <stdio.h>
#include <time.h>
#include "ch2Funcs.h"

//Recursive Binary Search; s = start; e = end
int binary_search(int A[], int s, int e, int v, int i1){
	int dummy;
	int m = s + (e - s)/2;
	if(i1 == m){
		return m;
	}else{
		i1 = m;
		if(A[m] < v){
			s = m + 1;
			dummy = binary_search(A, s, e, v, i1);
		}else{
			e = m - 1;
			dummy = binary_search(A, s, e, v, i1);
		}
	}
}
//Insertion sort, using binary search to ensure nlogn
void insert_sort_nlogn(int L, int arr[L]){
	int i, j, index, val;
	for(i=0;i<L;i++){
		index = binary_search(arr, 0, i, arr[i], -1);
		val = arr[i];
		for(j = i; j>index; j--){
			arr[j] = arr[j-1];
		}
		arr[index] = val;
	}
}

int main(){
	clock_t start, end;
	double elapsed_time;
	int num;
	printf("How many values does your array have?");
	scanf("%d", &num);
	int arr[num], arr2[num];
	populateArray(num, arr);
	copyArray(num, arr, arr2);

	//Print values in arrays
	//printf("These are the values of your array1:\n");
	//printArray(num, arr);
	//printf("These are the values of your array2:\n");
	//printArray(num, arr2);

	//Sort first array using insert_sort_mine + binary_search
	start = clock();
	insert_sort_nlogn(num, arr);
	end = clock();
	elapsed_time = ((double)end - (double)start)/CLOCKS_PER_SEC;
	printf("Insert Sort + Binary Search took %lf seconds\n", elapsed_time);
//	printf("These are the sorted values of your array1:\n");
//	printArray(num, arr);

	//Sort second array using insert sort of book (Section 2.1)
	start = clock();
	insert_sort_nlogn(num, arr2);
	end = clock();
	elapsed_time = ((double)end - (double)start)/CLOCKS_PER_SEC;
	printf("Insert Sort alone took %lf seconds\n", elapsed_time);
//	printf("These are the sorted values of your array2:\n");
//	printArray(num, arr2);

	return 0;
}
