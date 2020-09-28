/******************************************************************************
  * File:	04b_switch.c
  * Author:	Mario Esparza
  * Date:	08/30/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * In this program I will cover:
  * - TODO switch, break and continue
******************************************************************************/
#include <stdio.h>

int main(){
	/*Aside from if-else statements, there is another method we can use to have
	 * our programs make decisions; with the help of the switch statement:*/
	char grade;
	printf("What's your current grade in the class? ");
	scanf("%c", &grade);
	switch(grade){
		case 'A':
			printf("Nice you have an A in the class.\n");
			break;
		case 'B':
			printf("Nice you have a B in the class.\n");
			break;
		case 'C':
			printf("Nice you have a C in the class.\n");
			break;
		case 'F':
			printf("Alright, we gotta improve it!\n");
			break;
		default:
			printf("Unkown grade :(\n");
			break;
	}
	/*Given a variable, we create cases and if such is equal to one of the
	 * cases, bingo, that case runs. If none of the cases is met, the default 
	 * case runs (default case is not mandatory, you can remove it if you want,
	 * but I highly recommend it you keep it). The setback of switch statements
	 * is that you can't check ranges. If we were to try and do the age's exam-
	 * ple here, we would have to create a single case for each year; painful
	 * right? The break statement is of ample importance here, if we forget it,
	 * we may get unexpected results: Try inputting A or B in the following
	 * example.*/
	getchar(); //to clean the "input" line
	printf("What's your current grade in the class? ");
	scanf("%c", &grade);
	switch(grade){
		case 'A':
			printf("Nice you have an A in the class.\n");
		case 'B':
			printf("Nice you have a B in the class.\n");
		case 'C':
			printf("Nice you have a C in the class.\n");
			break;
		case 'F':
			printf("Alright, we gotta improve it!\n");
			break;
		default:
			printf("Unkown grade :(\n");
			break;
	}
	/*Your insight is correct. If we miss the break statement, the next case
	 * runs. And if that case is also missing a break statement, the following
	 * case runs. And so on and so forth. This however, can be benefitial for
	 * us. For example, what if I wanted to accept lower case inputs in the
	 * previous example? We could do something like this:*/
	getchar(); //to clean the "input" line
	printf("What's your current grade in the class? ");
	scanf("%c", &grade);
	switch(grade){
		case 'A':
		case 'a':
			printf("Nice you have an A in the class.\n");
			break;
		case 'B':
		case 'b':
			printf("Nice you have a B in the class.\n");
			break;
		case 'C':
		case 'c':
			printf("Nice you have a C in the class.\n");
			break;
		case 'F':
		case 'f':
			printf("Alright, we gotta improve it!\n");
			break;
		default:
			printf("Unkown grade :(\n");
			break;
	}
	/*We create a second case for each grade (this time with the lower case
	 * letter) and do not add a break statement. This way, if the user inputs
	 * a or A, the output will be the same one.*/

	/*Aside from the switch statement, break can also be used inside loops. It
	 * can be used to "break" the loop (exit out of it) if a condition is met.
	 * For example:*/
	printf("How many customers are in this table? ");
	int num;
	scanf("%d", &num);
	float sum = 0.0, tip;
	int i;
	for(i=0; i<num; i++){
		printf("How much did customer %d tipped? ", i+1);
		scanf("%f", &tip);
		if(tip < 0.0){
			printf("Tips can't be negative, please start over.\n");
			break;
		}else{
			sum = sum + tip;
		}
	}
	printf("Total tip of the table is %.2f\n", sum);
	/*In this example, we ask the user for tips amounts and keep track of them.
	 * At the end, we display the total to the user. However, if the user in-
	 * puts an invalid number (negative number), we exit the loop and stop as-
	 * king for tips. Cool huh? But non-efficient if you ask me. Instead of
	 * terminating the loop and telling the user to start over, how do you
	 * think we could just ask for the value again? Answer: instead of doing
	 * break, we do i-- (this will reset the iteration and repeat it):*/
	printf("How many customers are in this table? ");
	scanf("%d", &num);
	sum = 0.0, tip;
	for(i=0; i<num; i++){
		printf("How much did customer %d tipped? ", i+1);
		scanf("%f", &tip);
		if(tip < 0.0){
			printf("Tips can't be negative, please input it again.\n");
			i--;
		}else{
			sum = sum + tip;
		}
	}
	printf("Total tip of the table is %.2f\n", sum);
	/*Yaaas! Our program is a bit more efficient, if the user has 12 customers
	 * he/she doesn't have to re-input all tips in case a mistake is made. Now,
	 * aside from break, there is another statement that can come handy in
	 * loops, let's give it a look. First of all, what will this loop do?*/
	int j;
	for(j=0; j<5; j++){
		printf("Good Morning\n");
		printf("Everyone\n");
		printf("Today\n");
		printf("Is Tuesday\n\n");
	}
	/*That is correct, it will print all four statements 5 times. Now, let's
	 * say that we want to break in the third iteration. We could do so as fo-
	 * llows:*/
	for(j=0; j<5; j++){
		printf("Good Morning\n");
		printf("Everyone\n");
		if(j==2){
			printf("You have reached the third iteration, bye bye\n\n");
			break;
		}
		printf("Today\n");
		printf("Is Tuesday\n\n");
	}
	/*The loop broke (stopped) and after the third iteration nothing else
	 * printed right? Well, this statement that we will cover, doesn't exit the
	 * loop, but instead it "breaks" the iteration. Check it out:*/
	for(j=0; j<5; j++){
		printf("Good Morning\n");
		printf("Everyone\n");
		if(j==2){
			printf("You have reached the third iteration, bye\n\n");
			continue;
		}
		printf("Today\n");
		printf("Is Tuesday\n\n");
	}
	/*You can see that only the third iteration was affected, anything that ca-
	 * me after the continue statement didn't print for that particular itera-
	 * tion. After that, eveything continued as normal. Which reminds me, a
	 * tool like this could have been used in the resetting-iteration example:*/
	printf("How many customers are in this table? ");
	scanf("%d", &num);
	sum = 0.0, tip;
	for(i=0; i<num; i++){
		printf("How much did customer %d tipped? ", i+1);
		scanf("%f", &tip);
		if(tip < 0.0){
			printf("Tips can't be negative, please input it again.\n");
			i--;
			continue;
		}

		sum = sum + tip;
	}
	printf("Total tip of the table is %.2f\n", sum);
	/*Instead of using an else statement, we take advantage of the continue
	 * statement. And, to make it even better, we could:*/
	printf("How many customers are in this table? ");
	scanf("%d", &num);
	sum = 0.0, tip;
	for(i=0; i<num;){
		printf("How much did customer %d tipped? ", i+1);
		scanf("%f", &tip);
		if(tip < 0.0){
			printf("Tips can't be negative, please input it again.\n");
			continue;
		}

		sum = sum + tip;
		i++;
	}
	printf("Total tip of the table is %.2f\n", sum);
	/*We put i++ at the end of the loop. This way, if a mistake is done by the
	 * user, we don't have to use i--, but rather, i++ will be ignored. Same
	 * can be done in a while loop, try it out.*/
	return 0;
}

