/****************************************************************
  * File:    recursFuncs.C
  * Author:  Mario Esparza
  * Date:    04/29/2020
  * Course:  ECE 131 - Programming Fundamentals
  * 
  * Program that demonstrates the following: TODO
  *     
  *
  *    
  * 
****************************************************************/ 
#include <stdio.h>
void iterate(int start, int end){
	if(start < end){
		printf("start = %d\n", start);
		iterate(start+1, end);
		//We could also have done:
		//start++;
		//iterate(start, end);
	}else{
		return;
	}
}

int main(){
	//We've seen how to iterate through an int with a loop:
	int stop = 10;
	int i;
	for(i=0;i<stop;i++){
		printf("i = %d\n", i);
	}

	//What if I tell you we can do the same with functions?
	printf("\nLet's try it again, but now with a function\n");
	iterate(0, stop);

	return 0;
}
