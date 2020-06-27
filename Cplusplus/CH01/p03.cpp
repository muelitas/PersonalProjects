/****************************************************************
  * File:    p04.cpp
  * Author:  Mario Esparza
  * Date:    05/01/2020
  * Book:    A Tour of C++
  * 
  * Functions can't share the same name in C. Even
  * if they have different arguments. In C++
  * however, they can. It might not be a good idea
  * to do so though.
  * 
****************************************************************/ 
#include <iostream>
using namespace std;

void print(int x){
	cout << "Using int x function\n";
	cout << "x = " << x << ".\n";
	return;
}
void print(double x){
	cout << "Using double x function\n";
	cout << "x = " << x << ".\n";
	return;
}
void print(char x){
	cout << "Using char x function\n";
	cout << "x = " << x << ".\n";
	return;
}
int main(){
	print(42);
	print(53.5);
	print('c');
	return 0;
}
