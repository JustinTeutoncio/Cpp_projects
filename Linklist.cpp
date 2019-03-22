#include <iostream>

using namespace std;
class linkedlist{
public:
	linkedlist() :head(0){}
	~linkedlist();
	bool sortedisempty(){ return (head == 0); }; //true if the list is empty             
	int sortedgetlength();//length of the list                                       
	bool sortedfind(int k, int&x); //value of Kth element                              
	int sortedsearch(int key); //position of the element which is the same as the key  
	void sortedinsert(int x);//insert x to the right position in the sorted link               
	void sorteddelete(int k, int &x, bool& success);//delete the Kth element                   
	void print();
private:
	struct node{
		int data;
		node *next;
	};
	node*head;
};
linkedlist linklist;//global variable
int linkedlist::sortedgetlength(){
	if (head){
		node *temp = head->next;
		int counter = 1;
		while (temp)//keeps going until end
		{
			temp = temp->next; counter++;
		}
		return counter;
	}
	return 0;
}
bool linkedlist::sortedfind(int k, int&x){ //check for k
	if (head){ //checks if exist
		node*temp = head;
		for (int i = 1; i < k; i++)//Going thru list
			temp = temp->next;
		x = temp->data;//Setting the value of x to the value of element K
		cout << "The element " << k << " has the value of " << x;
		return true;
	}
	else{
		cout << "There is no current value in this list. :(";
		return false;
	}

}
int linkedlist::sortedsearch(int key){//Return the position of the element with the value of key
	if (head){ //exist
		int i = 1;
		if (key == head->data) //if the head holds the value of key, return 1
			cout << "The element with the value of " << key << " is the first element.\n ";
		else{
			i++;//i for counter
			node*temp = head->next;
			do{//do while goes at least once
				if (temp->data != key){//If temp data!=key, keep going
					i++; temp = temp->next; //Temp moves thru
				}
				else if (temp->data == key){//If temp data equals key, then return the counter
					cout << "The element with the value of " << key << " is the element number " << i << "." << endl;
					return i;
				}

			} while (temp);

			cout << "There is no element with the value of " << key << endl;//This will display if failure
			return 0;
		}
	}
	else{ //This will display if the list is empty
		cout << "List is empty :( \n";
		return 0;
	}

}
void linkedlist::sortedinsert(int x){//insert a node with the value of x in the correct area
	node*newnode = new node; //birth of a node
	newnode->data = x; //new node data = x
	if (head == 0 || head->data >= newnode->data){//new leader
		newnode->next = head; //set newnode next = head
		head = newnode; //head = newnode
	}
	else{
		node*temp = head;
		while (temp->next != 0 && temp->next->data < newnode->data)
			temp = temp->next; //Moves temp thru list
		newnode->next = temp->next; //Newnodes next is set to be equal to temps next
		temp->next = newnode; //Newnode is set as temp nexts node
	}

}
void linkedlist::sorteddelete(int k, int &x, bool& success){//Delete the Kth element
	node* temp = head; 	node*pre = head;
	if (temp && temp->data == k){ //If temp does not equal zero, and the data for temp equals K, delete temp
		head = temp->next;   //head becomes the next 
		delete temp;         //Delete the temp node      
		return;
	}
	while (temp && temp->data != k){
		pre = temp;
		temp = temp->next; //Move temp through the list
	}
	if (!temp){ //If temp hit end w/o Kth value, fail
		cout << "That value does not exist in the list";
		return;//go back
	}
	pre->next = temp->next;
	delete temp; //Delete temp
}
void linkedlist::print(){
	cout << "Current list:" << endl;
	if (!head) //if there isn't head
		cout << "There are no current values within this list :(";
	else{
		struct node *temp = head;
		while (temp){//keeps going until !temp
			cout << temp->data << " ";//Display the data value of the node that temp is currently in
			temp = temp->next; //Moves themp through the list
		}
	}

}
linkedlist::~linkedlist(){ //Deletes all the nodes in the list
	node*temp;
	while (head){
		temp = head;
		head = head->next;
		delete temp; //goes thru list until !head, kills all nodes
	}
}


void allthethings(){
	int x, k, ans;
	bool empty;
	cout << "Part 1:" << endl;
	do{
		cout << endl << "Enter number you wish to insert: \n";	cin >> k;
		linklist.sortedinsert(k);
		cout << endl << "Insert more?\n[1] MORE [2] CONTINUE" << endl; cin >> ans;
	} while (ans == 1);
	cout << endl << "Part 2:" << endl;

	do{
		cout << endl << "Enter the number you wish to delete from the list: \n";
		cin >> k;
		empty = linklist.sortedisempty();
		linklist.sorteddelete(k, x, empty);
		cout << endl << "Delete more?\n[1] MORE [2] CONTINUE" << endl; cin >> ans;
	} while (ans == 1);
	cout << endl << "Part 3:" << endl;
	linklist.print();

	cout << endl << "Part 4:" << endl;

	do{
		cout << "Please enter number you wish to find in the list: ";
		cin >> k;
		linklist.sortedsearch(k);
		cout << endl << "Search more?\n[1] MORE [2] CONTINUE" << endl; cin >> ans;
	} while (ans == 1);

	cout << endl << "Part 5" << endl;

	do{
		cout << "Please enter the number of the element you wish to find the value of:\n ";	cin >> k;
		linklist.sortedfind(k, x);
		cout << endl << "Again?\n[1] MORE [2] CONTINUE" << endl; cin >> ans;
	} while (ans == 1);

	cout << endl << "Part 6: The length of the list is currently: " << linklist.sortedgetlength();
	system("pause"); exit(0);
}
void menu(){
	int x, k, ans; bool empty;
	system("cls");
	cout << "Input a number corresponding to the choice:\n[1]INSERT ITEM\t[2]DELETE ITEM\n[3]PRINT LIST\t[4]SEARCH \n[5]FIND ELEMENT\t[6]GET LENGTH \n[7]EVERYTHING\t[8]END\n";
	cin >> ans;
	if (ans == 1){//INSERT
		cout << "Please enter the number you wish to insert: \n";	cin >> k;
		linklist.sortedinsert(k);
	}
	else if (ans == 2){//DELETE
		linklist.print();
		cout << endl << "Please enter the number you wish to delete from the list: \n";
		cin >> k;
		empty = linklist.sortedisempty();
		linklist.sorteddelete(k, x, empty);
	}
	else if (ans == 3)//Print
		linklist.print();
	else if (ans == 4){//SEARCH
		cout << "Please enter number you wish to find in the list: ";
		cin >> k;
		linklist.sortedsearch(k);
	}
	else if (ans == 5){//FIND
		cout << "Please enter the number of the element you wish to find the value of: ";	cin >> k;
		linklist.sortedfind(k, x);
	}
	else if (ans == 6)
		cout << "The length of the list is currently: " << linklist.sortedgetlength();
	else if (ans == 7)
		allthethings();
	else if (ans == 8)
		exit(1);
	else
		cout << "Error, what you have entered an invalid number";
	cout << endl; system("pause"); menu();
}
void main()
{
	cout << "LINKED LIST PROGRAM \nYou can test an individual function of this program or go through all of them at once." << endl;
	int a; cout << "[1] Go through every function" << endl << "[2] Pick a function" << endl;
	cin >> a;
	if (a == 1)
		allthethings();
	else
		menu();
}
