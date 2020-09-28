/******************************************************************************
  * File:	02_chars_and_ascii.c
  * Author:	Mario Esparza
  * Date:	08/18/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * In this program I will cover:
  * - characters
  * - ascii table
  * - comments
******************************************************************************/
#include <stdio.h>

int main(){
	/*So far, we have only seen variables with numeric values. It turns out
	variables can also have characters as values. For example:*/
	char my_character = 'g';
	printf("Your character is %c\n", my_character);
	/*Datatype is "char", format character is %c and there is something
	else to notice, when initializing a character, you have to enclose it
	in single quotes. Otherwise you will get an error:*/
	//char my_Character = g;
	/*Your program will think the right side of your equal is another va-
	riable. So remember, single quotes when initializing characters. Let's
	look at another example:*/
	char c1='H', c2='e', c3='l', c4='l', c5='o';
	printf("%c%c%c%c%c\n", c1, c2, c3, c4, c5);
	/*Is this crazy or what?*/

	/*EVen crazier is to think that characters are in reality just numbers.
	Do you remember when I told you that computers only understand numbers?
	Well, this would explain everything then huh? Let me show you. I will
	declare and initialize a character and I will print it with %d.*/
	char another_char = 't';
	printf("The numeric value of t is: %d\n", another_char);
	/*"Say whaaaa three times, but you said each datatype has its own for-
	mat character!" Well, yes, but in this case, since characters are num-
	bers (integers to be more specific), we can use %d to get their numeric
	values. Does anyone know where we can get a list of characters and
	their numeric values? ... ASCII!*/

	/*If you know the number of your character, you can use	this number,
	along with %c to print out the character. For instance,	let's use 65 to
	print A:*/
	printf("The character is: %c\n", 65);
	/*And we can do it using an integer variable:*/
	int my_var = 65;
	printf("The character is: %c\n", my_var);

	/*Another interesting thing is that, you can apply arithmetic opera-
	tions to characters. For example:*/
	char my_char = 'a';
	printf("The character you chose is: %c\n", my_char);
	my_char = my_char + 1;
	printf("Adding my_char by one results in: %c\n", my_char);
	my_char = my_char + 1;
	printf("Adding one once again, results in: %c\n", my_char);
	/*Pretty neat huh? We can subtract, multiply and divide. Whichever nu-
	meric value the character has, it will be treated as an integer when
	used in arithmetic operations. One last example: */
	char this_char = '9';
	printf("The character you chose is: %c\n", this_char);
	this_char = this_char - 1;
	printf("Subtracting this_char by one results in: %c\n", this_char);
	this_char = this_char - 1;
	printf("Subtracting one once again, results in: %c\n", this_char);
	/*It is important to remember that '9' doesn't equal 9. One is a cha-
	racter with a numeric representation of 57 and the other one is an in-
	teger with value 9. Don't mix them up!*/

	/*Last thing I want to mention about characters is: how to scan them.
	We use scanf and %c, just like we have done with the other datatypes:*/
	char c99;
	printf("Please provide a character: ");
	scanf("%c", &c99);
	printf("This is your character: %c\n", c99);

	/*In our codes, is sometimes necessary to have some guidance, something
	that reminds us what the whole code is about. In some other times, we
	may need a remainder for single chunks of code. These remainders are
	called comments. Throughout our code we can have single line comments
	or paragraph-long comments:*/

	//This is a single line comment. You start with two forward slashes

	/*This is a paragraph-long comment. Whenever your comment occupies more
	than 2 or three lines of code, you may want to use this kind of comment
	Notice that comments have a different color. Use this color to remind
	you that comments are not read by the compiler, they are ignored. They
	are meant to help humans, not the computer. That's why you have the 
	double forward slash or the asterisk forward slash. Whenever the compi-
	ler sees any of these two, it knows to ignore it.*/

	return 0;
}
