/**************************************************************
  * File:	12_arrays_of_structs.c
  * Author:	Mario Esparza
  * Date:	06/29/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * Program that covers the following:
  * 	1. How to create arrays of structures.
  *		2. How to initialize each structure and each of its
  *		members.
  *		3. With and without functions.
  *
**************************************************************/
#include <stdio.h>

struct car{
	float mileage;
	char make[50];
};

void printCarInfo(int L, struct car thisCar){
	int i;
	printf("\tMileage: %.2f\n", thisCar.mileage);
	printf("\tMake: ");
	for(i=0;i<L;i++){
		printf("%c", thisCar.make[i]);
	}
	printf("\n");
	return;
}

void printCarMake(int L, char thisMake[]){
	int i;
	for(i=0;i<L;i++){
		printf("%c", thisMake[i]);
	}
	printf("\n");
	return;
}

void printCarInfoBetter(int L, struct car thisCar){
	int i;
	printf("\tMileage: %.2f\n", thisCar.mileage);
	printf("\tMake: ");
	printCarMake(L, thisCar.make);
	return;
}

int main(){
	/*To take this concept of structures even further; in this
	program, I want to show you how you could have a whole in-
	ventory of cars. With the help of arrays we can make this
	happen. If I had 2 cars for example, and I wanted to store
	their information together, I would do so as follows:*/

	struct car cars[2]; //create array of three structures
	//Initializing first car (first structure in array):
	cars[0].mileage = 4500.5;
	cars[0].make[0] = 'B';
	cars[0].make[1] = 'M';
	cars[0].make[2] = 'W';

	//Itinialize second car:
	cars[1].mileage = 9250.1;
	cars[1].make[0] = 'F';
	cars[1].make[1] = 'O';
	cars[1].make[2] = 'R';
	cars[1].make[3] = 'D';

	//Pretty neat huh? Let's print the info of the BMW:
	int i;
	printf("Information of car 1 is:\n");
	printf("\tMileage: %.2f\n", cars[0].mileage);
	printf("\tMake: ");
	for(i=0;i<3;i++){
		printf("%c", cars[0].make[i]);
	}
	printf("\n");

	/*We could also use a function to print all the info of a
	car:*/
	printf("\nInformation of car 2 is:\n");
	printCarInfo(4,cars[1]);

	/*Or we can use a function that only prints the make of the
	car:*/
	printf("\nRe-printing information of car 1:\n");
	printf("\tMileage: %.2f\n", cars[0].mileage);
	printf("\tMake: ");
	printCarMake(3,cars[0].make);

	/*Even better, we can create a function that prints all the
	info and uses the printCarMake function:*/
	printf("\nRe-printing information of car 2:\n");
	printCarInfoBetter(4,cars[1]);
	
	/*If car had other members that were character arrays; it
	would be smarter to change the name of printCarMake to so-
	mething like printCharArray (like we did in 11). This way,
	if the car had a member called "model" or "issuedIn", you
	can use this function for make, model and/or issuedIn.*/

	/*This program could be more user friendly if it would let
	us ask the user for the number of cars that he/she has in
	inventory. We can do so as follows:*/
	int numOfCars;
	printf("How many cars do you have? ");
	scanf("%d", &numOfCars);
	struct car Cars[numOfCars];

	/*From here, we could create loops or functions or a combi-
	nation of both to ask the user for the mileage and make of
	each car. However, I will not show you how to do such until
	we see strings (the next chapter).*/

	return 0;
}
