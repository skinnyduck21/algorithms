#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int left, int right) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] >= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[right]);
    return i;
}

int quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left == right) return arr[left];

    int pivotIndex = partition(arr, left, right);

    if (pivotIndex == k) return arr[pivotIndex];
    else if (pivotIndex > k) return quickSelect(arr, left, pivotIndex - 1, k);
    else return quickSelect(arr, pivotIndex + 1, right, k);
}

int kthLargest(vector<int>& arr, int k) {
    return quickSelect(arr, 0, arr.size() - 1, k - 1);
}

int main() {
    vector<int> arr = {7, 2, 1, 10, 5};
    int k = 2;
    cout << "The " << k << "th largest element is " << kthLargest(arr, k) << endl;
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Partition function (descending order)
int partition(vector<int> &arr, int left, int right) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] >= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[right]);
    return i;
}

// Randomized partition
int randomPartition(vector<int> &arr, int left, int right) {
    int pivotIndex = left + rand() % (right - left + 1);
    swap(arr[pivotIndex], arr[right]); // Move random pivot to the end
    return partition(arr, left, right);
}

// QuickSelect to find kth largest
int quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left == right) return arr[left];

    int pivotIndex = randomPartition(arr, left, right);

    if (pivotIndex == k) return arr[pivotIndex];
    else if (pivotIndex > k) return quickSelect(arr, left, pivotIndex - 1, k);
    else return quickSelect(arr, pivotIndex + 1, right, k);
}

// Wrapper to find kth largest element
int kthLargest(vector<int>& arr, int k) {
    return quickSelect(arr, 0, arr.size() - 1, k - 1); // k-1 for 0-based indexing
}

int main() {
    srand(time(0)); // Seed RNG

    vector<int> arr = {7, 2, 1, 10, 5};
    int k = 2;
    cout << "The " << k << "th largest element is " << kthLargest(arr, k) << endl;
    return 0;
}

*/