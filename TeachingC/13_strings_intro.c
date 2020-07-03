/**************************************************************
  * File:	13_strings_intro.c
  * Author:	Mario Esparza
  * Date:	07/01/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * Program that covers the following:
  *		1. How to declare strings and the importance of the
  *		null character.
  * 	2. How to print strings using two different methods,
  *		%s and a loop with %c.
  *		3. How to scan strings using %s, scanf and getchar.
  *		4. How to use strings with functions.
  *
**************************************************************/
#include <stdio.h>

int countChars(char thisString[]){
	int i = 0, counter = 0;
	while(thisString[i] != '\0'){
		counter++;
		i++;
	}
	return counter;
	/*Notice that there is no real need for counter. We
	could use i as the counter.*/
}

void insertString(char str1[], char str2[], int start){
	//Let's print the strings
	printf("\nString 1 is: %s\n", str1);
	printf("\nString 2 is: %s\n", str2);
	//Get the lengths of the strings
	int L1 = countChars(str1);
	int L2 = countChars(str2);
	printf("\nString 1 has %d characters\n", L1);
	printf("\nString 2 has %d characters\n", L2);
	//Set L3 and declare what will be the resulting string
	int L3 = L1 + L2 + 1; //+1 for the null char
	char str[L3];
	str[L3-1] = '\0';
	printf("\nCheck 1, resulting string is: %s\n", str);
	//Copy str1 to str, only from 0 to "start"
	int i;
	for(i=0;i<start;i++){
		str[i] = str1[i];
	}
	printf("\nCheck 2, resulting string is: %s\n", str);
	//Copy str2 to str, i goes from start to start+L2
	//i is index of str, j is index of str2
	int j = 0;
	for(i=start;i<start+L2;i++){
		str[i] = str2[j];
		j++;
	}
	printf("\nCheck 3, resulting string is: %s\n", str);
	/*Copy the rest of str1 to str, i goes from start+L2
	to L1+L2-1. i is index of str, j is index of str1*/
	j = start;
	for(i=start+L2;i<L1+L2;i++){
		str[i] = str1[j];
		j++;
	}
	printf("\nCheck 4, resulting string is: %s\n", str);

	return;
}

