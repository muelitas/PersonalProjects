/****************************************************************
  * File:    p02.cpp
  * Author:  Mario Esparza
  * Date:    06/28/2020
  * Book:    A Tour of C++
  * 
  * I first create my own Class. A simple example to understand
  * the basics of a Class. I look at public and private variables
  * and at a constructor (initializing all private variables). I
  * then look at the example given by the book. Since it uses
  * "new" I added a destructor to the class. I added a check in-
  * side the subscript function called "operator[]". I added two
  * more functions, read_elemts and print_elemts.
  *
  * Question unanswered in this chapter: how would I go about
  * having a class with two arrays? If I say v[1] = 5.5, how will
  * it know which array I am editing?
  *
****************************************************************/ 
#include <iostream>
using namespace std;

class Student{
	public:
		/* This is the constructor (same name as class).
		 * This syntax initializes all three private mem-
		 * bers of the class.*/
		Student(int Age, float Gpa, int ID)
			:age{Age},gpa{Gpa},unmid{ID} {}
		double ACT; //public variable
		int getAge(){
			return age;
		}
		float getGPA(){
			return gpa;
		}
		int getUNMID(){
			return unmid;
		}
	private:
		//Private variables
		int age;
		float gpa;
		int unmid;
}; //<--- don't forget!!!

//Class given by the book with some modifications
class Vector{
	public:
		Vector(int s)
			:elem{new double[s]}, sz{s} {}
		/* Destructor; called automatically when object goes
		 * out of scope. Same name as the class preceded with
		 * a tilde (~). They don't have any arguments and
		 * they don't return anything:*/
		~Vector(){
			delete[] elem;
		}
		/* This, allows access to the elements. It returns
		 * a reference to the appropiate element:*/
		double& operator[](int i){
			if(i<0 || i>=sz){
				cout<<"Sorry, but index has to be between";
				cout<<"0 and "<<sz-1<<"\n";
				cout<<"Last element in array will be modified\n";
				i=sz-1;
			}else{
				cout << "Initializing elemt with index: "<<i<<"\n";
			}
			return elem[i];
		}
		int size(){
			return sz;
		}
		void read_elemts(){
			cout <<"Enter the vector values:\n";
			int i;
			for(i=0; i<sz; i++){
				cin>>elem[i];
			}
			return;
		}
		void print_elemts(){
			cout<<"\nThese are the elements in your vector:\n";
			int i;
			for(i=0; i<sz; i++){
				cout<<elem[i]<<" ";
			}
			cout<<"\n";
			return;
		}

	private:
		double* elem;
		int sz;
};


int main(){
	Student stud1(24,3.8,101652);
	int age = stud1.getAge();
	float gpa = stud1.getGPA();
	int unmid = stud1.getUNMID();
	stud1.ACT = 28.3;
	cout << "The information of Student 1 is: \n";
	cout << "\tAge: " << age << "\n";
	cout << "\tGPA: " << gpa << "\n";
	cout << "\tUNM ID: " << unmid << "\n";
	cout << "\tACT: " << stud1.ACT << "\n";

	Vector v(3);
	//Want to see if values in array are random:
	v.print_elemts();
	//Manually assign values (understanding "operator[]")
	v[0] = 5.5;
	v[1] = 10.1;
	v[2] = 20.2;
	//Ensure values were assigned correctly:
	v.print_elemts();
	//Ensure error checking is working successfully:
	v[3] = 4.5;
	v.print_elemts();
	//Change values, scan them from user:
	v.read_elemts();
	v.print_elemts();
	return 0;
}
