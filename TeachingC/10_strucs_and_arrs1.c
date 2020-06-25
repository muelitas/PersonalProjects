/**************************************************************
  * File:	10_strucs_and_arrs1.c
  * Author:	Mario Esparza
  * Date:	06/24/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * Program that covers the following:
  *	1. How to incorporate arrays inside structures. In
  *	other words, have arrays as structure members.
  *	2. How to populate and print these arrays.
  *
**************************************************************/
//TODO Add to Github
#include <stdio.h>

struct car{
	float mileage;
	char make[50];
};

struct truck{
	float mileage;
	int gasCap;
	char make[50];
	char model[50];
};

int main(){
	/*In the previous program, we covered the case in which
	a structure has members of type integer and float. Us-
	ing the same approach we could have created a structure
	with characters	and doubles. In this program, we will
	see how to create a structure with an array, or multi-
	ple arrays, as members. Let's look at the structure
	defined above main of type "car". A structure with two
	members, a float (mileage) and an array of 50 charac-
	ters (make). Let's declare a structure of this type
	and initialize its members:*/
	struct car car1;
	//Initialize its mileage
	printf("What is the mileage in the car? ");
	scanf("%f", &car1.mileage);
	//Initialize its make
	int i, length;
	printf("How many letters are in the make of this car?\n");
	printf("(can't be more than 50): ");
	scanf("%d", &length);
	for(i=0; i<length; i++){
		scanf(" %c", &car1.make[i]);
	}
	/*Notice that we use a loop to initialize the array of
	the structure. To access it, we first use the dot and
	then the brackets []. Similarly, to print its informa-
	tion, we would do:*/
	printf("This is the information of Car 1:\n");
	printf("Mileage: %.2f\n", car1.mileage);
	printf("Make: ");
	for(i=0; i<length; i++){
		printf("%c", car1.make[i]);
	}
	printf("\n");

	/*Pretty neat huh? Let's look at a second example.
	Let's look at a truck (pick-up):*/
	struct truck myTruck;
	//Initialize mileage and gas tank capacity
	printf("What is the mileage of your truck? ");
	scanf("%f", &myTruck.mileage);
	printf("What is the gas tank capacity? ");
	scanf("%d", &myTruck.gasCap);
	//Initialize make
	printf("How many letters are in the make of this truck?\n");
	printf("(can't be more than 50): ");
	scanf("%d", &length); //reuse "length"
	for(i=0; i<length; i++){
		scanf(" %c", &myTruck.make[i]);
	}
	//Initialize model
	printf("How many letters are in the model of this truck?\n");
	printf("(can't be more than 50): ");
	scanf("%d", &length); //reuse variable one more time
	for(i=0; i<length; i++){
		scanf(" %c", &myTruck.model[i]);
	}
	//Let's ensure all info was scanned properly:
	printf("This is the information of my truck:\n");
	printf("\tMileage: %.2f\n", myTruck.mileage);
	printf("\tGas Capacity: %d\n", myTruck.gasCap);
	printf("\tMake: ");
	for(i=0; i<length; i++){
		printf("%c", myTruck.make[i]);
	}
	printf("\n");
	printf("\tModel: ");
	for(i=0; i<length; i++){
		printf("%c", myTruck.model[i]);
	}
	printf("\n");
	
	return 0;
}
