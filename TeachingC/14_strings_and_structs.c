/**************************************************************
  * File:	14_strings_and_structs.c
  * Author:	Mario Esparza
  * Date:	07/02/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * Program that covers the following:
  * 	1. How strings and structures can be used together.
  *		2. Discusses what happens in the "input-tape" when you
  *		don't take into consideration the new line char '\n'.
  *
**************************************************************/
#include <stdio.h>

struct car{
	float mileage;
	char make[50];
	char model[50];
};

int main(){
	/*Let's begin where we left off in (12), creating an
	array of cars (array of structures):*/
	int numOfCars;
	char dummy;
	printf("How many cars do you have in your dealership? ");
	scanf("%d%c", &numOfCars, &dummy);
	struct car cars[numOfCars];
	/*Notice however that I have something weird going on
	in my scanf. I am reading an integer, and then I am
	reading a character. This character is the enter key.
	If we think of the information entered by the user as
	a tape, you would see that in that tape you don't only
	have an integer, but also a character (when the user
	types the enter key). This means that numOfCars equals
	whichever integer was entered by the user and dummy 
	equals '\n' (or 10, as stated in the ascii table). To
	prove this, we print the numeric value of dummy:*/
	printf("Numeric value of dummy is: %d\n", dummy);

	/*We care about reading this enter key with "dummy" be-
	cause every time we scan, the "input-tape" doesn't emp-
	ty by itself. In other words, by the time we scan next,
	the input tape will have this '\n' hanging around. So
	far, we have either played only with numbers (and deci-
	mals) or we have used the space between " and %. These
	two methods ignore the '\n'. But now, since we are
	using getchar() or scanf("%c"), we need to make sure
	the input tape is empty by the time it gets to the next
	scanf or getchar. If you want to experience these weird
	behaviors, go ahead and remove the %c of the scanf
	below. Otherwise, let's go ahead and get the mileage of
	each car:*/
	int i;
	for(i=0;i<numOfCars;i++){
		printf("What is the mileage in Car %d? ", i+1);
		scanf("%f%c", &cars[i].mileage, &dummy);
	}

	/*Next, let's get their makes:*/
	int j;
	for(i=0;i<numOfCars;i++){
		printf("What is the make of Car %d? ", i+1);
		//Scan make:
		dummy = '_';
		j = 0;
		while(1){
			dummy = getchar();
			if(dummy == '\n' || i >= 49){
				break;
			}else{
				cars[i].make[j] = dummy;
				j++;
			}
		}
		cars[i].make[j] = '\0';
	}
	/*Notice that we have to reset dummy and j every time
	we are moving to a different car. If we don't do this,
	the program would give us unexpected results.*/

	/*Finally, let's scan their models:*/
	for(i=0;i<numOfCars;i++){
		printf("What is the model of Car %d? ", i+1);
		//Scan make:
		dummy = '_';
		j = 0;
		while(1){
			dummy = getchar();
			if(dummy == '\n' || i >= 49){
				break;
			}else{
				cars[i].model[j] = dummy;
				j++;
			}
		}
		cars[i].model[j] = '\0';
	}

	/*Once everything is scanned, we can go ahead and print
	out the information:*/
	for(i=0;i<numOfCars;i++){
		printf("\nInfo of Car %d:\n", i+1);
		printf("\tMileage: %.2f\n", cars[i].mileage);
		printf("\tMake: %s\n", cars[i].make);
		printf("\tModel: %s\n", cars[i].model);
	}
		
	/*Portions of this code could be implemented in func-
	tions. I am tempted to show you how, but you will be
	challenged to do so on your own.*/

	return 0;
}
