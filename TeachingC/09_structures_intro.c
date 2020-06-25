/**************************************************************
  * File:	09_structures_intro.c
  * Author:	Mario Esparza
  * Date:	06/24/2020
  * Course:	ECE 131 - Programming Fundamentals
  *
  * Program that covers the following:
  * 	1.Structures definition, declaration and initialization
  *	2.Using printf and scanf functions with structures.
  *
**************************************************************/
//TODO Add to Github

#include <stdio.h>

struct patient {
	int age;
	float height;
	float weight;
	int insuranceID;
	//firstname, lastname and address later
};

struct student{
	int age;
	float gpa;
	int unmid;
};

int main(){
	/*In addition to arrays (and their capability of
	storing elements together), we have another tool
	that lets us do the same, but where all elements
	inside this group can have their own datatype.
	When we create an array, all the elements inside
	the array share the same datatype. In structures,
	elements can have different datatypes. You define
	a structure as follows:
		struct typeOfStruct {
			int member1;
			float member2;
			double member3;
			char member4;
		}; <---- DONT FORGET THIS SEMICOLON!
	You use the keyword struct followed by a name which
	resambles the type of structure you are creating.
	You create this name depending the context in which
	you will be using the structure. Inside the bra-
	ckets, you list your "members", you can have as
	many as you need and each can have a different da-
	tatype (or some of them can share the same data-
	type).

	Structures can be local or global. I would say ti-
	pically, you want them to be global, so all func-
	tions can use them, but this is up to you and the
	application or program you are doing. In this class
	we will make them all global.

	Let's take a look at our first example, the struc-
	ture with type-name of "patient" (defined on top
	of main). To declare/create a patient we do the
	following:*/
	struct patient patient1;
	/*We specify that we are delcaring a structure
	with the keyword "struct", we specify which type
	of structure it is with "patient" and we give the
	name of the variable with "patient1". This va-
	riable has 4 diff. members: age, height, weight
	and insuranceID. So far, the values of these mem-
	bers are random. To assign desired values we do
	the following:*/
	patient1.age = 24;
	patient1.height = 1.82; //in meters
	patient1.weight = 170.9; //lbs
	patient1.insuranceID = 101555;
	/*We use the dot to access each one of its members
	and assign the value that we want. Let's declare a
	second structure of this same type:*/
	struct patient patient2;
	patient2.age = 35;
	patient2.height = 1.78; //in meters
	patient2.weight = 185.2; //lbs
	patient2.insuranceID = 101123;
	//And yet, one more patient:
	struct patient patient3 = {64, 1.65, 136.4, 101345};
	/*But now, declaring all values in one line. Keep
	in mind that if you do this you have to give the
	values in the same order in which the members were
	declared inside the structure definition.*/

	/*Displaying this information in the terminal would
	look similar:*/
	printf("This is the information of Patient 1\n");
	printf("Age: %d\n", patient1.age);
	printf("Height: %.2f\n", patient1.height);
	printf("Weight: %.2f\n", patient1.weight);
	printf("Insurance ID: %d\n", patient1.insuranceID);
	/*I match the format character with the datatype of
	each member and we access each member with a dot.
	Now, lets use a different type of structure. Let's
	use the structure of type "student" (defined above
	main) and delcare a variable of this type.*/
	struct student stud1;
	/*Now, stud1 has 3 members (age, gpa and unmid) with
	random values. Let's give it some custom values:*/
	stud1.age = 52;
	stud1.gpa = 3.56;
	stud1.unmid = 101357;
	/*Let's declare a second student and ask the user
	for his/her information:*/
	struct student stud2;
	printf("Please provide the age of student 2: ");
	scanf("%d", &stud2.age);
	printf("Please provide the GPA of student 2: ");
	scanf("%f", &stud2.gpa);
	printf("Please provide the UNM ID of student 2: ");
	scanf("%d", &stud2.unmid);
	/*Once again, notice that we have to match the for-
	mat character with the datatype of each member. To
	make sure the information was stored correctly we
	print out the info:*/
	printf("This is the information of Student 2\n");
	printf("Age: %d\n", stud2.age);
	printf("GPA: %.2f\n", stud2.gpa);
	printf("UNM ID: %d\n", stud2.unmid);

	return 0;
}
