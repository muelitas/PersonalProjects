#include <iostream>
using namespace std;

double square(double x){
	return x*x;
}

void print_square(double x){
	cout << "The square of " << x << " is " << square(x)<<"\n";
	return;
}

int main(void){
	print_square(2.0);
	print_square(3.3);
	print_square(1.234);
	return 0;
}
