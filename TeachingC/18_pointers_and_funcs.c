/**************************************************************
  * File:	18_pointers_and_funcs.c
  * Author:	Mario Esparza
  * Date:	07/09/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * Program that covers the following:
  * 1. How to send and manipulate pointers in functions.
  * 2. Function that prints a singly linked list.
  * 3. How to insert and remove a node from a linked list.
  *
**************************************************************/
#include <stdio.h>

struct node {
	int value;
	struct node *next;
};

int addIntegers(int I1, int *I2){
	int result = I1 + *I2;
	return result;
}

float subFloats(float *F1, float *F2){
	float result = *F1 - *F2;
	return result;
}

void changeValue(double *D1){
	double newValue;
	printf("Which new value would you look to assign? ");
	scanf("%lf", &newValue);
	*D1 = newValue;
	return;
}

void printLinkedList(struct node *thisNode){
		printf("These are the values in your linked list:\n");
		while(thisNode != NULL){
			printf("%d\t", thisNode->value);
			thisNode = thisNode->next;
		}
		printf("\n");
		return;
}

void insertNode(struct node *before, struct node *after, struct node *middle){
	before->next = middle;
	middle->next = after;
	return;
}

void insertNodeV2(struct node *before, struct node *middle){
	middle->next = before->next;
	before->next = middle;
	return;
}

void removeNode(struct node *before){
	before->next = before->next->next;
	return;
}

int main(){
	/*Like everything else, pointers can be used in functions.
	You can return and send pointers. In this course however,
	we will only see how to send them. Let's start by declaring
	some variables:*/
	int i1 = 9, i2 = 12, myInt, *pti;
	
	printf("PLAYING WITH INTEGERS FIRST\n");
	/*Then, let's use a function that will add two integers and
	return the addition to main. The arguments that we are
	going to send are two, an integer and a pointer (an ad-
	dress). Example 1:*/
	myInt = addIntegers(i1, &i2);
	printf("using parameters i1 and &i2, we get: \t%d\n", myInt);
	/*In this example we send our integer variable i1 and we
	send the address of i2. In our function we are receiving an
	integer as the first argument and a pointer as the second.
	This is why when you send &i2, everything works out; it is
	like if you were saying: int *I2 = &i2; Which is how poin-
	ters are initialized, as we have seen.*/
	
	/*Now, when addIntegers receives this address, it goes a-
	head and dereferences the value inside this address. This
	is how we are able to add both values inside the function*/

	/*Another way in which we can call the function is as fol-
	lows:*/
	pti = &i1;
	myInt = addIntegers(5, pti);
	printf("using parameters 5 and pti, we get: \t%d\n", myInt);
	/*Using an integer as the first argument and a pointer (an
	address) as the second one.*/

	/*Lastly, we could have also done:*/
	pti = &i2;
	myInt = addIntegers(*pti, pti);
	printf("using parameters *pti and pti, we get: \t%d\n", myInt);
	/*Sending an integer as the first argument (a pointer being
	dereferenced, and a pointer as the second argument.*/
	
	//We can also create a function that expects two pointers:
	float f1 = 3.0, f2 = 7.0, myFloat, *ptf;
	printf("\nPLAYING WITH FLOATS\n");
	/*Notice that in the following examples, both arguments are
	addresses or pointers (which is the same):*/

	myFloat = subFloats(&f1, &f2);
	printf("using parameters &f1 and &f2, we get: \t%.2f\n", myFloat);

	ptf = &f1;
	myFloat = subFloats(ptf, &f1);
	printf("using parameters ptf and &f1, we get: \t%.2f\n", myFloat);

	ptf = &f2;
	myFloat = subFloats(&f1, ptf);
	printf("using parameters &f1 and ptf, we get: \t%.2f\n", myFloat);
	
	/*You might be saying, what is the point of all this if we
	can do the exact same thing with plain integers and floats.
	Well, one important thing about pointers is that when you
	send them as functions' arguments, they are no being pass
	by value, but by reference (just like arrays). This means
	that if you send a pointer to a function, if you dereferen-
	ce it and change the value, you will be changing the actual
	value of the variable this pointer is pointing to. For 
	example:*/
	double d1 = 5.0, d2 = 10.0, myDouble, *ptd;
	ptd = &d1;
	printf("Value of d1 before we call the function: %.2lf\n", d1);
	changeValue(ptd);
	printf("Value of d1 after we call the function: %.2lf\n", d1);
	/*Notice that the function is void, thus returning nothing.
	So there is no way this variable was updated as we had seen
	in the past. What happened is that we sent the address of
	d1, we accessed that address and modified whatever was in-
	side. We can do the same thing with d2 using &d2 as the
	parameter:*/
	printf("Value of d2 before we call the function: %.2lf\n", d2);
	changeValue(&d2);
	printf("Value of d2 after we call the function: %.2lf\n", d2);

	/*If we go back to linked lists and relate it to functions,
	/we could create a function that prints the information in-
	side the linked list. It would look something like this:*/
	struct node n1, n2, n3, n4, n5;
	
	n1.value = 5;
	n2.value = 15;
	n3.value = 25;
	n4.value = 35;
	n5.value = 45;
	
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = NULL;
	
	struct node *head = &n1;
	printLinkedList(head);
	//Dope huh?
	
	/*With functions, we can make other operations in linked
	lists more effective. For example, if we want to add a new
	node between n2 and n3, we can create a function that does
	this for us:*/
	struct node n6;
	n6.value = 17;
	insertNode(&n2, &n3, &n6);
	/*Now, if we print the list, we will see the value of the
	new node:*/
	printLinkedList(head);
	//Niz! (Nice)
	
	/*Would you believe me if I tell you we can make this func-
	tion more effective?. Let's insert one more node after
	n4:*/
	struct node n7;
	n7.value = 41;
	insertNodeV2(&n4, &n7);
	printLinkedList(head);
	/*With middle->next = before->next; we remove the need of
	a third argument (&n3). We have to flip the order of the
	statements inside th functio however. If we don't do it, we
	would lose track of where middle has to point to.*/
	
	/*Similarly, we can create a function that removes a node
	from the list. Let's remove n2:*/
	removeNode(&n1);
	printLinkedList(head);
	/*Using the node previous to the one we want to remove, we
	can use ->next->next to specify where n1 should point to.
	This allows us to do removeNode more efficient, since we are
	only using one argument.*/
	
	return 0;	
}