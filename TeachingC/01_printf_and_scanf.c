/******************************************************************************
  * File:	01_printf_and_scanf.c
  * Author:	Mario Esparza
  * Date:	08/18/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * In this program I will cover:
  * - printf statements (\n and \t)
  * - declaration vs initialization
  * - ints, floats, doubles and their format characters
  * - scanf statements
  * - arithmetic operations
  * - assignment operators
******************************************************************************/
#include <stdio.h>

int main(){
	/*Let's use Hello World again, but this time, let's add something weird
	at the end.*/
	printf("Hello World!\n");
	/*Can you see the difference? Here, let's print it as we did in the
	last program:*/
	printf("Hello World!");
	/*Easier to find the difference? The '\n' is called the new line cha-
	racter; and that is exactly what it does, is like if you would have
	pressed the enter key in your keyboard. If we wanted to, we could print
	hello world in two different lines. We could do so like this:*/
	printf("Hello\n");
	printf("World!\n");
	/*Or we could do so like this:*/
	printf("Hello\nWorld!\n");
	/*...using 2 '\n' inside the printf statement. Makes sense?*/

	/*Now, in addition to the new line char, we have another character that
	can help us manipulate our outputs. Let's say you are teaching a class
	and you want your program to display the grades of your students. We
	could do something like this:*/
	printf("The grades are:\n");
	printf("Joe -> 9.32\n");
	printf("Kim -> 9.79\n");
	printf("Sam -> 8.49\n");
	/*It works! But let's say I wanted to add more style and indent those
	lines where the grades are being displayed. We can do so like this:*/
	printf("The grades are:\n");
	printf("\tJoe -> 9.32\n");
	printf("\tKim -> 9.79\n");
	printf("\tSam -> 8.49\n");
	/*Where '\t' is acting as if you had press the tab key in your keyboard
	Really helpful when you want to indent your output.*/

	/*Now that we have seen how to manipulate text in our printf statements
	we are ready to jump into something a bit more complex. Just like in
	math, in your program, you can create numerical variables. Elements of
	your program that will hold numerical values. If I had a rectangle of
	height 3 and width 5, and I wanted to calculate its area, I could do so
	as follows in my program:*/
	int width = 5;
	int height = 3;
	int area_rect = width * height;
	/*"width", "height" and "area_rect" are the names of my variables and
	the keyword "int" tells my program that these three variables are going
	to hold integer values. To display these variables in the terminal we
	would do the following:*/
	printf("The width of your rectangle is %d\n", width);
	printf("The height of your rectangle is %d\n", height);
	printf("The area of the rectangle is %d\n", area_rect);
	/*We use a printf statement and we place a %d where we want the value
	of our variable to be printed. %d is a "format character" and we use it
	when we are trying to print integers. Furthermore, we can print	all 3
	variables in the same printf statement if we wanted to:*/
	printf("Here is the equation:\n");
	printf("%d * %d = %d\n", width, height, area_rect);
	/*Each variable separated by a comma in the order in which we want them
	printed. Pretty neat huh? Let's go ahead and repeat the process, but
	this time, by calculating the area of a circle:*/
	float radius = 2.5;
	float pi = 3.1416;
	float area_circle = radius * radius * pi;
	/*Since we are using decimal values, I had to change the prefix of our
	variables. Instead of using "int", I used "float". This tells our pro-
	gram that these three variables will hold decimal values. These pre-
	fixes are valled datatypes, and as mentioned before, they state which
	kind of value our variables can hold. So now, if we wanted to print
	these 3 float values, we can do so as follows:*/
	printf("The radius of your circle is %f\n", radius);
	printf("The constant pi is %f\n", pi);
	printf("The area of your circle is %f\n", area_circle);
	/*Where we have to change the format character. Instead of using %d, we
	are using %f. If we use %d, we would get an error/warning:*/
	printf("The radius of your circle is %d\n", radius);
	printf("The constant pi is %d\n", pi);
	printf("The area of your circle is %d\n", area_circle);
	/*So keep track of your datatypes and format characters. Something neat
	about C and decimals is that we can control how many decimals to print.
	If for instance, we only wanted to print 2 decimals of each of the
	circle variables, we could do so as follows:*/
	printf("The radius of your circle is %.2f\n", radius);
	printf("The constant pi is %.2f\n", pi);
	printf("The area of your circle is %.2f\n", area_circle);
	/*We add a dot and a number (the number of decimal spaces that we want)
	before "f". IS EVERYTHING MAKING SENSE SO FAR?*/

	/*So far, we have seen how to declare a variable and initialize it ma-
	nually. What if I told you that we can initialize a variable by asking
	the user? In other words, what if I told you that the user can assign a
	value to one of our variables? To do so, we have to do the following:*/

	//First, declare the variable
	int my_variable;
	//Next, display a message to the user
	printf("Hi, please provide an integer number: ");
	//Next, grab the value with "scanf"
	scanf("%d", &my_variable);
	//Finally, display the value to ensure it was grabbed correctly:
	printf("The number you entered is: %d\n", my_variable);
	/*Is that cool or wha?*/

	/*Let's try it again. This time, let's use two floats:*/
	float X, Y;
	printf("Please provide a value for X: ");
	scanf("%f", &X);
	printf("Please provide a value for Y: ");
	scanf("%f", &Y);
	printf("The values you entered are: X=%.2f and Y=%.2f\n", X, Y);

	/*This doesn't mean these values are absolute (can't be changed). We
	can ask the user for a different value for X for example:*/
	printf("Please provide a new value for X: ");
	scanf("%f", &X);
	printf("The new value of X is: %.2f\n", X);
	
	/*scanf is also "sensitive" in regards of the format character and the
	input given. If scanf is expecting an integer, an integer should be in-
	putted. If a float is being expected, a float should be given. So on
	and so forth*/
	
	/*Additionally, scanf allows you to bound numbers or elements with
	characters. This way, you can ask the user for something in a particu-
	lar format. For example, let's say you ask the user for the time and
	the user MUST enter a colon in between. You could do so like this:*/
	int hour;
	int min;
	printf("Please provide the time in this format: [hh:mm]\n");
	scanf("%d:%d", &hour, &min);
	printf("The time you inputed is: %d:%d\n", hour, min);
	/*Just like we saw in printf, you can scan multiple items at the same
	time. If you try to insert the time with a space, instead of a colon,
	you will get weird results. Try it here:*/
	printf("Please provide the time in this format: [hh:mm]\n");
	scanf("%d:%d", &hour, &min);
	printf("The time you inputed is: %d:%d\n", hour, min);
	/*This is why, it is important that the user follows the format asked
	for. Notice that if I input a one digit number, it doesn't print with
	a leading zero; aesthetically, it would look better wouldn't it? To add
	leading zeros you can the following:*/
	printf("Please provide the time in this format: [hh:mm]\n");
	scanf("%d:%d", &hour, &min);
	printf("The time you inputed is: %02d:%02d\n", hour, min);
	/*If you change 02 to a 03, you will have two leading zeros for numbers
	with 1 digit and one leading zero with numbers with 2 digits.*/

	/*In addition to floats, C has another kind of decimal datatype. It is
	called "double" and it stands for double precision. In other words, a
	double is a decimal with more precision than a float. Let me use
	doubles to explain the difference between DECLARATION and INITIALIZA-
	TION:*/
	double x;
	double y;
	double z;
	/*To declare a variable, is to prefix the name of a variable with a
	datatype (int, float, double). You are telling your program to save
	memory for this variable. At this point, x, y and z have values, but
	they are random values. Let me print them:*/
	printf("x = %lf, y = %lf, z = %lf\n", x, y, z);
	/*The format character for doubles is %lf. Notice that all three of
	them printed values that were never assigned to them.*/
	x = 1.1;
	y = 2.2;
	z = 10.3;
	/*To initialize a variable, is to assign a value to such, therefore,
	to remove the random value it had. If we reprint these variables, we'll
	see the difference:*/
	printf("x = %lf, y = %lf, z = %lf\n", x, y, z);
	/*As previously seen, we can also declare and initialize a variable in
	the same line:*/
	double a = 2.35;
	double b = 8.59;

	/*Let's look at some arithmetic operations using doubles:*/
	double mult = a * b; //multiplication
	double div = a / b;
	double add = a + b;
	double sub = a - b;
	/*We can also include literal numbers into our operations:*/
	double add2 = a + 5.6;
	double mult2 = b * 8.54;
	/*We can have more than 2 values in an operation:*/
	double sub2 = a - b - 5.46 + 8.94;
	/*But even better, we can use the same variable to perform and opera-
	tion and reassign itself a different value. For example:*/
	double savings = 0.0;
	/*We get paid and we decide to save $159.00. We then have to update
	our savings account:*/
	savings = savings + 159.00;
	/*Next paycheck comes in, and we decide to save $182.00:*/
	savings = savings + 182.00;
	/*You can also subtract from it if you grabbed some money for an iphone
	case for example:*/
	savings = savings - 62.00;
	/*Making sense?*/

	/*Let's look at another example. Imagine you want to keep track of the
	multiples of 3. We can use an integer variable to do this:*/
	int mults_of_3 = 1;
	printf("At the beginning, mults_of_3 = %d\n", mults_of_3);

	mults_of_3 = mults_of_3 * 3;
	printf("After one multiplication, mults_of_3 = %d\n", mults_of_3);

	mults_of_3 = mults_of_3 * 3;
	printf("After two multiplications, mults_of_3 = %d\n", mults_of_3);

	mults_of_3 = mults_of_3 * 3;
	printf("After three multiplications, mults_of_3 = %d\n", mults_of_3);

	mults_of_3 = mults_of_3 * 3;
	printf("After four multiplications, mults_of_3 = %d\n", mults_of_3);
	/*"Prity" neat huh? You can do this with any operator. Since this looks
	repetitive, pioneer programmers created something to make our lives a
	bit easier (type a little less): mults_of_3 = mults_of_3 * 3; could be
	typed as mults_of_3 *= 3; You don't believe me? Let's start over, but
	this time with multiples of 4:*/
	int mults_of_4 = 1;
	printf("At the beginning, mults_of_4 = %d\n", mults_of_4);
	mults_of_4 *= 4;
	printf("After one multiplication, mults_of_4 = %d\n", mults_of_4);
	mults_of_4 *= 4;
	printf("After two multiplications, mults_of_4 = %d\n", mults_of_4);
	mults_of_4 *= 4;
	printf("After three multiplications, mults_of_4 = %d\n", mults_of_4);

	/*We could have done the same thing with our savings!*/
	printf("Current value of savings is: %.2lf\n", savings);
	/*Another salary comes our way and we decide to save $381.00:*/
	savings += 381;
	/*Yet another month passes by and we decide to save $134.00:*/
	savings += 134;
	/*Oh no, I got a flat tire, minus $120.00:*/
	savings -= 120;

	/*These guys are called "Assignment Operators". They help us assign
	values to the same variable (and using its previous value) in a short
	way. Does it make sense?*/

	/*Before we move on to a different topic, I want to add that we have a
	5th arithmetic operator: the "modulo" operator (%). From a division of
	two numbers, it returns the remainder:*/
	int remainder;
	remainder = 17%5;
	printf("The remainder of 17 divided by 5 is: %d\n", remainder);

	remainder = 24%10;
	printf("The remainder of 24 divided by 10 is: %d\n", remainder);

	/*It works with variables too:*/
	int dividend = 19;
	int divisor = 9;
	remainder = dividend%divisor;
	printf("The remainder of %d divided by %d is: %d\n", dividend, divisor, remainder);

	/*The last thing that I want to mentiong about arithmetic operations is
	that it is perfectly fine to have them in a printf statement:*/
	printf("Two plus two equals %d\n", 2+2);
	float float1 = 25.5;
	printf("25.5 * 2.2 = %.3f\n", float1*2.2);
	double doub1 = 25.64;
	double doub2 = 35.01;
	printf("%.2f - %.2f = %.2f\n", doub1, doub2, doub1 - doub2);

	/*There are some interesting concepts between integers and floats that
	we haven't discussed yet. Try to guess the values of these variables:*/
	int val1 = 25;
	int val2 = 35.65;
	int val3 = 5/2;
	float val4 = 5/2;
	/*To change this, we do CASTING:*/
	float val5 = ((float) 5)/2;
	/*The 5, for this particular instance became 5.0 => 2.5. This is why
	you had weird results in your HW.*/

	/*Something that I haven't shown you is that we can declare multiple
	variables in the same line at the same time:*/
	int a1, a2, a3;
	float f1, f2, f3;
	/*Or, we can declare and initialize multiple variables in the same
	line:*/
	double d1 = 1.10, d2 = 2.5, d3 = 5.645;
	/*Both concepts are valid.*/

	/*Something else that we have excluded, is the conventions of naming
	variables. Unfortunately, we can't just call them whichever way we want
	We have to follow some rules/guidelines.*/
	printf("1) Variables are case sensitive:\n");
	int myVar = 10;
	printf("myVar = %d\n", myVar);
	int myVAR = 15;
	printf("myVAR = %d\n", myVAR);
	/*Although they have the same name, some of the characters are upper
	case in one of the name, while they aren't in the other name.*/
	printf("2) There are some reserved words, check book's chapter 3\n");
	printf("3) Variables should be declared once and only once\n");
	float decimal;
	decimal = 25.95;
	printf("decimal equals %.2f\n", decimal);
	//float decimal; //this will raise an error
	/*You can re-use them, but can't re-declare them:*/
	decimal = -24.56;
	printf("decimal equals %.2f\n", decimal);
	
	/*Since we have had a bit of progamming already, let me show you some
	Vim tricks/shortcuts: shift+a, x, dd, yy, p, gg, shift+g, shift+v.*/
	
	return 0;
}
