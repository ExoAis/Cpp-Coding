#include <iostream>
#include <vector>
using namespace std;


void twoWayMerge(int arr[], int l, int mid, int h) {
	int m = mid - l + 1; int n = h - mid;
	vector<int> left; vector<int> right;
	for (int i = 0; i < m; i++) {
		left.push_back(arr[l + i]);
	}
	for (int j = 0; j < n; j++) {
		right.push_back(arr[mid + j + 1]);
	}
	int leftIndex = 0; int rightIndex = 0;
	int mergedIndex = l;
	while (leftIndex < m && rightIndex < n) {
		if (left[leftIndex] <= right[rightIndex]) {
			arr[mergedIndex++] = left[leftIndex++];
		}
		else if (left[leftIndex] > right[rightIndex]) {
			arr[mergedIndex++] = right[rightIndex++];
		}
	}
	for (int z = leftIndex; z < left.size(); z++) {
		arr[mergedIndex++] = left[z];
	}
	for (int y = rightIndex; y < right.size(); y++) {
		arr[mergedIndex++] = right[y];
	}
	left.clear(); right.clear();
}
void mergeSort(int arr[], int l, int h) {
	if (l < h) {
		int mid = (l + h) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, h);
		twoWayMerge(arr, l, mid, h);
	}
}

int main() {
	int arr[9]{ 3, 7, 2, 9, 53, 78, 132, 77, 1 };
	int h = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, h - 1);
	for (int i = 0; i < h; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}