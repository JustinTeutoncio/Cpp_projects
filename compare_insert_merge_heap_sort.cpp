//Justin Teutonico Lab 5 CSC 382
//Compare sort times for insert sort, merge sort, heap sort
#include<iostream>
#include<time.h>
using namespace std;
void Insertion(int A[], int n){
	int i, j, temp;
	for (i = 1; i < n; i++) {
		j = i;
		while (A[j] < A[j - 1]) { // swap 
			temp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = temp;
			j--;
		}
	}
}
void merge(int arr[], int l, int m, int r){
	int i, j, k; int n1 = m - l + 1;
	int n2 = r - m;
	int *L = new int[n1]; int *R = new int[n2];//temp arrays
	for (i = 0; i < n1; i++)//copy data to temp arrays
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr[l..r]
	i = j = 0; // Initial index of first and second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2){
		if (L[i] <= R[j]){
			arr[k] = L[i]; i++;
		}
		else{
			arr[k] = R[j]; j++;
		}
		k++;
	}
	// Copy the remaining elements of L[], if any
	while (i < n1)
	{
		arr[k] = L[i];
		i++; k++;
	}

	// Copy the remaining elements of R[], if any
	while (j < n2){
		arr[k] = R[j];
		j++; k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r){
	if (l < r){
		int m = l + (r - l) / 2;// Same as (l+r)/2, avoids overflow 
		// Sort first and second halves
		mergeSort(arr, l, m); mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void heapify(int arr[], int n, int i){
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2
	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;
	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;
	// If largest is not root
	if (largest != i){
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n){
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)	{
		// Move current root to end
		swap(arr[0], arr[i]);
		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

void beginprogram() {
	int inputsizes[6] = { 100, 1000, 10000, 50000, 100000, 200000 };//input sizes
	cout << "Welcome to the program. The time is measured in seconds.\nNote the larger input sizes may take some time.\n";
	time_t t1, t2, t3, t4;//create time variables
	system("pause");//will pause before starting
	cout << "Input size    Insert   Merge   Heap" << endl;
	for (int i = 0; i < 6; i++){
		int *b = new int[inputsizes[i]];//will hold the array
		int *b2 = new int[inputsizes[i]];//will be the copy 
		int *b3 = new int[inputsizes[i]];//additonal copy
		int temp = 0;
		for (int j = 0; j < inputsizes[i]; j++){
			temp = rand();//generates each number randomly
			b[j] = b2[j] = b3[j] = temp;//asigns the same number to all arrays
		}
		for (int j = 0; j < inputsizes[i]; j++)
			b2[j] = b[j];//copies all of b
		t1 = time(0);//time insert begins
		Insertion(b, inputsizes[i]);//b is getting sorted
		t2 = time(0);//time insert ends and merge immediately begins
		mergeSort(b2, 0, inputsizes[i] - 1);//b2 is getting sorted
		t3 = time(0);//time merge ends, heap starts
		heapSort(b3, inputsizes[i]);
		t4 = time(0);//heap sort finish
		cout << inputsizes[i] << " \t \t" << t2 - t1 << "s       " << t3 - t2 << "s      " << t4 - t3 << "s\n";
		delete[] b; delete[] b2; delete[] b3;//clear memory
	}
	cout << "Go again? Enter Y for yes or N for no.\n";
	char h; cin >> h;
	if (h != 'n' && h != 'N')
		beginprogram();
}
int main() {
	srand(time(NULL));//seeds randomness once
	beginprogram();//goes to the start of the program.
	return 0;
}
