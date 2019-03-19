#include <iostream>
#include<time.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

struct Date{
	int day;
	int month;
	Date(){
		month = rand() % 12 + 1;
		if (month == 2)//feb has 29 days
			day = rand() % 29 + 1;
		else if (month == 4 || month == 6 || month == 9 || month == 11)//apr,jun,sept,nov have 30
			day = rand() % 30 + 1;
		else//rest have 31
			day = rand() % 31 + 1;
	}
	bool operator==(Date& rhs)const{
		if (this->month == rhs.month && this->day== rhs.day)
			return true;
		return false;
	}
	friend ostream& operator<<(ostream& os, const Date& dt){
		os << dt.month << '/' << dt.day;
		return os;
	}

};
int cnt = 0;
struct Person{
	int id;
	Date birthday;
	Person(){
		id = cnt; cnt++;
	}
	friend ostream& operator<<(ostream& os, const Person& dt){
		os << dt.id << ": born " << dt.birthday;
		return os;
	}
};

int size = 100;

int check_equals(Person b[]){
	int num_equals = 0;//how many pairs
	for (int i = 0; i < size; i++){
		if (b[i].id == 0){//first index checks the rest until limit
			for (int j = 1; j < size; j++)
				if (b[0].birthday == b[j].birthday){
					num_equals++;
					cout << b[0].id << " shares birthday with " << b[j].id << endl;
				}
		}
		else if (b[i].id == size-1){//last goes down list until start
			for (int j = size-2; j > 0; j--)
				if (b[size - 1].birthday == b[j].birthday){
					num_equals++;
					cout << b[size-1].id << " shares birthday with " << b[j].id << endl;
				}
		}
		else{
			for (int j = 0; j < b[i].id; j++)//start from index 0 until id index. e.g. if 10 people, 5 would do 0-4 first.
				if (b[i].birthday == b[j].birthday){
					num_equals++;
					cout << b[i].id << " shares birthday with " << b[j].id << endl;
				}
			for (int j = b[i].id+1; j<size; j++)//now the rest. starts at id+1; using above example, 5 will get compared to 6-9
				if (b[i].birthday == b[j].birthday){
					num_equals++;
					cout << b[i].id << " shares birthday with " << b[j].id << endl;
				}

		}
	}
	cout << endl<<num_equals/2 << " pairs of people share a birthday!" << endl;
	if (num_equals / 2 == 0){
		cout << "Wow! Statistically speaking, this is extremely unlikely!\n";
	}
	return num_equals / 2;
}


int main(){
	system("Color F1");
	srand(time_t(NULL));
	cout << "Hello! This program will simulate the Birthday Paradox." << endl;
	cout << "This paradox claims if you put 100 people in a room together, at least one pair of people will share the same birthday\n";
	char ans;
	int total_pairs = 0;
	int num_tries = 1;
	int pairs;
	do{
		cnt = 0;
		size = 100;
		Person a[100];
		for (int i = 0; i < size; i++){
			cout << a[i] << "\t";
		}
		cout << endl;
		pairs=check_equals(a);
		total_pairs += pairs;
		if (num_tries > 1){
			float avg = float(total_pairs) / float(num_tries);
			cout << "So far, on average there are " << avg << " pairs, for "<<num_tries<<" generations\n";
		}
		
		cout << "\nrun again? y / n? \n";
		cin >> ans;
		num_tries++;
	} while (ans != 'n');
	
	return 0;
}
