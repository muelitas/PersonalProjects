/****************************************************************
  * File:    ch2Funcs.h
  * Author:  Mario Esparza
  * Date:    05/29/2020
  * Book:    Introduction to Algorithms, 3rd Edition, by Cormen
  * 
  * This header file will contain those functions created in
  * Chapter 2. TODO list functions.
****************************************************************/ 
#ifndef CH2_FUNCS //Ensure compiler reads header file only once
#define CH2_FUNCS
/***********************************************************/
//BASIC FUNCTIONS TO DEAL WITH ARRAYS
//Function that copies integer array X into Y
void copyArray(int L, int X[L], int Y[L]);
//Scans integer array
void scanArray(int L, int arr[L]);
//Prints integer array
void printArray(int L, int arr[L]);
//Function that creates random integers and stores them in array
void populateArray(int L, int A[L]);

/***********************************************************/
//SORTING FUNCTIONS
//Insertion sort; method from the book
void insert_sort_book(int L, int A[L]);
//Sort in decreasing order
void insert_sort_back(int L, int A[L]);
//Insertion sort; my method
void insert_sort_mine(int L, int arr[L]);
//Method used in insert_sort_mine_rec
void insertSortRec(int A[], int end);
//Insertion-sort Recursively; my method
void insert_sort_mine_rec(int A[], int end);
//Sorts array of integers with Selection Sort
void selection_sort(int L, int arr[L]);
//Merge procedure for Merge Sort
void merge(int A[], int p, int q, int r);
//Merge-Sort recursive function
void merge_sort_rec(int A[], int p, int r);

/***********************************************************/
//SEARCHING ALGORITHMS
//Linear Search; L=array's length; v=value of interest
int linear_search(int L, int A[L], int v);
//Recursive Binary Search; s = start; e = end
int binary_search_rec(int A[], int s, int e, int v);
#endif
