/****************************************************************
  * File:    notes.cpp
  * Author:  Mario Esparza
  * Date:    06/28/2020
  * Book:    A Tour of C++
  * 
  * In this chapter, the author also dicusses variants and unions
  * Both useful to those situations in which you have two varia-
  * bles and you will only use one. Enumerations (enum) is also
  * mentioned in this chapter. To further undesrtand their usage
  * I used this link:
  * https://en.cppreference.com/w/cpp/language/enum
  * 
****************************************************************/ 
#include <iostream>
#include <string>
using namespace std;

int main(){
	//Few examples to better understand usage of enumerations.
	enum dummy{a,b,c=5,d, e,f,g=-21, h};
	cout << dummy::c << "\n";
	dummy myDummy = g;
	cout << myDummy << "\n";

	return 0;
}