int main(){
	/*Finally, we will look at the so mentioned "strings".
	These are not too different from arrays. You could even
	say that they are character arrays, with a tiny diffe-
	rence; the null character '\0' (will explain in a se-
	cond). As usual, let's start by declaring some
	strings:*/
	char firstString[] = "Hello";
	/*First thing to notice is the double quote notation.
	When declaring a string, you have to use double quotes
	to do so. The second thing to notice is that we didn't
	put anything inside the brackets. The compiler will
	automatically know how many slots this string needs.
	The third thing to notice is...if we look at "Hello" it
	would be obvious to imply that firstString has 5 ele-
	ments; however, behind the scenes, your program is ac-
	tually creating and initializing 6 elements. Five for
	"Hello" and one for the null character '\0'. A special
	character that gets situated (automatically) at the end
	of all strings (if declared correctly). You don't be-
	lieve me, I will prove it in a minute.*/

	/*Another way of declaring a string is as follows:*/
	char secondString[4] = "Bye";
	/*You set the length of the string in advance, ALWAYS
	giving an extra value for the null character.*/

	/*The declaration below is also valid. Your string will
	have 10 slots, "Arigato" will occupy slots 0 to 6, the
	null char will occupy slot 7, and slots 8-9 will be
	random chars. In other words, as soon as the characters
	in the string end, the null character is assigned right
	after, automatically.*/
	char thirdString[10] = "Arigato";

	/*Let's see how you can print the values inside a
	string. I'd say there are many methods, I will show you
	two. First method using a loop:*/
	int i = 0;
	printf("This is your string:\n");
	while(thirdString[i] != '\0'){
		printf("%c", thirdString[i]);
		i++;
	}
	printf("\n");
	/*Second method (which I think you will love):*/
	printf("\nThis is your string:\n");
	printf("%s\n", thirdString);
	/*Yes, strings have their own format character, neat
	as heck huh?*/

	/*Now, let's see how to scan a string. There are infi-
	nite ways of scanning a string. This is why I will only
	show a few of them. First, using a loop, an if state-
	ment and a scanf statement:*/
	char fourthString[10];
	i = 0;
	char dummy = '_';
	printf("\nPlease input your string:\n");
	while(1){
		scanf("%c", &dummy);
		if(dummy == '\n'){
			break;
		}else{
			fourthString[i] = dummy;
			i++;
		}
	}
	fourthString[i] = '\0';
	//Print to make sure it was scanned correctly
	printf("\nThis is your string:\n");
	printf("%s\n", fourthString);
	/*Alright, first thing to notice is our variable dummy.
	It will be used to scan one character at a time. If the
	scanned character is a new line (the enter key), we
	break the loop and stop scanning; otherwise, we keep
	scanning. Second thing to notice is that we are not gi-
	ving a space between " and %. This is because now, we
	are actually interested in scanning the enter key. Be-
	fore, it was being ignored. Third thing to notice is
	the last statement in which we manually assign the null
	character. This is key! If we don't do this, we would
	actually be creating a char array rather than a string.
	Lastly, there is one more thing to point out; What do
	you think will happen if the user inputs 20, 30 or 100
	characters?... OVERFLOW! You will be saving information
	in unwanted places. To prevent it, we can modify our if
	statement as follows:*/

	char fifthString[10];
	i = 0;
	dummy = '_';
	printf("\nPlease input your string:\n");
	while(1){
		scanf("%c", &dummy);
		if(dummy == '\n' || i >= 9){
			break;
		}else{
			fifthString[i] = dummy;
			i++;
		}
	}
	fifthString[i] = '\0';

	printf("\nThis is your string:\n");
	printf("%s\n", fifthString);
	/*This means that our loop will end if the user types
	the enter key or if the user inputs more than 9 chars.
	Notice that I am checking for 9, rather than 10. This
	is because we have to leave one spot for the null cha-
	racter.*/

	/*Another way in which you can scan a string is as fo-
	llows. Using a loop, an if statement and a function
	called getchar.*/
	char sixthString[10];
	i = 0;
	dummy = '_';
	printf("\nPlease input your string:\n");
	while(1){
		dummy = getchar();
		if(dummy == '\n' || i >= 9){
			break;
		}else{
			sixthString[i] = dummy;
			i++;
		}
	}
	sixthString[i] = '\0';

	printf("\nThis is your string:\n");
	printf("%s\n", sixthString);
	/*The only difference is that instead of using scanf,
	we are now using getchar.*/

	/*There is one more way that I want to show you in
	which you can scan a string. It is as follows:*/
	char seventhString[10];
	printf("\nPlease input your string:\n");
	scanf("%s", seventhString);

	printf("\nThis is your string:\n");
	printf("%s\n", seventhString);
	/*Yes! We can scan with %s and scanf. Easy peasy right?
	The only difference is that we do not have to use the &
	sign with the name of the string. And, if you want to 
	ensure the user doesn't input more characters than
	allowed, you can do the following:*/
	char eighthString[10];
	printf("\nPlease input your string:\n");
	scanf("%9s", eighthString);

	printf("\nThis is your string:\n");
	printf("%s\n", eighthString);
	/*Adding a number between % and s, lets the program know
	that it should not read/scan more characters than the
	given number. If the length of the string is n, the
	number between % and s should be n-1.*/

	/*There are two setbacks with this so-beatiful method
	however. With the topics that this class entail, you
	can't set up this length-number dynamically in the
	scanf statement. Also, this method only reads one word
	if you are trying to read a full sentence, this method
	(as it is currently shown), won't be able to do so.
	Thus, depending on the task at hand, I recommend using
	any of the two scanning-loop methods.*/

	/*Now, let me prove that all strings end with a null
	character:*/
	char ninthString[] = "ECE131";
	char charArray[] = {'E','N','G','1','0','1'};
	char charArray2[] = {'M','A','T','H','1','6','2'};
	printf("\nThis is your ninthString:\n");
	printf("%s\n", ninthString);
	printf("\nThis is your charArray:\n");
	printf("%s\n", charArray);
	/*Depending on your program and how it stored the pre-
	vious variables; running the previous code will print
	unexpectedly. On the other hand, if you add a null char
	at the end of your first char array, things will change
	(for good):*/

	char tenthString[] = "ECE131";
	char charArray3[] = {'E','N','G','1','0','1', '\0'};
	char charArray4[] = {'M','A','T','H','1','6','2'};
	printf("\nThis is your ninthString:\n");
	printf("%s\n", tenthString);
	printf("\nThis is your charArray3:\n");
	printf("%s\n", charArray3);
	/*This time it works because the printf statement is
	looking for the null character to end the printing.
	Since charArray3 has a null character at the end,
	printf knows where to stop now. Now, we can actually
	say that charArray3 is a string and no longer a charac-
	ter array. Check this out:*/
	char charArray5[] = {'P','r','o','g','r','\0','a','m','s'};
	printf("\nThis is your charArray5:\n");
	printf("%s\n", charArray5);
	/*Can you infer why this is happening?*/

	/*Okay, we have seen how to initialize, print and scan
	strings. We also saw how strings and loops intermingle.
	The next step is strings and functions. Lets create a
	function that counts the number of characters inside a
	string:*/
	char stringI[] = "Programming is Fun";
	int numOfChars = countChars(stringI);
	printf("The number of characters in your string is: %d\n", numOfChars);
	/*The function adds counter by one until the element in
	the string is equal to the null character.*/

	/*Let's look at another example. Here, we will insert
	one string into another string at the "start":*/
	char stringII[] = "I like dogs";
	char stringIII[] = "really ";
	insertString(stringII, stringIII, 2);

	return 0;
}

