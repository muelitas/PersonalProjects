/****************************************************************
  * File:    notes.c
  * Author:  Mario Esparza
  * Date:    05/01/2020
  * Book:    A Tour of C++
  * 
  * Any clarifications that I need will be tested and registered
  * here. Notes that I thinks worth highlighting, will also be 
  * registered here. Mostly, I will be checking which features
  * of C++ also apply to C.
  * 
****************************************************************/ 
#include <stdio.h>

void print(int x){
	printf("Using int x function\n");
	printf("x = %d\n", x);
	return;
}
void print(double x){
	printf("Using double x function\n");
	printf("x = %lf\n", x);
	return;
}
void print(char x){
	printf("Using char x function\n");
	printf("x = %c\n", x);
	return;
}

int main(){

	//Checking if double can be initialized with {}
	//int d {0.5};
	//printf("d = %ld\n", d);
	//It can't, only in C++.

	//Checking if unary operator also works in C
	int x = 5;
	printf("Using negative unary with x, = %d\n", -x);

	/*Functions can't share the same name in C. Even
	if they have different arguments. In C++
	however, they can.*/
	print(42);
	print(53.5);
	print('c');
	return 0;
}
