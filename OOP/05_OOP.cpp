#include <iostream>
using namespace std;

// Function template for selection sort
template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Assume the minimum is the first element
        int minIndex = i;
        
        // Find the minimum element in unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first element
        if (minIndex != i) {
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function template to input the array
template <typename T>
void inputArray(T arr[], int n) {
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// Function template to output the array
template <typename T>
void outputArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Integer array sorting
    int intArr[5];
    int n = 5;
    
    cout << "Integer Array:" << endl;
    inputArray(intArr, n);
    
    selectionSort(intArr, n);
    
    cout << "Sorted Integer Array: ";
    outputArray(intArr, n);
    
    // Float array sorting
    float floatArr[5];
    
    cout << "\nFloat Array:" << endl;
    inputArray(floatArr, n);
    
    selectionSort(floatArr, n);
    
    cout << "Sorted Float Array: ";
    outputArray(floatArr, n);

    return 0;
}
