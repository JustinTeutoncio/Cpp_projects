#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void insertion_sort(int a[], int p);
void selectionsort(int a[], int p);
void bubblesort(int a[], int n);
void mergesort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void quicksort(int arr[], int low, int high);

int steps = 0;//global variable to count steps
void main(){
	char l;
	do{
		steps = 0;//reset step counter
		system("cls");
		clock_t start, end;
		int n;
		srand(time(NULL));//seed randomness based on clock
		cout << "Please enter the N value (size of array to be sorted)\n";
		cin >> n;
		int*a = new int[n];
		string b;
		cout << "[1] ascending (0-n)\n[2] descending (n-0)\n[3] random" << endl;
		cin >> b;
		cout << "What sorting?\n[1]insert \n[2]select \n[3]bubble \n[4]merge \n[5]quick\n"; int q; cin >> q;
		if (b == "ascending" || b == "1"){
			for (int i = 1; i <= n; i++)
				a[i - 1] = i;//array from 1 to n
		}
		else if (b == "descending" || b == "2"){
			for (int i = 1; i <= n; i++)
				a[i - 1] = n - i + 1;//array from n to 1
		}
		else if (b == "random" || b == "3"){
			for (int i = 1; i <= n; i++)
				a[i - 1] = i;
			int x = rand() % n;
			for (int i = 0; i < n; i++){
				swap(a[i], a[x]);
				x = rand() % n;
			}

		}
		//before
		int show=0;
		cout << "Would you like to preview the arrays before and after the sorting?\nHigh N values will only show first 200 before and after.\n[1]Yes\n[2]No\n";
		cin >> show;
		if (show == 1){
			if (n < 200){
				for (int i = 0; i < n; i++)
					cout << a[i] << " ";
			}
			else{
				for (int i = 0; i < 200; i++)
					cout << a[i] << " ";
			}
			cout << endl;
			system("pause");
		}

		start = clock();
		if (q == 1)
			insertion_sort(a, n);
		if (q == 2)
			selectionsort(a, n);
		else if (q == 3)
			bubblesort(a, n);
		else if (q == 4)
			mergesort(a, 0, n - 1);
		else if (q == 5)
			quicksort(a, 0, n - 1);
		end = clock();

		if (show == 1){
			if (n < 200){
				for (int i = 0; i < n; i++)
					cout << a[i] << " ";
			}
			else{
				for (int i = 0; i < 200; i++)
					cout << a[i] << " ";
			}
			cout << endl;
			system("pause");
		}
		cout << "Process took " << (double(end - start) / CLOCKS_PER_SEC) << "seconds\n";
			cout << "Steps: " << steps << "\nRun a new sort? Y / N\n"; cin >> l;
			steps = 0;
		} while (l == 'Y' || l == 'y');
	}

void insertion_sort(int a[], int p){//p is size
	int j, temp;
	steps++; //for intitialization of int i
	for (int i = 0; i < p; i++){
		steps += 2;//i<p, i++
		j = i;
		steps++;//j=i
		while (j > 0 && a[j] < a[j - 1]){
			steps += 2;//j>0, a<[j]
			temp = a[j];//+1
			a[j] = a[j - 1];//+1
			a[j - 1] = temp;//+1
			j--;//+1
			steps += 4;
		}
	}
}
void selectionsort(int a[], int p){//p is size
	steps++;//iter=1
	for (int iter = 1; iter <= p - 1; iter++){
		steps += 2;//iter<=p, iter++
		int large = 0; steps++;//;arge=0
		steps++;//index=1
		for (int index = 1; index <= p - iter; index++){
			steps += 2;//index<p, index++
			steps++;//comp
			if (a[large] < a[index]){
				large = index;
				steps++;//large=index
			}
			swap(a[large], a[p - iter]); steps += 3;//swap is 3
		}
	}
}

void bubblesort(int a[], int n){
	steps++;//int i =1
	for (int i = 1; i <= n - 1; i++){
		steps += 2;//i<n, i++
		steps++;//index=1
		for (int index = 1; index <= n - i; index++){
			steps++;//a [index-1]> a[index]
			if (a[index - 1] > a[index]){
				swap(a[index - 1], a[index]);
				steps += 3;//swap is 3
			}
		}
	}
}

void merge(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	steps += 2;//2 assignments
	int* R = new int[n2]; //Temp arrays
	int *L = new int[n1];

	steps++;//i=0
	for (i = 0; i < n1; i++){ //Copies array data into the temp L array
		steps += 2;//i<n1, i++
		L[i] = arr[l + i];//+1
		steps++;
	}
	steps++;//j=0
	for (j = 0; j < n2; j++){ //Copies array data into temp R array
		steps += 2;//j<n2, j++
		R[j] = arr[m + 1 + j];//+1
		steps++;
	}
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	steps += 3;
	while (i < n1 && j < n2){
		steps += 2;//2 comp
		steps++;//1 comp below
		if (L[i] <= R[j]){
			arr[k] = L[i];
			i++;
			steps += 2;//arr[k]=l[i], i++
		}
		else{
			arr[k] = R[j];//+1
			j++;//+1
			steps += 2;
		}
		k++;		steps++;
	}
	/* Copy the remaining elements of L[], if there are any */
	while (i < n1){
		steps++;//comp
		arr[k] = L[i];//+1
		i++;//+1
		k++;//+1
		steps += 3;//+1
	}
	/* Copy the remaining elements of R[], if there are any */
	while (j < n2){
		steps++;//comp
		arr[k] = R[j];//+1
		j++;//+1
		k++;//+1
		steps += 3;//+3
	}
}

void mergesort(int arr[], int l, int r){
	if (l < r){//+1
		int m = l + (r - l) / 2;//+1		
		mergesort(arr, l, m);//+1		
		mergesort(arr, m + 1, r);//+1	
		merge(arr, l, m, r);//+1
		steps += 5;
	}
}

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];    // pivot is last element, to be put in its correct spot. everything greater is put to its right, smaller to left
	int i = (low - 1);  // Index of smaller element 
	steps += 3;
	for (int j = low; j <= high - 1; j++){
		// If current element is smaller than or equal to pivot 
		steps += 2;
		if (arr[j] <= pivot){
			steps += 2;
			i++;    // increment index of smaller element 
			swap(&arr[i], &arr[j]); steps += 3;
		}
	}
	swap(&arr[i + 1], &arr[high]); steps += 4;
	return (i + 1);
}

void quicksort(int arr[], int low, int high){//low is start index, high is end
	if (low < high){
		int p = partition(arr, low, high);
		//Sort elements before and after partition 
		quicksort(arr, low, p - 1);
		quicksort(arr, p + 1, high);
		steps += 4;//comparison, assignment, 2 function calls
	}
}