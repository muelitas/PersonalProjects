/****************************************************************
  * File:    recursFuncs.C
  * Author:  Mario Esparza
  * Date:    04/29/2020
  * Course:  ECE 131 - Programming Fundamentals
  * 
  * Program that demonstrates the following:
  *     
  *
  *    
  * 
****************************************************************/ 

#include <stdio.h>

int triangularN(int n){
	if(n == 1){
		return 1;
	}else{
		return(n+triangularN(n-1));
	}
}

int main(){

	//show how to calculate a tn with a loop
	//Then, show how to do it with a rec func
	long int tn = triangularN(6);
	printf("tn = %ld\n", tn);
	return 0;
}
