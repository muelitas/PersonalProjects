/**************************************************************
  * File:	17_singly_linked_lists.c
  * Author:	Mario Esparza
  * Date:	07/06/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * Program that covers the following:
  * 1. The concept of nodes (structures) and links (pointers).
  * 2. How to iterate through a linked list.
  *
**************************************************************/
/*If time permits, explain pros and cons of linked lists and
arrays: 1.Accessing is better in arrays, since you dont have to acess
each element to get to the desired one. 2.Inserting and dele-
ting takes more time for arrays than it does for linked lists.
3.Arrays are of fixed size (comiler time); Linked Lists are of
dynamic size (run time). 4.Arrays require less memory, since
they don't need an extra space for each pointer.*/

#include <stdio.h>

struct node {
	int value;
	struct node *next;
};

int main(void){
	/*Arrays are one way of organizing data in memory: Having
	multiple variables (of the same type) together with an in-
	dex to refer them with. Another way in which we can organi-
	ze data in memory is using Linked Lists. Where our varia-
	bles are not stored together (contiguous), but they are
	connected by links (pointers). I will refer to this varia-
	bles as nodes.*/

	/*If we look at the structure that I defined above, we can
	see that it has two members: an integer and a pointer to a
	structure. We have seen how to deal with an integer inside
	a structure, and we have seen how to deal with a pointer to
	a structure. The difference here is that the pointer to the
	structure is inside a structure. We are going to use this
	pointer as the link*/
	
	/*Let's look at an example of five nodes. First, we declare
	the nodes:*/
	struct node n1, n2, n3, n4, n5;
	/*Next, let's give them some values by initializing their
	member called "value":*/
	n1.value = 5;
	n2.value = 15;
	n3.value = 25;
	n4.value = 35;
	n5.value = 45;
	
	/*Next, let's link them together, starting at n1 and ending
	at n5:*/
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = NULL;
	
	/*We access the "next" member of each node with a dot.
	Then, since "next" is a pointer to a structure of type no-
	de,	we have to make it point to a structure of the same ty-
	pe. This is why the initializations above works just fine.
	Notice that the link of the last node (n5) is being initia-
	lized to "NULL". This "NULL" is the null pointer. In this
	context, you can think of it as the null character of
	strings: the one that indicates the end of the linked list.
	This means we can use it as the stopping condition when
	iterating through the values inside a list. I will show you
	how to do so in a minute.*/
	
	/*First, let's create the "head" pointer. This variable
	will establish where in the list we are going to start
	grabbing information from.*/
	struct node *head;
	//If we want to start at the beginning (n1), we would do:
	head = &n1;
	//Let's ensure head is actually pointing to n1:
	printf("The address of n1 is %p\n", &n1);
	printf("The value of head is: %p\n", head);
	//Checked, head is in fact pointing to n1.
	
	/*This means we can dereference head to get the value insi-
	de n1:*/
	printf("\nValue in n1 is: %d\n", head->value);
	/*We can also dereference "next" and see where n1 is poin-
	ting to:*/
	printf("next of n1 points to (using head): %p\n", head->next);
	printf("next of n1 points to (using n1): %p\n", n1.next);
	/*Since n1 should be pointing to n2, let's print the ad-
	dress of n2 and check if is true:*/
	printf("The address of n2 is %p\n", &n2);
	/*n1 is in fact pointing to n2 and we can use our pointer
	head to retrieve this information.*/
	
	/*This also means we can use our pointer head to move from
	node to node:*/
	head = head->next;
	/*The previous statement is the same as saying: head = &n2;
	Why? Because n1.next = &n2 and we have previously stated
	that head->next = n1.next; thus, head = head->next = &n2;.
	Now, if we print the value of head, we will see that its
	value is the address of n2:*/
	printf("The value of head is: %p\n", head);
	
	/*If we repeat it once again, we will see how head would
	equal the address of n3:*/
	head = head->next;
	printf("The value of head is: %p\n", head);
	printf("The address of n3 is %p\n", &n3);
	
	/*We can apply this instruction over and over to travel
	through each node. When to stop? Well, this is where the
	NULL pointer kicks in:*/
	head = &n1;
	printf("Printing values in linked list. Starting at n1:\n");
	while(head != NULL){
		printf("%d\t", head->value);
		head = head->next;
	}
	printf("\n");
	
	/*Or if we wanted to start in the middle, at n3 per se, we
	would do:*/
	head = &n3;
	printf("Printing values in linked list. Starting at n3:\n");
	while(head != NULL){
		printf("%d\t", head->value);
		head = head->next;
	}
	printf("\n");
	
	/*You might be thinking this is pretty neat, but what is
	actually going on? As mentioned earlier, we are using NULL
	as the stopping condition of the loop. Whenever the pointer
	points to nothing (pointer equals the NULL pointer), the
	loop will stop. Then, in each iteration we print the member
	"value" of the structure to which head is pointing to. We
	use the arrow operator because head is a pointer to a
	structure and not a common structure. The second line in
	the loop indicates a "jump" of node. We set head equal to
	the node which "next" is pointing to. If head is pointing
	to n1, then with head = head->next; we are telling head to
	point to n2.*/
	
	/*With the hope of better explaining what is happening in
	memory, we print some addresses:*/
	printf("The address of n1 is %p\n", &n1);
	printf("The value of next in n1 is: %p\n", n1.next);
	printf("The address of n2 is %p\n", &n2);
	printf("The value of next in n2 is: %p\n", n2.next);
	printf("The address of n3 is %p\n", &n3);
	printf("The value of next in n3 is: %p\n", n3.next);
	printf("The address of n4 is %p\n", &n4);
	printf("The value of next in n4 is: %p\n", n4.next);
	printf("The address of n5 is %p\n", &n5);
	printf("The value of next in n5 is: %p\n", n5.next);
	printf("The value of head is: %p\n", head);
	
	/*Something else that is neat about nodes in this context,
	is that we can have our pointer head, skip nodes if we want
	to. For example, in the following lines of code I make head
	point to n1, skip n2 and then have it point to n3:*/
	head = &n1;
	printf("The address of n1 is %p\n", &n1);
	printf("The value of head is: %p\n", head);
	//Now, let's skip n2
	head = head->next->next;
	printf("The address of n3 is %p\n", &n3);
	printf("The value of head is: %p\n", head);
	//Cool huh?

	return 0;
}

