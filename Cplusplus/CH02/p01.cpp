/****************************************************************
  * File:    p01.cpp
  * Author:  Mario Esparza
  * Date:    06/27/2020
  * Book:    A Tour of C++
  * 
  * In this program I learn how to use structures in C++. I also
  * got to practice the usage of references and cin (scanf in C).
  *
  * Notes:
  * - We use the dot to access structure members from normal va-
  * riables and references. We use the arrow operator (->) when
  * dealing with pointers to structures.
  * - Structures can have functions as members. Idk this is true
  * for C. I'll have to check.
****************************************************************/ 
#include <iostream>
using namespace std;

struct Vector{
	int sz;
	double *elem;
};

void read_elemts(Vector& v){
	cout <<"Please enter the values of your vector:"<<endl;
	int i;
	for(i=0; i<v.sz; i++){
		cin>>v.elem[i];
	}
	return;
}

void print_elemts(Vector& v){
	cout<<endl<<"These are the elements in your vector:"<<endl;
	int i;
	for(i=0; i<v.sz; i++){
		cout<<v.elem[i]<<" ";
	}
	cout<<endl;
	return;
}

void vector_clean(Vector& v){
	//Cleaning the heap (free store aka. dynamic memory)
	delete[] v.elem;
	return;
}

void vector_init(Vector& v){
	int size;
	cout<<"Please input the size of your vector: ";
	//No format characters needed as in C!
	cin >> size;
	v.elem = new double[size]; //allocate s doubles in the heap
	v.sz = size;
	//I don't need to return the structure (Vector) since I am
	//using a reference to such.
	return;
}

int main(){
	//Interesting, I don't need the prefix "struct"
	Vector v;
	vector_init(v);
	read_elemts(v);
	print_elemts(v);
	vector_clean(v);
	return 0;
}
