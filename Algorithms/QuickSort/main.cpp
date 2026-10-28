#include <iostream>
using namespace std;

int partition(int arr[], int l, int h) {
	int pivot = arr[l];
	int i = l; int j = h;
	while (i < j) {
		do {
			i++;
		} while (arr[i] <= pivot && i < h);
		do {
			j--;
		} while (arr[j] > pivot && i <= j);
		if (i < j) {
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[l], arr[j]);
	return j;
}
void quickSort(int arr[], int l, int h) {
	if (l < h) {
		int boundary = partition(arr, l, h);
		quickSort(arr, l, boundary);
		quickSort(arr, boundary + 1, h);
	}
}

int main() {
	int arr[] {5, 4, 3, 2, 1};
	int h = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, h);
	for (auto i : arr) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}