/******************************************************************************
  * File:	03_loops_and_loops.c
  * Author:	Mario Esparza
  * Date:	08/18/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * In this program I will cover:
  * - For loops, while loops, do-while loops
  * - Their syntax; some tweaks; combining them with scanf
  * - Having for loops with multiple variables (conditions)
******************************************************************************/
#include <stdio.h>

int main(){
	/*Imagine we wanted to print all numbers from 1 to 5 in increasing or-
	der. We could do so as follows:*/
	int i = 1;
	printf("%d\n", i);
	i = i + 1;
	printf("%d\n", i);
	i += 1; //remember this one?
	printf("%d\n", i);
	i += 1;
	printf("%d\n", i);
	i += 1;
	printf("%d\n", i);
	/*But what would happen if we wanted to print from 1 to 20 instead? Or
	1 to 100? It would take plenty lines of code wouldn't it? Then, what if
	I told you there is a cleaner way to perform this?*/
	for(i=1; i<=5; i+=1){
		printf("%d\n", i);
	}
	/*Such is the syntax of a for loop. It starts at 1, ends at 5 and adds
	one after each iteration. In each iteration, it prints out the current
	value of i. Notice that the stop condition is a <=. This is one of the
	six relative operators that we will see. Other three are: >=, < and >.
	Most, if not all of them, you should have already seen in any math
	class. In C, they "ask" questions. In this particular case, <= is as-
	king ig i is less than or eqaul to 5. We will see the other two opera-
	tors when we jump into if and else statements. Now, going back to loops
	if we wanted to print till 20, we would have to change the 5 to a 20:*/
	for(i=1; i<=20; i+=1){
		printf("%d\n", i);
	}
	/*If we only wanted to print from 15 to 20, we would do:*/
	for(i=15; i<=20; i+=1){
		printf("%d\n", i);
	}
	/*We can also print negative values:*/
	for(i=-5; i<=0; i+=1){
		printf("%d\n", i);
	}
	/*We can subtract instead of add:*/
	printf("We change <= to >=:\n");
	for(i=5; i>=0; i-=1){
		printf("%d\n", i);
	}
	/*And we can multiply or divide:*/
	for(i=1024; i>0; i/=2){
		printf("%d\n", i);
	}
	/*And notice that the operation doesn't have to be by one:*/
	for(i=1; i<=20; i+=3){
		printf("%d\n", i);
	}
	/*I start at 1, until I reach 20 or less in jumps of 3 units. Neat as
	heck huh? Is everything making sense though? Let's look at a tougher
	example. Let's use triangular numbers (0, 1, 3, 6, 10, 15 ...).*/
	int j = 0;
	int tn = 0;
	tn = tn + j;
	printf("Triangular number 0: %d\n", tn);
	//update j and tn
	j += 1;
	tn = tn + j;
	printf("Triangular number 1: %d\n", tn);
	//repeat
	j += 1;
	tn = tn + j;
	printf("Triangular number 2: %d\n", tn);
	//one more time
	j += 1;
	tn = tn + j;
	printf("Triangular number 3: %d\n", tn);
	//yet, one more time
	j += 1;
	tn = tn + j;
	printf("Triangular number 4: %d\n", tn);
	/*There is a pattern/repetition going on right? A perfect candidate for
	a loop:*/
	tn = 0;
	for(j=0; j<=4; j+=1){
		tn = tn + j;
		printf("%d --> ", tn);
	}
	printf("...\n");
	/*Instead of using the arrow, we can list them using our iterator j:*/
	tn = 0;
	for(j=0; j<=4; j+=1){
		tn = tn + j;
		printf("Triangular number %d: %d\n", j, tn);
	}
	/*One last thing, we can do "tn += j;"*/
	tn = 0;
	for(j=0; j<=4; j+=1){
		tn += j;
		printf("Triangular number %d: %d\n", j, tn);
	}
	/*BEATIFUL! Is everything making sense so far? Okidoki, aside from for
	loops, there are two other loop methods we can use in C. We have while
	loops:*/
	int k = 0;
	while(k<=5){
		printf("%d\n", k);
		k+=1;
	}
	/*Repeating what we did in the first for loop. Notice that the start,
	stop and step are located in different sections; they are not in the
	same line. Let's look at the triangular number example using while
	loop:*/
	k = 0;
	tn = 0;
	while(k<=4){
		tn += k;
		printf("Triangular number %d: %d\n", k, tn);
		k += 1;
	}

	/*And we have do-while loops:*/
	k = 0;
	do{
		printf("%d\n", k);
		k+=1;
	}while(k<=5);
	/*Your loop will DO whatever is inside the brackest WHILE the condition
	is met. Once the condition isn't met, the loop stops. Keep an eye on the
	semicolon! Triangular example again? Here we go:*/
	k = 0;
	tn = 0;
	do{
		tn += k;
		printf("Triangular number %d: %d\n", k, tn);
		k += 1;
	}while(k<=4);
	/*Which loop method to use? Well, whichever you like the best. All
	loops can do exactly the same. There is only one main difference: 
	do-while loops always run once. This means that the condition comes
	after one iteration has already happened. Let me show you:*/
	int a;
	printf("Output of for loop:\n");
	for(a=0; a<0; a+=1){
		printf("%d\n", a);
	}

	printf("Output of while loop:\n");
	a = 0;
	while(a<0){
		printf("%d\n", a);
		a+=1;
	}

	printf("Output of do-while loop:\n");
	a = 0;
	do{
		printf("%d\n", a);
		a+=1;
	}while(a<0);
	/*For and while loops conditions are checked before any code is ran.
	Do-while loops conditions are checked after code is ran once. Now that
	we have covered all three loop methods, let's go ahead and talk about
	some tweaks. When you want to modify your iterator by one, you may find
	++ and -- to be better options:*/
	for(a=0; a<6; a++){
		printf("%d\n", a);
	}
	/*a++ acts as if you had a+=1 or a=a+1*/
	a = 5;
	while(a>-1){
		printf("%d\n", a);
		a--;
	}
	/*a-- acts as if you had a-=1 or a=a-1. These are called the increment
	and decrement operators. Tweak 1, check. Next one, let me show you how
	to indent without \t. Let's re-print our triangular numbers, the first
	15 of them:*/
	k = 0;
	tn = 0;
	while(k<=15){
		tn += k;
		printf("TN %d: %d\n", k, tn);
		k += 1;
	}
	/*Can you see that weird jump between TN 9 and TN 10? We can avoid it
	by adding %X, where X represents how many indents you want:*/
	k = 0;
	tn = 0;
	while(k<=15){
		tn += k;
		printf("TN %2d: %d\n", k, tn);
		k += 1;
	}
	/*We told our program to give each number 2 slots (from right to left)
	Let's give them 3 slots?*/
	k = 0;
	tn = 0;
	while(k<=15){
		tn += k;
		printf("TN %3d: %d\n", k, tn);
		k += 1;
	}
	/*If you care about tables and aesthetics, this could be one way of keeping
	 clean. Next in the tweak's list is ... having multiple variables in your
	 loops' conditions:*/
	int y, z;
	for(y=0, z=4; y<=4, z<10; y++, z+=2){
		printf("y = %d, z = %d\n", y, z);
	}
	/*b's stopping condition was "hit" first, therefore, y didn't get all the
	 way to 4. The stopping condition that gets "hit" first, is the one that
	 determines when the loop stops. Additionally, some conditions can be 
	 missing, for example:*/
	y = 0;
	for(; y<5; y++){
		printf("y=%d\n", y);
	}
	/*Here, we initialized y outside of the loop's parenthesis.*/
	y = 0;
	for(; y<5;){
		printf("y=%d\n", y);
		y++;
	}
	/*Here, we initialize y outside of the loop's parenthesis and we add it by
	 one inside the loop. We can also remove the stopping condition, but this
	 would make our loop run forever. BTW, to stop a running-forever loop in
	 the terminal, you type Ctrl+c. There is another way of stopping a loop in
	 a program, but we will look at it later. Just so you get the feeling, the
	 following loop will run forever, you will have to type Ctrl+c.*/
	/*y = 0;
	for(; ;){
		printf("y=%d\n", y);
		y++;
	}*/
	/*scanf tweak, can we use a loop to scan multiple times? Absolutely:*/
	int m = 0;
	float my_var;
	while(m<4){
		printf("Please provide a decimal value: ");
		scanf("%f", &my_var);
		printf("The value you inputted is %.2f\n", my_var);
		m++;
	}
	/*second scanf tweak, we scan for the start, stop and step values and use
	 * them in the loop conditions:*/
	int stop, step, start;
	printf("Let's print a set of integers.\n");
	printf("Where would you like to start? ");
	scanf("%d", &start);
	printf("Where would you like to stop? ");
	scanf("%d", &stop);
	printf("What would be the step between them? ");
	scanf("%d", &step);
	while(start < stop){
		printf("->%d", start);
		start += step;
	}
	printf("\n");
	/*And voila! We have covered Loops and its tweaks (most of them). Next,
	 let's learn how to make our program decide.*/

	return 0;
}
