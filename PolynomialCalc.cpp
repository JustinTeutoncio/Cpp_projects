//JUSTIN TEUTONICO LAB 3 CSC326
//Q1: Reverse an integer with iterations
//Q2: Reverse int with recursion
//Q3: Polynomial calculator

#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

void reverse_iter(int x){//question 1
	int i = 10;
	do{
		cout << (x%i) / (i / 10);
		i *= 10;
	} while ((x * 10) / i != 0);
}

void reverse_recur(int x){//question 2
	int a;
	if (x){
		a = x % 10; cout << a;
		return reverse_recur(x / 10);
	}
}

void polyn(){//question 3
	cout << "Enter the highest degree in the polynomial" << endl;//3a
	int high; cin >> high; 
	int h = high + 1;//variable for counter; if highest degree is 3, requires 4 inputs, etc
	int*a = new int[h];//stores terms
	int*b = new int[h];//stores exponents
	cout << "Enter each term from the highest degree to the lowest degree (" <<h<<"inputs total)"<< endl;
	for (int i = 0; i < h; i++){
		cin >> a[i];//entering the values
		if (a[i] != 0)
			b[i] = high;//b array handles exponents; starts from high, lowers each loop
		else
			b[i] = 0;
		high--;//exponent decreases by 1 per loop; the next term has to be one lower
	}
	cout << endl << "You entered: " << endl;
	for (int i = 0; i < h; i++){//displays polynomial
		if (a[i] > 0){
			if (b[i] >1 && a[i] != 1)
				cout << a[i] << "x^" << b[i];//wont display 1x^1
			else if (a[i] == 1 && b[i] > 1)
				cout << "x^" << b[i];//x^pow
			else if (b[i] == 1 && a[i] != 1)
				cout << a[i] << "x";//Ax, where a > 1
			else if (b[i] == 1 && a[i] == 1)
				cout << "x";//if a and b are 1, its just x
			else
				cout << a[i];//just the number if exponent is 0
			if (a[i + 1] > 0)
				cout << " + ";
		}
		else if (a[i + 1] > 0)
			cout << " + ";
	}
	cout << endl << "Enter the value for x" << endl; int x; cin >> x;//enter x
	int total = 0; int q;
	cout << "The value is: " << endl;
	for (int i = 0; i <h; i++){
		if (a[i] != 0 && b[i] > 1){//will carry out ((number * x)^exp); checks if a[i] isn't blank and b[i] is at least 2
			q = a[i] * x;//q holds value for number*x
			total += pow(q, b[i]);//total += value of q raised to pow of b[i]
		}
		else if (b[i] == 1)//number * x
			total += a[i] * x;
		else if (b[i] == 0)//number alone
			total += a[i];
	}
	cout << total << endl;//3b
	
		delete a; delete b;
		system("pause");

	}


void program(){
	cout << endl;
	cout << "Input [1] for Prob 1 & 2 (Reverse an int)" << endl; //user enters an integer to be reversed
	cout << "Input [2] for Prob 3 (Polynomial)" << endl;
	cout << "[3] to quit" << endl;
	int q; cout << "Enter the number corresponding to the choice: \n"; cin >> q;

	if (q == 1){//user entered 1, reverse #
		cout << "Enter the number to be reversed: " << endl; int a; cin >> a;
		cout << "The number reversed (iterative) is ";
		reverse_iter(a); cout << endl; system("pause"); //shows iterative
		cout << endl << "Recursive: ";
		reverse_recur(a); cout << endl; system("pause");//shows recursive
		program();
	}
	else if (q == 2){//goes to polynomial
		polyn(); program();
	}
	else if (q == 3)//kills program
		exit(1);
	else{//error handling
		cout << "Not an option." << endl; system("pause"); program();
	}
}
int main(){ program(); return 0; }