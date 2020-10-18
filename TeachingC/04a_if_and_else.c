/******************************************************************************
  * File:	04a_if_and_else.c
  * Author:	Mario Esparza
  * Date:	08/30/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * In this program I will cover:
  * - if, else if and else statements
  * - nested if-else statements
  * - logical operators (&&, || and !)
  * - 0 is false, anything else is true
  * - booleans and stdbool.h
******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

int main(){
	/*In this program, we well see how our programs can take their own deci-
	 * sions. For example, let's create a program that checks if a number
	 * is negative:*/
	int num;
	printf("Please enter an integer number: ");
	scanf("%d", &num);
	printf("The number you entered is: %d\n", num);
	if(num < 0){
		printf("This number is negative.\n");
	}
	/*The printf inside the if statement will only print if the condition in
	 * the if statement is true. If the condition is false, the printf won't
	 * run. We could add another if statement to check if the number is positi-
	 * ve (including zero as positive):*/
	if(num >= 0){
		printf("This number is positive.\n");
	}
	/*Furthermore, if we didn't want to include zero in our positive range, we
	 * can add a third if statement to check for zero:*/
	if(num > 0){
		printf("This number is greater than zero.\n");
	}
	if(num == 0){
		printf("This number is equal to zero.\n");
	}
	/*Basic, but neat huh? Remember, == is not the same as =. Once assigns a 
	 * value and the other one asks if two values are the same. Now, nothing
	 * would change if num was a decimal number, we would only have to change
	 * int to float or double. Using characters is similar:*/
	char my_char;
	getchar(); //to clean the "input tape"
	printf("Please give me a letter: ");
	scanf("%c", &my_char);
	printf("The letter you entered is: %c\n", my_char);
	if(my_char == 'F'){
		printf("Best of luck next semester!\n");
	}
	/*Notice the single quotes however. If we don't put those, we would get an
	 * error. Additionally, we can also check with the ascii number of F:*/
	if(my_char == 70){
		printf("Best of luck next semester!\n");
	}
	/*Making sense? If statements have a counterpart, else statements. If the
	 * condition in the if statement is false, the else statement takes over:*/
	float savings = 50456.25;
	if(savings > 40000){
		printf("You have reached your goal, good stuff!\n");
	}else{ //if savings is less than or eqaul to 40K
		printf("Not quite there, but closer, keep it up!");
	}
	/*Another example:*/
	int age;
	printf("How old are you? ");
	scanf("%d", &age);
	printf("The age you entered is %d\n", age);
	if(age >= 60){
		printf("Nice, you get a 10%% discount at Dairy Queen!\n");
	}else{
		printf("You are too young little one.\n");
	}
	
	//TODO create code/tutorial for the following items
	//In class we talked about if and if-else
	//We covered logical operators (&& and ||)
	//WE looked at the drinking example, including under 0 ages
	//We talked about the main difference between if-else and if-if
	
	//Let's jump into some more complex stuff "Nested if and else" statements.
	//Remember the example of drinking age? Let's revisit it, but this time
	//with Nested if-else:
	int x;
	printf("How old are you? ");
	scanf("%d", &x);
	if(x < 0){
		printf("Age can't be lower than 0\n");
	}else if(x < 18){ 
		printf("You can't neither drink Mexico nor in the USA\n");
	}else{ //if x>=18
		if(x<21){
			printf("You can drink in Mexico, but you can't drink in the USA\n");
		}else{ //x>=21
			printf("You can drink in both countries, cheers!\n");
		}
	}
	/*The only case in which we would enter the first else case (first layer),
	 * is if the user is over 18. Then, inside this else case, we have two more
	 * cases, is the user over 21 or is it not? So, all our cases are covered,
	 * but this time we did so in a different fashion. Now, let me ask you.
	 * What if both countries didn't let people over 70 years drink? Adding a
	 * third layer of if-else, where would you add it? That is correct, we
	 * would add it in the second-layer else:*/
	printf("How old are you? ");
	scanf("%d", &x);
	if(x < 0){
		printf("Age can't be lower than 0\n");
	}else if(x < 18){ 
		printf("You can't neither drink Mexico nor in the USA\n");
	}else{ //if x>=18
		if(x<21){
			printf("You can drink in Mexico, but you can't drink in the USA\n");
		}else{ //x>=21
			if(x<70){
				printf("You can drink in both countries, cheers!\n");
			}else{
				printf("Sorry, you can't drink due to our Senior's policy\n");
			}
		}
	}
	/*Let's look at another example, this time using two variables. Let's say
	 * you are planning to buy some stocks. You go to the stock market and you
	 * are asked two questions: initial investment and monthly installments.
	 * From there, they give you different options:*/
	float initial, monthly;
	printf("Initial investement? ");
	scanf("%f", &initial);
	printf("Monthly installment amount? ");
	scanf("%f", &monthly);

	printf("Given your initial investment we think you can invest in:\n");
	if(initial >= 0 && initial < 20000){
		printf("Satellite, Little Bear Coffee or Michael Thomas.\n");
		printf("However, given your monthly installment, we think your best ");
		printf("option is: ");
		if(monthly > 0 && monthly < 500){
			printf("Michael Thomas\n");
		}else if(monthly >= 500 && monthly < 800){
			printf("Little Bear Coffee\n");
		}else{ //monthly >= 800
			printf("Satellite\n");
		}
	}else{ //if initial >= 20K
		printf("Starbucks or Dutch Bros\n");
		printf("However, given your monthly installment, we think your best ");
		printf("option is: ");
		if(monthly > 0 && monthly < 1200){
			printf("Dutch Bros\n");
		}else{ //monthly >= 1200
			printf("Starbucks\n");
		}
	}
	/*Capeesh? Somewhat interesting huh? And you can have as many layers of
	 * if-else statements and as many conditions inside their parenthesis.
	 * Additionally, you will see that we can also combine if-else statements
	 * and loops. Let's print some integers (one by one) in either a bacward
	 * a forward manner; we will let the user decide:*/
	getchar();
	int start, stop, i;
	char BorF;
	printf("Would you like to print backward or forward? [B or F]\n");
	scanf("%c", &BorF);
	printf("Where would you like to start? ");
	scanf("%d", &start);
	printf("Where would you like to stop? ");
	scanf("%d", &stop);
	if(BorF == 'B'){
		printf("Printing Backwards:\n");
		i = start;
		while(i>stop){
			printf("%d  ", i);
			i--;
		}
		printf("\n");
	}else if(BorF == 'F'){
		printf("Printing Forwards:\n");
		for(i = start; i < stop; i++){
			printf("%d  ", i);
		}
		printf("\n");
	}else{
		printf("I can't recognize that letter, please try again.\n");
	}
	/*Can you all think of another way of checking whether the user wants to
	 * print forwards or backwards, without using BorF? That is correct, using
	 * start and stop, we can check the relationship between these two (which
	 * one is smaller than the other one) to determine how the user is wanting
	 * to print the integers. Next, let's discuss some tweaks. First, let's
	 * talk about how numbers have an interesting property when it comes to lo-
	 * gic (false or true). Anything that isn't zero will always default to
	 * true; leaving zero to always default to false. Check this out:*/
	int N = 1;
	if(N){
		printf("The value in N defaults to true\n");
	}else{
		printf("The value in N defaults to false\n");
	}
	/*If you change the value of N to 0, you'll see that the second printf sta-
	 * tement will print, instead of the first one. Next tweak, the negation
	 * operator. If something is true, this guy will make if false. Same case
	 * for when something is false. For example:*/

	printf("Please give me an integer: ");
	scanf("%d", &x);
	if(!x){
		printf("Hello\n");
	}	
	/*If the user inputs 0, 'Hello' will be printed. If the user inputs any-
	 * thing else, nothing will be printed. Since, 0 stands for false and is
	 * being negated (switched to true), this is the only moment in which 
	 * 'Hello' will be printed. Let's look at another example. Let's say you
	 * work at a bar in the US and you are checking for people's age, if
	 * their age is NOT greater than 21, you don't accept them:*/
	printf("How old are you? ");
	scanf("%d", &x);
	if( !(x>=21) ){
		printf("Sorry, but you are too young, get a fake!\n"); //JK!
	}

	//TODO talk about while(1) when talking about 0=false in if-else
	//TODO also, talk about loops and multiple conditions
	
	/*There is a fourth datatype that we haven't discussed yet. It is related
	to logic, so I think it fit to introduce it here:*/
	_Bool over21;
	int AGE;
	printf("How old are you?");
	scanf("%d", &AGE);
	if(AGE >= 21){
	    over21 = 1;
	}else{
	    over21 = 0;
	}
	
	if(over21){
	    printf("You can drink in the US\n");
	}else{
	    printf("You are too young to drink in the US\n");
	}
	/*Useful when there are only two cases, true or false, yes or no. Let's look
	at another example:*/
	_Bool over2_0;
	float GPA;
	printf("What is your GPA?");
	scanf("%f", &GPA);
	if(GPA >= 2.0){
	    over2_0 = 1;
	}else{
	    over2_0 = 0;
	}
	
	if(over2_0){
	    printf("You can apply for this Scholarship\n");
	}else{
	    printf("You can't apply for this Scholarship\n");
	}
	/*And, if you don't like the concept of "_Bool" and 0,1 for false and true,
	we can use stdbool.h to fix that. Let's repeat the age exmaple:*/
	bool Over21;
	printf("What's your age again?");
	scanf("%d", &AGE);
	if(AGE >= 21){
	    Over21 = true;
	}else{
	    Over21 = false;
	}
	
	if(Over21){
	    printf("You can drink in the US\n");
	}else{
	    printf("You are too young to drink in the US\n");
	}
	/*That's right, instead of declaring with "_Bool", you declare with "bool".
	Instead of setting equal to 0 (when false), you set equal to "false". And
	instead of setting equal to 1 (when true), you set equal to "true".*/
	
	/*There is a decision making element that I forgot to mention. Is called 
    conditional operator. In one line (most of the times), it allows your pro-
    gram to make a decision. For example, let's go back to the example in which
    we ask the user for a number and return its absolute value:*/
    int value;
    printf("Please provide an integer number: ");
    scanf("%d", &value);
    printf("The value you provided is: %d\n", value);
    
    if(value < 0){
        value *= -1;
    }
    
    printf("The absolute value of the number you provided is: %d\n", value);
    
    /*Now, let's look at the same example using the conditional operator:*/
    printf("\nPlease provide an integer number: ");
    scanf("%d", &value);
    printf("The value you provided is: %d\n", value);
    int abs_val = (value < 0) ? value * -1 : value;
    printf("The absolute value of the number you provided is: %d\n", abs_val);
    /*What we do is: we put a condition inside the parenthesis, we follow this
    by a question mark and then list two options splitted by a colon. If the 
    condition inside the parenthesis is true, abs_val will equal option 1 (op-
    tion on the left side of the colon); if the condition is false, abs_val will
    equal option 2 (option on the right side of the colon). Notice that I decla-
    red and initialized in the same line. If I wanted to, I could have declared
    abs_val in one line and initialized it on another one. Let's look at another
    example using booleans. We will look at the over 21 example again, with a
    slight change:*/
    int age;
    bool over21, over16;
    printf("\nHow old are you? ");
    scanf("%d", &age);
    over21 = (age < 21) ? false : true;
    over16 = (age < 16) ? false : true;
    
    if(over21 && over16){
        printf("You can drive and drink in the US.\n");
    }else if(!over21 && over16){
        printf("You can drive, but you can't drink in the US.\n");
    }else{
        printf("You can't drive nor drink in the US.\n");
    }
	/*Question, in the first if, do I have to check for both? Answer: no.*/
    
    /*I won't go in depth, but I will mention that you can have multiple con-
    ditions inside the conditional operator. For example, if we wanted to check
    for negative values in our previous example, we could have done:*/
    bool under0, under21, under16;
	
	printf("\nHow old are you? ");
	scanf("%d", &age);
	under0 = (age < 0) ? true : false;
	under16 = (age >= 0 && age < 16) ? true : false;
	under21 = (age >= 0 && age < 21) ? true : false;
	
	if(under0){
		printf("Ages can't be negative, please start over.\n");
	}else if(under16 && under21){
		printf("You can't drive nor drink in the US.\n");
	}else if(!under16 && under21){
		printf("You can drive, but you can't drink in the US.\n");
	}else{
		printf("You can drive and drink in the US.\n");
	}
	/*Again, there is an infinite way of making a program work.*/
    //TODO talk about how it may be unsafe to compare between decimal
    //numbers. Use a long float to show that floats are not "exact".
	return 0;
}
