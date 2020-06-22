/****************************************************************
  * File:    07_funcs_prototyping.C
  * Author:  Mario Esparza
  * Date:    06/21/2020
  * Course:  ECE 131 - Programming Fundamentals
  * 
  * Program that demonstrates the following:
  *     1. Error when you declare a function below main.
  *     2. How to solve this error using function prototypes.
  *
  * 
****************************************************************/ 
#include <stdio.h>

//Function prototypes:
void printTwoIntegers(int int1, int int2);
float addTwoFloats(float f1, float f2);
int multiplyNtimes(int num, int n);

int main(){
	/*Up to today, all the functions that we have created
	have been created above main, what do you think will
	happen if we define our functions below main? If you
	ucomment the line below and try to compile your pro-
	gram, you will get an error.*/
	//printMessage();
	
	/*You get this error because programming is Top-Down.
	This means that it scans/reads from the top to the
	bottom. Thus, when your program reads the function
	call, your program knows nothing about it because
	the function definition comes afterwards (below main).
	If instead you had declared the function above main,
	your program would have worked without issues (like
	we have seen in all our previous examples).*/

	/*There is another solution however. Some programmers
	like to have their function definitions below main,
	and use "function prototypes" above main. These func-
	tion protypes let the compiler know the name of the
	function, its dataype and the number of arguments
	that it will receive. Let's give you an example,
	above main, I am doing a function prototype for a	
	function called printTwoIntegers. Notice that all
	I am doing is, giving the datatype, the name and
	the arguments of the function, nothing else. Then,
	below main, I declare the function.*/

	/*This means that running the following command, will
	result in zero errors because the compiler, in its
	top-down logic, will read the function prototype and
	will know that somewhere in the program, a function
	with this name exists. Therefore, whenever I call this
	function, the compiler will scan the program until it
	finds the function definition.*/
	printTwoIntegers(2,5);

	/*The two functions used below use the concep of func-
	tion prototyping.*/
	float sum;
	sum = addTwoFloats(5.5, 9.8);
	printf("The sum of your two floats is: %.2f\n", sum);

	int n = 5;
	int number = 2;
	int result;
	result = multiplyNtimes(number, n);
	printf("Multiplying %d by itself, %d times, results in %d.\n", number, n, result);

	/*Whether to use function prototypes or not, is up to
	you. Your program will run either way (if implemented
	correctly).*/
	
	return 0;
}

//Function that prints Hello World!
void printMessage(){
	printf("Hello World!");
	return;
}

//Function that receives two integers
void printTwoIntegers(int int1, int int2){
	printf("The first integer is %d\n", int1);
	printf("The second integer is %d\n", int2);
	return;
}

//Function that receives and adds two floats
float addTwoFloats(float f1, float f2){
	float result = f1 + f2;
	return result;
}

//Function that multiplys "num" by itself "n" times
int multiplyNtimes(int num, int n){
	int i, result = 1;
	for(i=0; i<n; i++){
		result = result * num;
	}
	return result;
}
