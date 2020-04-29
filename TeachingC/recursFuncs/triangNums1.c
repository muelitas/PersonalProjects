/****************************************************************
  * File:    recursFuncs.C
  * Author:  Mario Esparza
  * Date:    04/29/2020
  * Course:  ECE 131 - Programming Fundamentals
  * 
  * Program that demonstrates the following: TODO
  *     
  *
  *    
  * 
****************************************************************/ 
#include <stdio.h>

int main(){
	int tn1 = 1;
	int tn2 = 2;
	int tn3 = tn2 + tn1;
	int tn4 = tn3 + tn2;
	int tn5 = tn4 + tn3;
	printf("Fifth triangular number is: %d\n", tn5);
	return 0;
}
