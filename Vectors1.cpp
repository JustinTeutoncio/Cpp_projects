#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
	cout << "Queue is as follows:";
	if (v.empty())
		cout << "Empty!";
	else
		for (auto i = v.begin(); i != v.end(); i++)
			cout << *i << " ";
	cout << endl;	}

int main(){
	vector<int> a;
	for (int i = 1; i <= 5; i++)
		a.push_back(i);//insert 1,2,3,4,5 to queue
	char ans = ' ';
	while (ans != '0'){
		cout << "Circular queue with vector simulator. Size is " << a.size() << endl;
		print(a);
		cout<<"You may : \n[1]Advance queue\n[2]Add to queue\n[3]Delete from queue\n[4]Empty queue\n[5]Resize queue\n[0]QUIT\n";
		cin >> ans;
		if (ans == '1')
			for (int i = 0; i< a.size() - 1; i++)
				swap(a[i], a[i + 1]);
		else if (ans == '2'){//push back a new int
			cout << "Input a number to add\n"; int n; cin >> n;
			a.push_back(n);
		}
		else if (ans == '3' && a.size() > 0){//delete element, if possible
			cout << "Input the index of the item in the queue to delete\n"; int n; cin >> n;
			if (n > a.size() - 1)
				cout << "Error, not possible\n";
			else
				a.erase(a.begin() + n);
		}
		else if (ans == '4')//wipe queue
			a.clear();
		else if (ans == '5'){
			cout << "Input the new size\n"; int n; cin >> n;
			if (n < 0)
				cout << "Error, not possible\n";
			else
				a.resize(n);
		}
		system("pause");system("cls");
	}
	return 0;	}