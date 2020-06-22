/****************************************************************
  * File:    05_funcs_and_arrays.C
  * Author:  Mario Esparza
  * Date:    06/20/2020
  * Course:  ECE 131 - Programming Fundamentals
  * 
  * Program that demonstrates the following:
  *     1. How to send single values of array to a function.
  *     2. How to send the "whole" array to a function.
  *     3. Difference between passByValue and passByReference.
  *
  * 
****************************************************************/ 
#include <stdio.h>

//Function that adds two doubles (decimals) and displays result.
void addTwoNumbers(double x, double y){
	double result = x + y;
	printf("Adding %.2lf and %.2lf results in %.2lf\n", x,y,result);
	return;
}

//Function that adds all values inside an array of doubles.
void addValuesInArray(int arrayLength, double Array[]){
	/*The first argument receives an integer, the length of the array.
	The second argument is the array, notice that we need to add the
	brackets at the end of Array; not doins so would have resulted in
	an error. In other words, typing   double Array   would have given
	me an error. Try it.*/
	int i;
	double result = 0.0;
	for(i=0; i<arrayLength; i++){
		result = result + Array[i];
	}
	printf("The sum of all the values inside the array is %.2lf\n", result);
}

//Function that prints all values inside an array of doubles.
void printArray(int arrayLength, double Array[arrayLength]){
	/*Notice that here, my second argument looks different, inside
	the brackets, I have stated how long the array is. Is not nece-
	ssary, but is not invalid either. Completely up to you and your
	coding style. There's one catch however, please look at function
	below called    printArrayError.*/
	int i;
	for(i=0; i<arrayLength; i++){
		printf("array[%d] = %.2lf\n", i, Array[i]);
	}
	return;
}
/*
//Function that tries to print all values inside an array of doubles.
void printArrayError(double Array[arrayLength], int arrayLength){
	//If you uncomment this function and try to compile the program,
	//you will get an error. The first argument   Array[arrayLength]
	//is using the second argument   arrayLength   Therefore, when
	//the compiler tries to set up the length of the array, it won't
	//know it because it doesn't have any record of it. This is why
	//if you want to use this syntax, you have to first state the
	//variable   arrayLength. Then, you would be able to set your
	//array with its length (like in the function printArray).
	int i;
	for(i=0; i<arrayLength; i++){
		printf("array[%d] = %.2lf\n", i, Array[i]);
	}
	return;
}
*/

//To show that a variable won't change everywhere if you change it inside a function
void changeValueOfVariable(int myVariable){
	myVariable = 500;
	return;
}

//To show that if you change an array inside a function, you change it everywhere
void changeValueInsideArray(int myArray[]){
	myArray[0] = 500;
	return;
}

//Function that populates an array of doubles with the help of scanf
void scanArray(int length, double array[length]){
	int i;
	printf("Please enter the values for your array:\n");
	for(i=0;i<length;i++){
		scanf("%lf", &array[i]);
	}
	return;
}

//Function that calculates the average of a set of grades
double calculateAverage(int L, double array[]){
	double sum = 0.0;
	int i;
	for(i=0;i<L;i++){
		sum = sum + array[i];
	}
	double average = sum / L;
	return average;
}

int main(){
	//Up to this point, we have only seen how to send integers, doubles,
	//floats and characters as arguments. It turns out we can also send
	//arrays to our functions. We can send single elements of an array,
	//or we can send the "whole" array. Let's start by looking at the
	//single elements case:
	double array[5] = {5.2,8.9,2.6,4.8,5.4};
	addTwoNumbers(array[0], array[3]);
	addTwoNumbers(array[4], array[2]);
	//These examples called the function addTwoNumbers and sent two 
	//different elements of our array. Great, this works and is useful
	//when we only need to send a few elements of our array. What about
	//when we need all the values inside our array? For example, what
	//if we wanted to add all the values in our array? If our array has
	//100 elements, our function would need 100 arguments (parameters),
	//which is not optimal. Let's then show how we can send a whole
	//array to a function:

	addValuesInArray(5, array);
	//The first parameter that I send, represents the length of the
	//array. The second argument is the name of the array we are inte-
	//rested in sending to our function. Notice that here, you do not
	//need to put any brackets after the variable name array.

	/*Let's look at another example. Let's send the whole array to a
	function that will print its values:*/
	printArray(5, array);

	/*Let's declare another array, but this time using a variable to
	set up its length:*/
	int length = 4;
	double array2[length];
	array2[0] = 10.5;
	array2[1] = 9.2;
	array2[2] = 8.4;
	array2[3] = 5.6;

	//We can now re-use our functions in this new array:
	addTwoNumbers(array2[3], array2[0]);
	addValuesInArray(length, array2);
	printArray(length, array2);
	/*Notice that instead of sending 4 as the first argument, I am now
	sending the variable   length   This is convenient because if we
	need to change the length of our array, we would only have to
	change the value of   length   rather than changing the value
	in all the functions.*/


	/*Now, sent arrays act differently than sent variables. When you
	send a variable (integer, decimal, character, etc), as soon as
	your function receives it, it creates a local copy of this va-
	riable and forgets about the variable that was sent. On the other
	hand, when you send an array, the function that receives this
	array does not create a copy of it; instead, it keeps track of
	where it comes from. This means that if you change a value of the
	array inside your function, you are chaging this array's value
	for good (you are also changing it at the place where it came
	from). Wherever you use your array now, it will have this new
	value. Let's show this by first trying to change the value of a
	variable:*/
	
	int myVariable = 55;
	printf("Before calling the function, myVariable = %d\n", myVariable);
	changeValueOfVariable(myVariable);
	printf("After calling the function, myVariable = %d\n", myVariable);
	/*If you look at the output of these two printf statements, you
	will see that the value of myVariable didn't change, even though
	I changed its value in changeValueOfVariable. If we do the same
	with an array, things will be different; watch:*/

	int myArray[1];
	myArray[0] = 55;
	printf("Before calling the function, myArray[0] = %d\n", myArray[0]);
	changeValueInsideArray(myArray);
	printf("Before calling the function, myArray[0] = %d\n", myArray[0]);
	/*Bingo, I created an array of one element and initialized it to 55.
	I then sent the array to the function, changed its single element to
	500 and returned nothing (changeValueInsideArray is void and didn't
	return anything). Nonetheless, the value of myArray changed, because
	the change was done in memory to the original array and not to a
	copy of it. This is known as pass-by-reference vs pass-by-value.
	When you pass by value, you copy the element inside the function,
	when you pass by reference, you use the original memory of the
	array.*/

	/*These are awesome news. This means that we can create an array,
	send it to a function, and populate it with the help of a function
	and scanf:*/
	//First, let's declare the array
	int Length = 4;
	double array3[Length];
	//Then, let's see which random values it has:
	printArray(Length, array3);
	//Then, let's use our function to populate it with desired values:
	scanArray(Length,array3);
	//Finally, let's print it again to ensure all desired values were
	//stored properly:
	printArray(Length, array3);

	/*As the last example, let's look at a function that calculates and
	returns the average of a set of grades:*/
	Length = 10; //I am reusing this variable and changing it to 10
	double grades[Length];
	scanArray(Length, grades); //we scan the grades
	printArray(Length, grades); //we print them
	//Then, we call our function 
	double average = calculateAverage(Length, grades);
	printf("The average of the class is: %.2lf\n", average);

	return 0;
}

