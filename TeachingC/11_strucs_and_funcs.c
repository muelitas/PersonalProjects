/**************************************************************
  * File:	11_strucs_and_funcs.c
  * Author:	Mario Esparza
  * Date:	06/24/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * Program that covers the following:
  * 	1. How to send, receive and return structures.
  *	2. How to display and scan structure info in functions.
  *
**************************************************************/
//TODO Add to Github
#include <stdio.h>

struct car{
	float mileage;
	char make[50];
};

struct tv{
	int screen, resolution;
	char brand[50];
};

void getAndDisplayInfo(){
	struct car myCar;
	printf("What is the mileage in the car? ");
	scanf("%f", &myCar.mileage);

	int i, length;
	printf("How many letters are in the make of this car?\n");
	printf("(can't be more than 50): ");
	scanf("%d", &length);
	printf("Please input the make: ");
	for(i=0; i<length; i++){
		scanf(" %c", &myCar.make[i]);
	}

	printf("\nThis is the information of your car:\n");
	printf("\tMileage: %.2f\n", myCar.mileage);
	printf("\tMake: ");
	for(i=0; i<length; i++){
		printf("%c", myCar.make[i]);
	}
	printf("\n");
	
	return;
}

void displayInfo(int L, struct car oneCar){
	int j;
	printf("\nThis is the information of your car:\n");
	printf("\tMileage: %.2f\n", oneCar.mileage);
	printf("\tMake: ");
	for(j=0; j<L; j++){
		printf("%c", oneCar.make[j]);
	}
	printf("\n");

	return;
}

struct tv scanInfoTV(int L){
	struct tv myTV;
	printf("What is the screen size of your TV? ");
	scanf("%d", &myTV.screen);
	printf("What is the resolution of your TV? ");
	scanf("%d", &myTV.resolution);

	int i;
	printf("Please input the brand: ");
	for(i=0; i<L; i++){
		scanf(" %c", &myTV.brand[i]);
	}

	return myTV;
}

void displayInfoTV(int L, struct tv oneTV){
	int j;
	printf("\nThis is the information of your TV:\n");
	printf("\tScreen Size: %d\n", oneTV.screen);
	printf("\tResolution: %d\n", oneTV.resolution);
	printf("\tMake: ");
	for(j=0; j<L; j++){
		printf("%c", oneTV.brand[j]);
	}
	printf("\n");

	return;
}

void printCharArray(int L, char arr[]){
	int j;
	for(j=0; j<L; j++){
		printf("%c", arr[j]);
	}
	printf("\n");
	return;
}

void newDisplayInfoCar(int L, struct car oneCar){
	printf("\nThis is the information of your car:\n");
	printf("\tMileage: %.2f\n", oneCar.mileage);
	printf("\tMake: ");
	printCharArray(L, oneCar.make);
	return;
}

void newDisplayInfoTV(int L, struct tv oneTV){
	printf("\nThis is the information of your TV:\n");
	printf("\tScreen Size: %d\n", oneTV.screen);
	printf("\tResolution: %d\n", oneTV.resolution);
	printf("\tMake: ");
	printCharArray(L, oneTV.brand);
	return;
}

int main(){
	/*The same way we used variables and arrays as parame-
	ters of functions, we can also use structures. We will
	look at three functions cases; one in which we call the
	function and do everything inside it; one in which we
	send a structure and return nothing; and another one in
	which we send some arguments and return a structure.
	Let's use the car example again:*/
	getAndDisplayInfo();
	/*Example of a function that does everything and does
	not return anything. Second example:*/
	struct car carA;
	printf("\nWhat is the mileage in car A? ");
	scanf("%f", &carA.mileage);

	int i, length;
	printf("How many letters are in the make of this car?\n");
	printf("(can't be more than 50): ");
	scanf("%d", &length);
	printf("Please input the make: ");
	for(i=0; i<length; i++){
		scanf(" %c", &carA.make[i]);
	}
	displayInfo(length, carA);
	/*Example of a function that receives two arguments and
	returns nothing. It is important to hightlight the way
	in which we specify the second argument in the function
	definition. We use "stuct" to indicate we will receive
	a structure; we use "car" to indicicate which kind of
	structure we will be receiving; and we indicate that
	"oneCar" will be the variable name of the structure in-
	side the function.*/
	
	/*Third example; I will use the structure called tv.
	Notice that I am defining the members "screen" and
	"resolution" in the same line (this is valid and some-
	times preferred by some programmers). Let's start the
	function example:*/
	struct tv livingRoomTV;
	printf("\nHow many letters are in the brand of your TV?\n");
	printf("(can't be more than 50): ");
	scanf("%d", &length); //reusing variable "length"
	livingRoomTV = scanInfoTV(length);
	/*Example of a function that receives an integer and
	returns a structure. Notice that in order to return a
	structure, I had to define the function as a
	"struct tv"; otherwise, it wouldn't have let us return
	a structure. Let's make sure all info was scanned
	correctly:*/
	displayInfoTV(length, livingRoomTV);

	/*Lastly, I would like to point out that both functions
	displayInfo and displayInfoTV, have a printf section.
	Functions are about removing code that is repetitive,
	thus, we can do something about it. Let's create a
	function that prints a character array, this way, when-
	ever we need to print a tv brand, a car make, a truck
	make or a truck model, we call this function and we are
	done!*/

	struct car carB;
	printf("\nWhat is the mileage in car B? ");
	scanf("%f", &carB.mileage);

	printf("How many letters are in the make of this car?\n");
	printf("(can't be more than 50): ");
	scanf("%d", &length);
	printf("Please input the make: ");
	for(i=0; i<length; i++){
		scanf(" %c", &carB.make[i]);
	}
	newDisplayInfoCar(length, carA);
	
	struct tv bedroomTV;
	printf("\nHow many letters are in the brand of your TV?\n");
	printf("(can't be more than 50): ");
	scanf("%d", &length); //reusing variable "length"
	bedroomTV = scanInfoTV(length);
	newDisplayInfoTV(length, bedroomTV);
	/*The printing method uses 5 lines of code. Looking at
	the two functions in which we were using it, we would
	have 10 lines of code. Now, with our printCharArray
	function we are only using 8 lines of code. If we had
	a truck, or if we added a model to our car structure,
	we would only have to use this function and we wouldn't
	have to create more printf sections.*/

	/*If we look more in depth to the functions we have
	created, we could also create a function that scans
	character arrays and save some more lines of code*/

	return 0;
}
