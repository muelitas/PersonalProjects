/****************************************************************
  * File:    ch2Funcs.c
  * Author:  Mario Esparza
  * Date:    05/30/2020
  * Book:    Introduction to Algorithms, 3rd Edition, by Cormen
  * 
  * This file contains functions definitions that were used in
  * Chapter 2. TODO list functions.
****************************************************************/ 
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "ch2Funcs.h"

//Function that copies integer array X into Y
void copyArray(int L, int X[L], int Y[L]){
	int i;
	for(i=0; i<L; i++){
		Y[i] = X[i];
	}
	return;
}
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
//Function that creates random integers and stores them in array
void populateArray(int L, int A[L]){
	srand(time(0)); //set different seed every time program runs
	int i;
	for(i=0; i<L; i++){
		A[i] = rand()%1001;
		//using "%1001" to limit numbers between 0 and 1000
	}
	return;
}
//Insertion sort; method from the book
void insert_sort_book(int L, int A[L]){
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
//Sort in decreasing order; tweaked the increasing-order-version of the book
void insert_sort_back(int L, int A[L]){
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
//Insertion sort; my method
void insert_sort_mine(int L, int arr[L]){
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
//Where the insertion-sorting happens
void insertSortRec(int A[], int end){
	int a = A[end],i;
	for(i=end-1; i>=0;i--){
		if(A[end]<A[i]){
			A[end] = A[i];
			end = i;
			A[i] = a;
		}
	}
	return;
}
//Insertion-sort Recursively; my method
void insert_sort_mine_rec(int A[], int end){
	if(end!=0){
		insert_sort_mine_rec(A, end - 1);
		insertSortRec(A, end);
	}else{
		return;
	}
}
//Sorts array of integers with Selection Sort
void selection_sort(int L, int arr[L]){
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
//Merge procedure for Merge Sort
void merge(int A[], int p, int q, int r){
	int l = 0, r_ = 0,i;
	int L[q-p+1];
	int R[r-q];
	//Create arrays of left and right values of A
	for(i=p;i<=q;i++){
		L[l] = A[i];
		l++;
	}
	for(i=q+1;i<=r;i++){
		R[r_] = A[i];
		r_++;
	}
	l = 0;
	r_ = 0;
	//Merge
	for(i=p; i<=r; i++){
		if(L[l] < R[r_]){
			A[i] = L[l];
			l++;
			//If L doesn't have any more values, only care about R
			if(l>=(q-p+1)){
				i++;
				while(i<=r){
					A[i] = R[r_];
					r_++;
					i++;
				}
			}
		}else{
			A[i] = R[r_];
			r_++;
			//If R doesn't have any more values, only care about L
			if(r_>=(r-q)){
				i++;
				while(i<=r){
					A[i] = L[l];
					l++;
					i++;
				}
			}
		}
	}
	return;
}
//Merge-Sort recursive function
void merge_sort_rec(int A[], int p, int r){
	if(p<r){
		int q = floor((p+r)/2);
		merge_sort_rec(A, p, q);
		merge_sort_rec(A, q+1, r);
		merge(A,p,q,r);
	}else{
		return;
	}
}
//Linear Search; L=array's length; v=value of interest
int linear_search(int L, int A[L], int v){
	int i, ind = -1;
	for(i=0;i<L;i++){
		if(A[i] == v){
			ind = i;
			break;
		}
	}
	return ind;
}
//Recursive Binary Search; s = start; e = end
int binary_search_rec(int A[], int s, int e, int v){
	int dummy;
	if(s<=e){
		int m = s + (e - s)/2;
		if(A[m] == v){
			return m;
		}else{
			if(A[m] < v){
				s = m + 1;
				dummy = binary_search_rec(A, s, e, v);
			}else{
				e = m - 1;
				dummy = binary_search_rec(A, s, e, v);
			}
		}
	}else{
		//v was not found in array
		return -1;
	}
}

