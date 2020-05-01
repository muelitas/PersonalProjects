/****************************************************************
  * File:    recursFuncs.C
  * Author:  Mario Esparza
  * Date:    04/29/2020
  * Course:  ECE 131 - Programming Fundamentals
  * 
  * Recursive functions are explained with the help of triangular
  * numbers (TNs). We start by manually calculating each TN. We
  * continue with the help of a loop. We then show a function that
  * prints each TN recursively. Then, we show a function that
  * recursively, returns the nth TN. Lastly, we show the "baddest"
  * method of recursion in which we repeatedly call the function
  * in the return statement.
  * 
****************************************************************/ 
#include <stdio.h>
//Print all TNs until goal is reached
void triangNum1(int i, int tn, int goal){
	if(i <= goal){
		tn = tn + i;
		printf("Triang. Num. %d: %d\n", i, tn);
		triangNum1(i+1, tn, goal);
	}else{
		return;
	}
}
//Return only the nth TN
int triangNum2(int i, int tn, int goal){
	if(i <= goal){
		tn = tn + i;
		triangNum2(i+1, tn, goal);
	}else{
		return tn;
	}
}
//Return the nth TN, but more efficiently
int triangNum3(int n){
	if(n == 1){
		return 1;
	}else{
		return n + triangNum3(n-1);
	}
}

int main(){
	printf("First, let's do it manually aka. painfully.\n");
	int i = 1;
	int tn = i;
	printf("Triang. Num. 1: %d\n", tn);
	i++;
	tn = tn + i;
	printf("Triang. Num. 2: %d\n", tn);
	i++;
	tn = tn + i;
	printf("Triang. Num. 3: %d\n", tn);
	i++;
	tn = tn + i;
	printf("Triang. Num. 4: %d\n", tn);
	i++;
	tn = tn + i;
	printf("Triang. Num. 5: %d\n", tn);

	printf("\nNow, let's try it with a loop.\n");
	tn = 0;
	int n = 5; //TN which we want to reach
	for(i=1;i<=n;i++){
		tn = tn + i;
		printf("Triang. Num. %d: %d\n", i, tn);
	}

	printf("\nNow, let's give recursive func. a try\n");
	i = 1; //reset i back to 1
	tn = 0; //reset tn back to 0
	triangNum1(i,tn,n);

	//What if we were only interested in getting the nth TN?
	int result = triangNum2(i,tn,n);
	printf("\nTriang. Num. %d: %d\n", n, result);

	//Yet a more efficient way would be:
	result = triangNum3(n);
	printf("\nTriang. Num. %d: %d\n", n, result);

	return 0;
}
