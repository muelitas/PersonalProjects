/**************************************************************
  * File:	08_global_variables.c
  * Author:	Mario Esparza
  * Date:	06/22/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * Program that demonstrates the following:
  *	1. Explanation of local and global variables.
  *	2. Conditions and "rules" when using global variables.
  *
**************************************************************/
//TODO add to Github
//TODO add description
#include <stdio.h>
//Global Variables
double globalDouble = 10.5;
int globalInt = 56;

//Function that calculates and retunrs the area of a triangle
float calcTriangleArea(float b, float h){
	float area = b * h / 2;
	return area;
}

//Print numbers from "start" to "end"
void printGivenRange(int start, int end){
	int i;
	for(i=start; i<=end; i++){
		printf("%d\n", i);
	}
	return;
}

//Function that changes the value of "myNumber"
void changeNumber(double myNumber){
	printf("\tWe are now inside changeNumber\n");
	printf("\tAt the beginning, myNumber = %.2lf\n", myNumber);
	myNumber = 985.4;
	printf("\tAfter changing it, myNumber = %.2lf\n", myNumber);
	return;
}

//Function that modifies the value of "globalDouble"
void modifyNumber(){
	printf("\tWe are now inside modifyNumber\n");
	printf("\tAt the beginning, globalDouble = %.2lf\n", globalDouble);
	globalDouble = 1015.4;
	printf("\tAfter changing it, globalDouble = %.2lf\n", globalDouble);
	return;
}	

//Function that multiplies integer by 2
void multiplyByTwo(){
	printf("\tWe are now inside multiplyByTwo\n");
	printf("\tAt the beginning, globalInt = %d\n", globalInt);
	globalInt = globalInt * 2;
	printf("\tAfter changing it, globalInt = %d\n", globalInt);
	return;
}

//Function that multiplies integer by 3
void multiplyByThree(){
	printf("\tWe are now inside multiplyByThree\n");
	printf("\tAt the beginning, globalInt = %d\n", globalInt);
	globalInt = globalInt * 3;
	printf("\tAfter changing it, globalInt = %d\n", globalInt);
	return;
}
int main(){
	/*As of right now, all the variables that we have used,
	have been "local" variables; variables that are created
	inside functions and can only be used in that context.
	For example, below, inside main, I am creating three
	local variables. These variables can only be used insi-
	de main. If I try to use "base" inside calcTriangleArea
	I would get an error. The compiler would tell me that
	it doesn't know anything about this "base" variable. 
	Same would happen for "height" and "Area". Similarly,
	if I try to use the variables of calcTriangleArea in
	main, I would get errors because "b", "h" and "area"
	are local variables of calcTriangleArea and can only
	be used inside calcTriangleArea.*/
	float base = 10.0;
	float height = 5.5;
	float Area = calcTriangleArea(base, height);
	/*If you don't believe me, try it out, go to
	calcTriangleArea, comment the line "float area = ..."
	and add this line "Area = b * h / 2;". You will see
	that the compiler will yell at you that Area is an
	undeclared variable.*/

	/*We could "hack" the program and give the variables
	the same name inside main and inside the function. For
	example:*/
	int start = 20, end = 31;
	printGivenRange(start, end);
	/*Notice that I am using the names "start" and "end"
	in both functions, and as it might seem they are the
	same variable, they are not. In memory, the program
	has created two different instances of each. One start
	for main, one start for printGivenRange, one end for
	main and one end for printGivenRange. We can prove
	this with the following example:*/
	double myNumber = 55.5;
	printf("Inside main, before calling changeNumber\n");
	printf("the value of myNumber is %.2lf\n", myNumber);
	changeNumber(myNumber);
	printf("back in main, after calling the function\n");
	printf("the value of myNumber is %.2lf\n", myNumber);
	/*Even though I created a variable with the same name
	in two functions (main and changeNumber), notice that
	if I change its value in changeNumber, it doesn't
	change its value in main. Again, this is because both
	variables are "local" and can only be used inside the
	function they were created. There is however, a way
	in which we can use the same variable in multiple
	functions. This variable or variables would be re-
	ferred as "global" variables. I will repeat the pre-
	vious example (changeNumber), but this time, using a
	global variable:*/
	
	/*At the top of this program, you will see a variable
	called globalDouble, I have declared it to be a
	double with 10.5 as its value (notice that it is not
	inside any function).*/
	printf("Inside main, before calling modifyNumber\n");
	printf("the value of globalDouble is %.2lf\n", globalDouble);
	modifyNumber();
	printf("back in main, after calling the function\n");
	printf("the value of globalDouble is %.2lf\n", globalDouble);
	/*Bingo! You can see that globalDouble has a diffe-
	rent value everywhere, not only in modifyNumber.
	This is becuase globalDouble is a variable that can
	be accessed and modified by all functions. You can
	also see that I didn't have to send a variable to
	modifyNumber, nor I had to receive one. As soon as
	modifyNumber sees the line globalDouble = 1015.4,
	it can access this variable because the context of
	the variable is global and not local.*/

	/*If you are not convinced yet, let me give you ano-
	ther example:*/
	printf("Inside main, before calling multiplyByTwo\n");
	printf("the value of globalInt is %d\n", globalInt);
	multiplyByTwo();
	printf("back in main, after calling the function\n");
	printf("the value of globalInt is %d\n", globalInt);
	
	printf("Inside main, before calling multiplyByThree\n");
	printf("the value of globalInt is %d\n", globalInt);
	multiplyByThree();
	printf("back in main, after calling the function\n");
	printf("the value of globalInt is %d\n", globalInt);
	//Pretty neat huh?

	/*If you declare a global variable with the name 
	myVar, you will not be able to declare any other
	variable (local or global) with the same name.*/
	
	/*There is one last thing I want to mention regar-
	ding global variables. If you want to use a global
	variable inside any of your functions, the variable
	has to be delcared before all functions that will
	use it. For example, I would have declared globalInt
	right before    int main(){   the functions
	multiplyByTwo and multiplyByThree would not have
	worked because they wouldn't have known what 
	globalInt is. This is why it is a good practice to
	have your global variables at the beginning of your
	program*/

	return 0;
}
