/**************************************************************
  * File:	16_pointers_and_structs.c
  * Author:	Mario Esparza
  * Date:	07/06/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * Program that covers the following:
  * 1. How to handle pointers to structures.
  * 2. How to handle structures with pointers as their members.
  *
**************************************************************/
#include <stdio.h>

struct tv{
	float screen, resolution;
	//char brand[50]; //later
};

struct intPtrs{
	int *p1;
	int *p2;
};

int main(){

	/*Let's take a look at one of the structures we used in the
	past. Let's declare a structure and then a "pointer to a
	structure".*/
	struct tv myTv;
	struct tv *tvPointer;
	/*Notice that the * comes after specifying the type of
	structure and not the keyword struct.*/
	
	/*Let's make it point to myTv:*/
	tvPointer = &myTv;
	/*We could also have done: struct tv *tvPointer = &myTv;*/

	/*Now, to dereference the pointer, we have two options:*/
	(*tvPointer).screen = 48.0;
	tvPointer->resolution = 1080.0;
	/*Either by using parenthesis, * and a dot or by using the
	"arrow operator". Now, the members of myTv have actual
	values (not random anymore).*/
	
	/*We can print them using either method:*/
	printf("Screen size of myTv is: %.2f\n", tvPointer->screen);
	printf("Resolution of myTv is: %.2f\n", (*tvPointer).resolution);
	/*Using %d because the members we are dereferencing are in-
	tegers.*/
	
	/*And we can scan them as well:*/
	scanf("%f", &(tvPointer->screen));
	scanf("%f", &((*tvPointer).resolution));
	
	/*So we just saw how to create and initialize a pointer to
	a structure. Now, let's look at a structure containing
	pointers.*/
	struct intPtrs pointers;
	/*The variable pointers is a structure of type intPtrs that
	has two members; each one of them is a pointer to an inte-
	ger. Let's see how we can manipulate them. First, let's
	print their values (they should be random addresses).*/
	printf("Value of first pointer is: %p\n", pointers.p1);
	printf("Value of second pointer is: %p\n", pointers.p2);
	
	/*Let's initialize them (make them point somewhere):*/
	int i1 = 100, i2 = 150;
	pointers.p1 = &i1;
	pointers.p2 = &i2;
	printf("Value of first pointer is: %p\n", pointers.p1);
	printf("Value of second pointer is: %p\n", pointers.p2);
	/*The values (addresses) of the pointers have changed,
	let's ensure they are actually pointing to where we want
	them to point by printing the addresses of i1 and i2:*/
	printf("Address of i1 is: %p\n", &i1);
	printf("Address of i2 is: %p\n", &i2);
	
	/*Also, notice that to access the members we didn't have
	to use the arrow operator, nor the parenthesis and aste-
	risk: pointers->p1 nor (*pointers).p2 This is because
	"pointers" is not a pointer to a structure. "pointers" is a
	common structure that has pointers inside. This is why we
	are	accessing these two members with the dot.*/
	
	/*Let's dereference them and print the values of the varia-
	bles they are pointing to:*/
	printf("Dereferencing p1 gives us: %d\n", *(pointers.p1));
	printf("Dereferencing p2 gives us: %d\n", *(pointers.p2));
	
	/*Let's dereference them and change the values of the
	variables they are pointing to:*/
	*(pointers.p1) = 2000;
	*(pointers.p2) = 1500;
	printf("New value of i1 is: %d\n", i1);
	printf("New value of i2 is: %d\n", i2);
	
	return 0;
}
