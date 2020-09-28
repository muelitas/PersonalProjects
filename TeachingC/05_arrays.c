/******************************************************************************
  * File:	05_arrays.c
  * Author:	Mario Esparza
  * Date:	09/06/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * In this program I will cover:
  * - TODO Arrays
******************************************************************************/
#include <stdio.h>

int main(){
	/*Before we start this new topic, I would like to explain why I recommended
	 * to use a space in the scanf function. Let's look at an example. How many
	 * times do you think the program will let you input a value in the follo-
	 * wing example?*/
	int i1;
	printf("Please enter an integer: ");
	scanf("%d", &i1);
	char c1;
	printf("Please enter a character: ");
	scanf("%c", &c1);
	/*It should have been two huh?! Well, what ha-happened is, the enter key
	 * used with the integer, is also registered and stored in the "input tape"
	 * In other words, %d reads the number, but the \n is left there. Therefore
	 * when the second scanf kicks in, it doesn't let you input anything, be-
	 * cause it reads the input tape and finds out there is a \n laying in
	 * there. Thus, c1 = \n. To prove that this is true, let me print the ascii
	 * value of c1:*/
	printf("ASCII value of c1 is: %d\n\n", c1);
	/*Let's look at another example:*/
	float f1, f2;
	printf("Please enter the value of your first float: ");
	scanf("%f", &f1);
	printf("Now, enter the value of the second float: ");
	scanf("%f", &f2);
	/*If you type 1.1 2.1 as your input (two floats together), you will see
	 * that the program won't let you input anything for the second float. Rea-
	 * son being is that you have already inputted such. Logic is as follows,
	 * 1.1 is assigned to f1, but 2.1 is left in the "input tape", thus, when
	 * another scanf kicks in, what it reads is whatever is first in the input
	 * tape. Thus, f2 = 2.1. Does the input tape concept makes a bit more sense
	 * now? Now, to deal with the \n issue, all we have to do is add an space
	 * in the scanf statement:*/
	printf("Please enter an integer: ");
	scanf("%d", &i1);
	printf("Please enter a character: ");
	scanf(" %c", &c1);
	/*But only when scanning a character. Because when you scan an integer, a
	 * double or a float, the program knows to ignore any \n that are present.
	 * Et voila! The program didn't ignore the second scanf statement this time
	 * It ignored the \n that was present in the input tape. Makes sense? Now
	 * we are ready to move to the next topic, which is: "arrays". A group of
	variables that share the same datatype. For example:*/
	int students_ids[5];
	/*This statement creates an "array" of integers. Five of them to be
	precise. All of the elements in the array have a value, but this value
	is random. To give them a value (initialize them), you have to specify
	which element in the array you want to give a value to; AND you have to
	start at 0. So, if I want to give a value to the first element of the
	array, I would do something like this:*/
	students_ids[0] = 10001;
	/*I specify which array I am interested, then I use the "index" 0 to
	state which element in the array I am interested in. If I want to give
	a value to the second element of the array, I'd do:*/
	students_ids[1] = 10004;
	/*Index 1 refers to the second element in the array called student_ids.
	Notice that you surround the index with square brackets. Let's go ahead
	and initialize the third to fifth elements of the array:*/
	students_ids[2] = 10022;
	students_ids[3] = 10045;
	students_ids[4] = 10059;
	/*Now my array is fully initialized, all elements in the array have
	been assigned a desired value. Notice that the index for the last ele-
	ment in the array is 4, even though the array has 5 elements. This is
	because we started at index 0. Therefore, if you have an array of N
	elements, the last index value will be N-1. How many values are in the
	following array?*/
	float coffee_costs[4];
	/*What is the datatype of each one of the values inside the array? Ans-
	wer is float. What would be the last index value? Answer is 3. Let's
	initialize the values of this array:*/
	coffee_costs[0] = 5.24;
	coffee_costs[1] = 4.76;
	coffee_costs[2] = 5.29;
	coffee_costs[3] = 6.51;
	/*Noice, if the price of one of the coffees changes, I could edit it as
	follows:*/
	coffee_costs[2] = 3.56;
	/*I specify the index of the coffee I want to edit (in this case the
	third element of the array) and assign it a new value. In other words,
	the values with which you initialize your arrays are not absolute, you
	can change them. Similarly, I can modify this values with arithmetic
	operations. Let's say you forgot to inclue the tax in your coffee costs
	we could update them in many ways:*/
	coffee_costs[0] = 5.24 * 1.07875;
	coffee_costs[1] = coffee_costs[1] * 1.07875;
	float tax = 1.07875;
	coffee_costs[2] = coffee_costs[2] * tax;
	coffee_costs[3] *= tax;
	/*Just like we have seen with variables. Now however, your variables
	have square brackets and a number inside. Oh wait, but how can we check
	if we did the right thing. Is the right number being assigned to each
	element in the array? Well, good thing we can print them out:*/
	printf("The prices of your coffess, including taxes, are:\n");
	printf("Coffee 1: $%.2f\n", coffee_costs[0]);
	printf("Coffee 2: $%.2f\n", coffee_costs[1]);
	printf("Coffee 3: $%.2f\n", coffee_costs[2]);
	printf("Coffee 4: $%.2f\n", coffee_costs[3]);
	/*Pretty neat huh? And not only can we print them, but we can also scan
	them. Check this out:*/
	char grades[3];
	printf("\nWhat is the grade of your first student? ");
	scanf(" %c", &grades[0]);
	printf("What is the grade of your second student? ");
	scanf(" %c", &grades[1]);
	printf("What is the grade of your third student? ");
	scanf(" %c", &grades[2]);
	printf("\nThese are the grades of your students:\n");
	printf("Student 1: %c\nStudent 2: %c\n", grades[0], grades[1]);
	printf("Student 3: %c\n", grades[2]);
	/*Dopeo! Always matching the format character with the Datatype of the
	variable. Otherwise, you could get errors or unexpected results. Un-
	comment the two lines below to see what I mean.*/
	//int dummy_array[10];
	//scanf("%f", &dummy_array[0]);

	/*Let's go back to our array "grades" though. I will ask the user for
	the student whom he is interested in knowing the grade from. Using this
	variable, I will access the array and print the grade:*/
	int index;
	printf("\nFrom your 3 students ");
	printf("which one would you like to see the grade from? ");
	scanf("%d", &index);
	printf("You chose student %d. The grade is ", index);
	printf("%c\n", grades[index - 1]);

	printf("\nLet's try a different student: ");
	scanf("%d", &index);
	printf("You chose student %d. The grade is ", index);
	printf("%c\n", grades[index - 1]);
	/*Notice that I subtract index by 1 because indices inside arrays start
	at 0, not at 1. Before we mix arrays and loops (really helpful), I want
	to show you one last thing regarding arrays. So far, I have only shown
	how to declare and initialize arrays in different places. It turns out
	you can do so in the same line. For example:*/
	char hello[5] = {'H','e','l','l','o'};
	int integers[6] = {1,2,3,4,5,6};
	float gpas[3] = {3.9, 3.7, 2.8};
	/*Each array of a different type and initialized from the getgo. You
	can access their elements the same way we did before. You can edit them
	also like we did before. This is merely a way of initializing your
	array right away if you know which values it will hold. Notice however,
	that if you declare your array and then try to initialize all values in
	the same line, you will get an error. Uncomment the following lines and
	try to compile.*/
	//char dummy__array[3];
	//dummy__array = {'U','N','M'};

	/*So far, we have only seen arrays that have small dimensions. What if
	we had an array of 20 elements? Would you like to initialize each ele-
	ment at a time, like we have been doing so? No huh? There is a better,
	more efficient, way. I will create an array that will hole the first
	10 integers. Check it out:*/
	int i = 0;
	int ints[10];
	while(i<10){
		ints[i] = i+1;
		i += 1;
	}
	/*Iterator "i" starts at 0. The loop will end when "i" is equal or grea
	ter than 10; and it will be added by one in each iteration. The inte-
	resting, maybe more confusing line, is the one of ints. In each itera-\
	tion, we use "i" as the index and as the value being assigned. When i
	is 0 (first iteration), the first element of ints is accessed and 0+1\
	is assigned to it. On the second iterator, i = 1, the second element of
	ints is accessed and 1+1 is assigned to it. So on and so forth until
	i>=10. Pretty intense huh? Let's use another loop to print out the va-
	lues inside the array:*/
	i = 0; //reset value of i
	printf("\nThe values in your ints array are: \n");
	while(i<10){
		printf("%d ", ints[i]);
		i += 1;
	}
	printf("\n");
	/*Et Voila! First 10 integers were stored correctly in our array. You
	might be thinking, well, we could have printed all 10 integers without
	the need of an array, but bare with me, this is the beginning of the
	beginning. Let's look at a somewhat more complex example; where we will
	ask the user for a new value after each iteration:*/
	float GPAs[7];
	printf("\nPlease enter the GPAs of your students.\n");
	printf("One at a time, followed by the enter key:\n");
	for(i=0; i<7; i++){
		scanf("%f", &GPAs[i]);
	}
	/*And we print them out right away:*/
	printf("\nThe GPAs you entered are:\n");
	for(i=0; i<7; i++){
		printf("- %.2f\n", GPAs[i]);
	}
	
	/*Making sense? Let's look at one more example using loops and arrays*/
	int j = 0; //using a new iterator
	char word[5];
	printf("\nThink of a word with 5 letters. Go ahead and type each\n");
	printf(" letter, one at a time, followed by the enter key:\n");
	for(j=0;j<5;j++){
		scanf(" %c", &word[j]);
	}
	printf("The word you thought of is:\n");
	for(j=0;j<5;j++){
		printf("%c", word[j]);
	}
	printf("\n");
	/*Now, we are ready to jump into loops that deal with arrays and if-else
	 * statements. Before that however, let me show you how you can ask the user
	 * for the length of your array:*/
	int num_cars;
	printf("How many cars are in inventory? ");
	scanf("%d", &num_cars);
	float mileages[num_cars];
	/*mileages is an array of floats that has num_cars elements. Therefore, if
	 * num_cars is 10, mileages is 10 elements long. If num_cars is 20, milea-
	 * ges is 20 elements long. Now, we can iterate through them and use num_
	 * cars as the stopping condition:*/
	int k = 0;
	while(k<num_cars){
		printf("What is the mileage of car %d? ", k+1);
		scanf("%f", &mileages[k]);
		k++;
	}

	printf("\nHere is a mileages-summary of your cars:\n");
	k = 0;
	while(k<num_cars){
		printf("Car %3d --- %.2f\n", k+1, mileages[k]);
		k++;
	}

	/*Noize! Now, let's add some if-else statements. Let's do the following, if
	 * the user inputs a mileage greater than 200,000, we will warn the user
	 * that the mileage of the car is too high.*/
	k = 0;
	while(k<num_cars){
		printf("What is the mileage of car %d? ", k+1);
		scanf("%f", &mileages[k]);
		if(mileages[k] >= 200000){
			printf("Warning: this car is over 200K miles, just saying.\n");
		}
		k++;
	}
	/*Now, what happens if the user inputs a negative mileage? What do you
	 * think we should do? How should we do it? Answer:*/
	k = 0;
	while(k<num_cars){
		printf("What is the mileage of car %d? ", k+1);
		scanf("%f", &mileages[k]);
		if(mileages[k] >= 200000){
			printf("Warning: this car is over 200K miles, just saying.\n");
		}else if(mileages[k] < 0){
			printf("Mileages can't be negative, please input it again.\n");
			k--; //What else can we use instead of k--? Answer: "continue;"
		}
		k++;
	}

	/*Making sense? Let's look at another example. We will first ask the user
	 * for the number of students in the class. Then, we will scan their letter
	 * grades. If the grade is not A, B, C or F, we will re-ask for the grade:*/
	int num_grades;
	printf("How many students are in your class? ");
	scanf("%d", &num_grades);
	char Grades[num_grades];
	for(k=0; k<num_grades; ){
		printf("Please input grade of student %d: ", k+1);
		scanf(" %c", &Grades[k]);
		if(Grades[k] < 65 || Grades[k] > 67){
			if(Grades[k] != 70){
				printf("Sorry, I can't recognize this grade. Plese re-enter.\n");
				continue;
			}
		}
		k++;
	}
	printf("\nThese are the grades of your students:\n");
	for(k=0; k<num_grades; k++){
		printf("Student %3d --- %c\n", k+1, Grades[k]);
	}

	/*Let's include lower case!*/
	/*	Use: if( (Grades[k]<65) || (Grades[k]>67 && Grades[k]<97) || (Grades[k]>99) )*/
	/*  Then use: if( (Grades[k] != 70) || (Grades[k]!=102) ) */
	/*Notice that if we wanted to, we could include the conditions of our se-
	 * cond if inside the first if. However, it would make it way too crammed*/

	/*If time permits, include toupper.*/

	return 0;
}
