#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void get_values(float *A, float *B, float *C){
	printf("Please provide the values of\n");
	printf("a: ");
	scanf("%f", A);
	printf("b: ");
	scanf("%f", B);
	printf("c: ");
	scanf("%f", C);
	return;
}

void print_values(float a,float b, float c){
	printf("\nThe values are:\n");
	printf("a: %.2f\nb: %.2f\nc: %.2f\n", a, b, c);
	return;
}

int main(){
	float a, b, c;
	bool Bool;
	get_values(&a, &b, &c);
	print_values(a, b, c);

	//checking discriminant
	float discr = b*b - 4*a*c;
	Bool = (discr < 0) ? true : false;

	if(!Bool){
		discr = sqrtf(discr);
		float root1, root2;
		root1 = (-b+discr)/(2*a);
		root2 = (-b-discr)/(2*a);
		printf("You roots are:\n");
		printf("x1 = %.2f\n", -root1);
		printf("x2 = %.2f\n", -root2);
	}else{
		printf("Your discriminant is negative => imaginary roots.\n");
	}
	return 0;
}
