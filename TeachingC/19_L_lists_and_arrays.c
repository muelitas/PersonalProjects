/**************************************************************
  * File:	19_L_lists_and_arrays.c
  * Author:	Mario Esparza
  * Date:	07/13/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * Program that covers the following:
  * 	1. Covers a different king of node, a car.
  *	2. Iterates through a linked list of cars.
  * 	3. Reviews strings-scanning methods.
  *
**************************************************************/
//TODO Add to Github
#include <stdio.h>

//This will replace the concept of "node"
struct car {
	int mileage;
	char make[70];
	char model[70];
	struct car *next;
};

void scanString(char thisString[]){
	char dummy = '_';
	int i = 0;
	while(1){
		dummy = getchar();
		if(dummy == '\n' || i>=69){
			break;
		}else{
			thisString[i] = dummy;
		}
		i++;
	}
	thisString[i] = '\0';
	return;
}

void scanStringV2(struct car *thiscar){
	char dummy = '_';
	int i = 0;
	while(1){
		dummy = getchar();
		if(dummy == '\n' || i>=69){
			break;
		}else{
			thiscar->model[i] = dummy;
		}
		i++;
	}
	thiscar->model[i] = '\0';
	return;
}

void printCarsInfo(struct car *thiscar){
	int carNumber = 1;
	while(thiscar != NULL){
		printf("\nInfo of car %d:\n", carNumber);
		printf("\tMileage: %d\n", thiscar->mileage);
		printf("\tMake: %s\n", thiscar->make);
		printf("\tModel: %s\n", thiscar->model);
		thiscar = thiscar->next;
		carNumber++;
	}
	printf("\n");
	return;
}

int main(){
	/*Let's look back at our car structure and create a
	linked list of cars. First, we declare our cars
	(nodes):*/
	struct car c1, c2, c3, c4;
	/*Next, as seen in the past, lets give their mileages
	a value:*/
	c1.mileage = 1001.1;
	c2.mileage = 2001.2;
	c3.mileage = 3001.3;
	c4.mileage = 4001.4;

	/*Next, let's give each car a make. I'll treat the make
	as a string and try to review all the initializing me-
	thods that we have seen. Let's start with the simplest
	one, using %s:*/
	char dummy;
	printf("What is the make of your first car? ");
	scanf("%69s%c", c1.make, &dummy);

	/*For the second car, let's do it manually:*/
	c2.make[0] = 'F';
	c2.make[1] = 'o';
	c2.make[2] = 'r';
	c2.make[3] = 'd';
	c2.make[4] = '\0';

	/*For the third one, let's use a loop:*/
	dummy = '_';
	int i = 0;
	printf("What is the make of your third car? ");
	while(1){
		dummy = getchar();
		if(dummy == '\n' || i>=69){
			break;
		}else{
			c3.make[i] = dummy;
		}
		i++;
	}
	c3.make[i] = '\0';

	/*And for the fourth one, let's use a function and a
	loop:*/
	printf("What is the make of your fourth car? ");
	scanString(c4.make);

	/*For the models, lets repeat the process, but this ti-
	me using a pointer:*/
	struct car *currCar;
	currCar = &c1;
	printf("What is the model of your first car? ");
	scanf("%69s%c", currCar->model, &dummy);

	currCar = &c2;
	currCar->model[0] = 'F';
	currCar->model[1] = 'o';
	currCar->model[2] = 'c';
	currCar->model[3] = 'u';
	currCar->model[4] = 's';
	currCar->model[5] = '\0';

	currCar = &c3;
	dummy = '_';
	i = 0;
	printf("What is the model of your third car? ");
	while(1){
		dummy = getchar();
		if(dummy == '\n' || i>=69){
			break;
		}else{
			currCar->model[i] = dummy;
		}
		i++;
	}
	currCar->model[i] = '\0';
	
	/*And for the fourth car, I am going to use two di-
	fferent methods. We can reuse the function we previous-
	ly used:*/
	currCar = &c4;
	printf("What is the model of your fourth car? ");
	scanString(currCar->model);
	printf("Model of car 4 using previous function: %s\n", c4.model);

	/*Or we can create a function that accepts a pointer,
	dereferences it and scans for the model:*/
	printf("Once again, what is the model of your fourth car? ");
	scanStringV2(&c4);
	printf("Model of car 4 using new function: %s\n", c4.model);

	/*Although, there might seem no point in creating a di-
	fferent function, this is the beginning of what I want
	to show you next: a function that iterates through each
	node (car) and prints out their information. To accom-
	plish this, we first need to link the cars to each
	other:*/
	c1.next = &c2;
	c2.next = &c3;
	c3.next = &c4;
	c4.next = NULL;

	/*Then we can call our function, starting at c1:*/
	printCarsInfo(&c1);
	/*This function prints the information of a car, and
	uses "next" to move to the next car. Same as we did
	in the example with nodes, but this time, each node
	(car) has more information than only a "value".*/
	return 0;
}
