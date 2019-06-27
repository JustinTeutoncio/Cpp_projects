#include<iostream>
using namespace std;

int mult = 0;
double exp(double x, double n){ //x=base, n=exp, y=#of mult
	mult++;
	if (n == 1){
		cout << "After " << mult - 1 << " multiplications..." << endl;
		return x;
	}
	else
		return (x*exp(x, n - 1));
}

void program(){
	double base, exponent, ans;//a=base, b=exp, c=answer
	cout << "Enter the base number, and then the exponent." << endl;
	cin >> base >> exponent;
	if (exponent == 0)
		cout << "The result is 1." << endl;
	else if (exponent == 1)
		cout << "The result is " << exponent << "." << endl;
	else{
		ans = exp(base, exponent); cout << "The result is " << ans << endl;
	}
	cout << endl << endl;
	mult = 0;
	program();
}

int main(){ program(); return 0; }