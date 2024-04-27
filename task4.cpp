#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void rearrange(int arr[], int start, int end, int k) {
    if (start >= end) return; // Base case

    int partitionIndex = start; 

    
    for (int i = start; i < end; i++) {
        if (arr[i] <= k) {
            swap(arr[i], arr[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(arr[partitionIndex], arr[end]); // Placeing the end element at its correct position

    // Recursively arrange the left part if it contains elements <= k
    if (partitionIndex > start && arr[partitionIndex - 1] <= k)
        rearrange(arr, start, partitionIndex - 1, k);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 4, 6, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 5;

    cout << "Original Array: ";
    printArray(arr, size);

    rearrange(arr, 0, size - 1, k); 
    cout << "Rearranged Array: ";
    printArray(arr, size);

    return 0;
}
