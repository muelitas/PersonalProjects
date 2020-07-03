/****************************************************************
  * File:    notes.cpp
  * Author:  Mario Esparza
  * Date:    05/01/2020
  * Book:    A Tour of C++
  * 
  * Any clarifications that I need will be tested and registered
  * here. Notes that things worth highlighting, will also be 
  * registered here.
  * 
****************************************************************/ 
#include <iostream>
#include <string>
using namespace std;

int main(){
	//You can declare and initialize a variable inside an if
	//statement to limit its scope (to live only inside the
	//if statement brackets). Dope!

	//In order to use string as datatype I need <string> and
	//namespace std.
	string str;
	cout << "Please provide a string: ";
	cin >> str;
	cout << "str = " << str << "\n";

	//nullptr is meant as a replacement to nullptr.
	 
	//There is a new topic called a reference. Quite interes-
	//ting, since it lets you play with the variable, rather
	//than creating a copy. Look at the "sort" example in
	//1.7.

	//Testing the negative unary operator
	int x = 5;
	cout << "Using negative unary with x ="<<-x<<"\n";

	/* Bools are already defined in C++, you don't need
	 * an extra library like you do in C.*/
	return 0;
}
