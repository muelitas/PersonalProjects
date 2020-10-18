/**************************************************************
  * File:	15_pointers_intro.c
  * Author:	Mario Esparza
  * Date:	07/06/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * Program that covers the following:
  * 1. How variables look in memory (brief explanation).
  *	2. Declaration and initialization of pointers.
  * 3. How to dereference pointers for read and write purposes.
  *
**************************************************************/
#include <stdio.h>

int main(){
	/*Before we dive into Pointers, I want to make a quick ex-
	planation of how variables look in memory. Below, I declare
	three integers. I print their values and their "addresses".
	I do so with the help of the address operator (&) and its 
	format character (%p).*/
	
	int i1 = 5;
	int i2 = 10;
	int i3 = 15;
	
	printf("The address of i1 is %p\n", &i1);
	printf("The value of i1 is %d\n", i1);

	printf("\nThe address of i2 is %p\n", &i2);
	printf("The value of i2 is %d\n", i2);

	printf("\nThe address of i3 is %p\n", &i3);
	printf("The value of i3 is %d\n", i3);
	
	/*If you run this code and pay close attention to the prin-
	ted addresses, you will notice that there is a difference
	of 4 bytes per address. This is because integers ocupy 4
	bytes in memory (in most cases). If you repeat this code
	using floats instead of integers, you will see that floats
	also occupy 4 bytes in memory (doubles occupy 8 bytes and
	characters occupy 1 byte).*/

	/*In pointers, memory is important because that is what
	they are; when you create a pointer, you create a variable
	that stores a memory-address, rather than an integer, deci-
	mal	or character. Below, I show you how a pointer can be
	declared and how it can be initialized.*/
	
	int *intPointer1; //declaring a pointer (option 1, preferred)
	int* intPointer2; //declaring a pointer (option 2)
	int * intPointer3; //declaring a pointer (option 3)
	//These three are "pointers to integers"
	
	//Initializing pointers
	intPointer1 = &i1;
	intPointer2 = &i2;
	intPointer3 = &i3;
	
	//Let's print their values:
	printf("The value of intPointer1 is %p\n", intPointer1);
	printf("The value of intPointer2 is %p\n", intPointer2);
	printf("The value of intPointer3 is %p\n", intPointer3);
	/*Notice that the format character that I used is %p, the
	same format character that I used to print the addresses of
	our integers at the beginning of this program. This means
	that pointers do hold memory-addresses as their values.*/
	
	/*But, what are these addresses, what do they mean? Well,
	if we print the addresses of i1, i2 and i3 again, along
	with the values of our pointers, you will notice that...*/
	printf("The address of i1 is %p\n", &i1);
	printf("The address of i2 is %p\n", &i2);
	printf("The address of i3 is %p\n\n", &i3);
	printf("The value of intPointer1 is %p\n", intPointer1);
	printf("The value of intPointer2 is %p\n", intPointer2);
	printf("The value of intPointer3 is %p\n", intPointer3);
	/*...the value of intPointer1 is the address of i1; the va-
	lue of intPointer2 is the address of i2 and the value of
	intPointer3 is the address of i3. Our pointers are success-
	fully pointing to where we said they should point.*/
	//EXPLAIN WIHT A DIAGRAM

	/*Alright, but why do we care? What is it special about a
	variable to pointing to another variable? Well, this poin-
	ting variable has read and write permissions on the pointed
	variable. Let me show you how we can read/access the value
	of a pointed variabe using "pointers to floats":*/
	float f1 = -9.0;
	float f2 = 0.0;
	float f3 = 9.0;
	
	//Declaring "pointers to floats"
	float *floatPointer1;
	float* floatPointer2;
	float * floatPointer3;
	
	//Initializing these pointers
	floatPointer1 = &f1;
	floatPointer2 = &f2;
	floatPointer3 = &f3;
	
	//Print addesses of floats and values of pointers
	printf("The address of f1 is %p\n", &f1);
	printf("The address of f2 is %p\n", &f2);
	printf("The address of f3 is %p\n\n", &f3);
	printf("The value of floatPointer1 is %p\n", floatPointer1);
	printf("The value of floatPointer2 is %p\n", floatPointer2);
	printf("The value of floatPointer3 is %p\n", floatPointer3);
	/*Notice that %p is a "universal" format character for ad-
	dresses; we didn't have to change it, even though we are
	now using floats. Now that we have checked that the poin-
	ters are pointing to the desired variables, let's see how
	using the pointers, we can access the value inside those
	variables:*/
	printf("floatPointer1 is pointing to f1, the value inside");
	printf("f1 is: %f\n", *floatPointer1);
	printf("floatPointer2 is pointing to f2, the value inside");
	printf("f1 is: %f\n", *floatPointer2);
	printf("floatPointer3 is pointing to f3, the value inside");
	printf("f1 is: %f\n", *floatPointer3);
	/*We use the format character of the variable we are poin-
	ting to and the * to "de-reference" each pointer. Similarly
	we can use this same * to change the value inside the poin-
	ted variable.*/
	
	printf("Value of f1 before changing its value is: %.2f\n", f1);
	*floatPointer1 = 100.5; //Same as saying:   f1 = 100.5;
	printf("Value of f1 after changing its value is: %.2f\n", f1);
	/*Pretty interesting huh? It is important not to confuse
	the usage of *. When you use it right after a datatype
	(int, float, double, etc), you are declaring a pointer.
	When you use it without a datatype, you are dereferencing
	the pointer, either for reading or writing.*/
	
	/*We can change the value of our float variable with scanf
	as well:*/
	printf("Please provide a value for f1: ");
	scanf("%f", &(*floatPointer1));
	printf("Value of f1 after scanning its value is: %.2f\n", f1);
	/*Whatever value is scanned, is assigned to the variable
	which floatPointer1 is pointing to. In this case f1. This
	is why when you print the value of f1, you see the value
	that you just inputted.*/
	
	/*We can also declare and initialize in the same line:*/
	double d1 = 55.5;
	double d2 = 5555.5;
	double *doublePointer1 = &d1;
	/*Then, later on in the program, if I want my pointer to
	point somewhere else, I could do:*/
	doublePointer1 = &d2;
	
	/*Pointers can be used to assign values to variables, for
	example:*/
	double d3 = *doublePointer1;
	/*I read (dereference) the value in the variable that
	doublePointer1 is pointing to and assign it to d3. Since
	doublePointer1 points to d2, I am essentially saying d3 = d2
	Let's make sure they are in fact the same:*/
	printf("Value of d2 is: %.2lf\n", d2);
	printf("Value of d3 is: %.2lf\n", d3);

	/*Let's look at these properties one more time:*/
	int int1 = 5;
	int *p1 = &int1;
	printf("Address of int1 is: %p\n", &int1);
	printf("Value of p1 is: %p\n", p1);
	printf("Value of int1 is: %d\n", int1);
	printf("Value of int1 is: %d (using dereferenced pointer)\n", *p1);
	
	//Then, if we modify int1 as we have seen in the pase, we get:
	int1 = 10;
	printf("Value of int1 is: %d\n", int1);
	printf("Value of int1 is: %d (using dereferenced pointer)\n", *p1);
	
	//Or if we modify it by dereferencing the pointer, we get:
	*p1 = 20;
	printf("Value of int1 is: %d\n", int1);
	printf("Value of int1 is: %d (using dereferenced pointer)\n", *p1);
	
	/*Let's look at some other properties. Let's add another
	integer and another pointer to integer:*/
	int int2;
	int *p2;
	/*We can dereference a pointer, perform operations to that
	value and assign the result to a variable:*/
	int2 = *p1 / 2 + 35;
	printf("Value of int2 is: %d\n", int2);
	/*We can set a pointer equal to another pointer:*/
	p2 = p1;
	printf("Value of p1 is: %p\n", p1);
	printf("Value of p2 is: %p\n", p2);
	/*This means that p2 is now also pointing to int1.*/

	/*Un-initialized pointers also have random values (addres-
	ses):*/
	char *charPointer;
	printf("Value of charPointer is: %p\n", charPointer);

	/*When printing the value of a pointer, you have and must
	use %p, you can't use any other format character:*/
	//printf("The value of charPointer is %c\n", charPointer);
	
	/*Whichever variable you are trying to pointer to point to,
	it has to be the same datatype, for example, something like
	this would not work:*/
	//float float1 = 20;
	//int *pointer1 = &float1;
	
	/*The variable you are trying to point, must have been al-
	ready declared, otherwise, your program will yell at you:*/
	// int *intPointer5 = &int5;
	// int int5 = 25;
	
	/*Lastly, when declaring multiple pointers in a single line
	you have to make sure each pointer has its respective *.
	Otherwise, you would be creating a combination of pointers
	and common variables. For example:*/
	//Correct way of declaring multiple pointers:
	int *a, *b, *c;
	//Incorrect way of declaring multiple pointers:
	int *iA, iB, iC;
	/*In this last statement you are actually declaring one
	pointer and two integers.*/

	return 0;
}
