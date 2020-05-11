/****************************************************************
  * File:    p03.c
  * Author:  Mario Esparza
  * Date:    05/10/2020
  * Book:    Introduction to Algorithms, 3rd Edition, by Cormen
  * 
  * In this program I am solving Exercise 2.1-4 of page 22
  * "Consider the problem of adding two n-bit binary integers,
  * stored in 2 n-element arrays A and B. The sum of the two
  * integers should be stored in binary form in an (n+1) element
  * array C".
  *
  * I create three character arrays. I use the first two to store 
  * binary numbers given by the user and a third one to store the
  * addition. I have three "function-helpers"; one to scan a 
  * character array (binary number); another one to print binary
  * numbers; and a third one to clear any leftover characters in
  * the scanning tape (terminal).
  *
****************************************************************/ 

#include <stdio.h>
char c; //used to scan characters from user

//Ensures "scanning tape" is empty and ready for next scan
void cleanScanTape(){
	while(c!='\n'){
		c = getchar();
	}
	return;
}

//Function that scans a binary number
void scanBinaryNum(int L, char arr[L]){
	int i;
	for(i=0;i<L;i++){
		c = getchar();
		arr[i] = c;
	}
	//In case user inputs more than L characters
	cleanScanTape();
	return;
}

//Function that prints a binary number
void printBinaryNum(int L, char arr[L]){
	int i;
	for(i=0; i<L; i++){
		printf("%c", arr[i]);
	}
	return;
}

//Function that adds two binary numbers (A and B)
void addBinaryNums(int L, char A[L], char B[L], char C[L+1]){
	int i;
	char carryOut='0';
	for(i=L-1;i>=0;i--){
		if(A[i]=='0' && B[i] == '0'){ // 0 + 0
			C[i+1] = carryOut;
			carryOut='0';
		}else if(A[i]=='1' && B[i] == '1'){ // 1 + 1
			C[i+1] = carryOut;
			carryOut='1';
		}else{ // 0 + 1 or 1 + 0
			if(carryOut == '1'){
				C[i+1]='0';
				carryOut = '1';
			}else{
				C[i+1]='1';
				carryOut = '0';
			}
		}
	}
	C[0] = carryOut;
	return;
}

int main(){
	//Get binary number from user
	int length;
	printf("How long will your binary numbers be? ");
	scanf("%d%c", &length, &c);
	char A[length], B[length], C[length+1];
	printf("Please input your first binary number: ");
	scanBinaryNum(length, A);
	printf("Please input your second binary number: ");
	scanBinaryNum(length, B);

	//Add binary numbers
	addBinaryNums(length, A, B, C);	

	//Print binary numbers, as well as the addition
	printBinaryNum(length, A);
	printf(" +\n"); //astetics
	printBinaryNum(length, B);
	printf("\n");
	printf("-------\n"); //astetics
	printBinaryNum(length+1, C);
	printf("\n");

	return 0;
}
