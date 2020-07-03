/****************************************************************
  * File:    p04.cpp
  * Author:  Mario Esparza
  * Date:    05/01/2020
  * Book:    A Tour of C++
  * 
  * In this program, I play with the 'range-for-statement' of 
  * C++.
  *
****************************************************************/ 
#include <iostream>
using namespace std;

int main(){
	int a[] = {1,2,3,4,5,6,7,8};
	for(int x:a){	//for each x in v
	//It seems that I must have a type inside () of for
		cout << x << "\n";
	}
	//Notice that x is only declared inside the for loop
	//cout << x << "\n";

	//The following loop adds 1 to each value in a
	for(int& x:a){ //"reference to"
		x++;
	}
	for(int x:a){
		cout << x << "\n";
	}
	return 0;
}

