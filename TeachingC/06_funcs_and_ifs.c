/****************************************************************
  * File:    06_funcs_and_ifs.C
  * Author:  Mario Esparza
  * Date:    06/21/2020
  * Course:  ECE 131 - Programming Fundamentals
  * 
  * Program that demonstrates the following:
  *     1. How to use if-else statements inside functions.
  *     2. How to check if a case is missing a return statement.
  *
  * 
****************************************************************/ 
#include <stdio.h>

//Function that lets the user know if a number is positive or negative
void posOrNeg(){
	int number;
	printf("Please enter an integer: ");
	scanf("%d", &number);
	if(number >= 0){
		printf("The number you entered is positive\n");
	}else{
		printf("The number you entered is negative\n");
	}
	return;
}

//Function that returns absolute value of number
int absoluteValue(int number){
	if(number < 0){
		number = number * -1;
	}
	//else, number is already positive
	return number;
}

//Given an age, it determines if you can drink, vote and/or drive
void determineOptions(int age){
	if(age > 16){
		printf("Hey, you are old enough to drive in the US\n");
		if(age >= 18){
			printf("You are also old enough to vote in the US\n");
			if(age >= 21){
				printf("And you are also old enough to drink in the US\n");
			}else{
				printf("But you are not old enough to drink in the US\n");
			}
		}else{
			printf("But you are not old enough to vote in the US\n");
			printf("Nor old enough to drink in the US\n");
		}
	}else{
		printf("You are not old enough to drive in the US\n");
		printf("You are not old enough to vote in the US\n");
		printf("And you are not old enough to drink in the US\n");
	}
	return;
}

//Function checks if denominator is divisible
int checkIfDivisible(float denominator){
	if(denominator == 0){
		return -1;
	}else{
		return 0;
	}
}

//To show what happens when one case misses and if statement
int checkIfDivisibleError(float denominator){
	if(denominator == 0){
		printf("Denominator equals 0.\n");
	}else{
		return 0;
	}
}

int main(){
	/*Just as we can have arrays, loops and variables inside
	functions, we can also have if and else statements. In
	this program we will create a few functions incorporating
	if and else statements. Let's start with a function that
	tells us whether a number is positive or negative:*/
	posOrNeg();
	posOrNeg();
	posOrNeg();

	/*Nice right? We could also modify this posOrNeg function a
	little and have it return the absolute value of	a number:*/
	int myInt;
	printf("Give me an integer: ");
	scanf("%d", &myInt);
	int result = absoluteValue(myInt);
	printf("This is the absolute value of the integer you entered: %d\n", result);

	/*Now, let's look at the example from class in which we ask
	for the user's age:*/
	int age;
	printf("What is your age? ");
	scanf("%d", &age);
	determineOptions(age);

	/*Lastly, lets do a function with multiple return statements.
	Let's devide two numbers and create a function that checks if
	the denominator is zero:*/
	float numer, denom;
	printf("Please input your division in the following format (a/b): ");
	scanf("%f/%f", &numer, &denom);
	int veredict = checkIfDivisible(denom);
	if(veredict == 0){
		printf("Dividing %.2f and %.2f results in: %.2f.\n", numer, denom, numer/denom);
	}else{
		printf("It seems your denominator is zero, can't divide by it.\n");
	}
	/*We ask the user for the numerator and denominator, then we
	use our function to check the denomniator. If the denominator
	equals anything else than 0, we return 0 and veredict equals
	0. If the denominator equals 0, our function returns -1 and
	veredict equals -1; indicating that the division can't be
	performed. In programming, zero stands for false. In this
	case, I returned 0 as an indicator that there were no errors
	in the function (a "false" for errors).*/

	/*There is a catch however, when using multiple return state-
	ments. When using if-else and multiple return statements you
	have to ensure that all possible paths (cases) have a return
	statement. For example, if we modify checkIfDivisible and we
	replace the return -1 by a printf statement, our program 
	would cause unexpected results because a return statement
	would be missing in the "if" case. I did this change in the
	function called checkIfDivisibleError.*/

	/*If you add the function checkIfDivisibleError and you compile
	the program, the compiler might yell at you or it might not.
	This is why we have to keep an eye on these kind of mistakes.
	Because depending on your compiler, you might not get any
	errors or warning messages. Fortunately, if you ever feel like
	you might be missing a return statement you can always force
	your compiler to check for this by using the command:
	gcc -Wreturn-type programName.c   If there is an error (if you
	are missing a return statement, the compiler will give you a
	warning "control reaches end of non-void function".*/

	return 0;
}
