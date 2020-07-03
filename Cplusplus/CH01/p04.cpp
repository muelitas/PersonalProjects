/****************************************************************
  * File:    p04.cpp
  * Author:  Mario Esparza
  * Date:    05/01/2020
  * Book:    A Tour of C++
  * 
  * In this program I play with the datatypes of C++, especially
  * complex, vector and double {}. But I am also lookind at 
  * small aspects of other datatypes.
  * 
****************************************************************/ 
#include <iostream>
#include <complex>
#include <vector>
using namespace std;

int main(){
	double d1 = 2.3;
	double d2 {4.8};
	double d3 = {9.8}; //you can add the =, but not needed
	complex<double> z = 1;
	cout<<"Real part="<<real(z)<<"\n";
	cout<<"Imag part="<<imag(z)<<"\n";

	//Initialize complex variable with {}
	complex<double> z2 {d1,d3};
	cout<<"Real part="<<real(z2)<<"\n";
	cout<<"Imag part="<<imag(z2)<<"\n";

	//This doesn't work
	//z {d1,d2};
	
	//But this does
	z = {d1,d2};
	cout<<"Real part="<<real(z)<<"\n";
	cout<<"Imag part="<<imag(z)<<"\n";

	//Initialize complex variable with ()
	complex<double> z3(d1,10.59);
	cout<<"Real part="<<real(z3)<<"\n";
	cout<<"Imag part="<<imag(z3)<<"\n";

	//Initialize vector with '= {}'
	vector<int> ints = {1, 2, 3, 4};
	cout<<"First elmt in ints="<<ints[0]<<"\n";
	cout<<"First elmt in ints="<<ints.at(0)<<"\n";

	//Initialize vector with '{}'
	vector<float> floats {0.5, 1.5, 2.5, 3.5};
	cout<<"First elmt in floats="<<floats.front()<<"\n";
	cout<<"Last elmt in floats="<<floats.back()<<"\n";

	int i2 {8};	//this is correct
	//int i1 {7.8};	//this won't give me i1 = 7
	
	//these variables will deduce the datatype
	auto b = true;
	auto c = 'x';
	auto i {7};

	return 0;
}
