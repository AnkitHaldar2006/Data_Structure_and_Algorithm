#include <iostream>
#include <cmath>
using namespace std;

// Function to perform Jump Search
int jumpSearch(int arr[], int n, int key) {
    // Step size = √n
    int step = sqrt(n);
    int prev = 0;

    // Finding the block where element may exist
    while (arr[min(step, n) - 1] < key) {
        prev = step;
        step += sqrt(n);

        if (prev >= n)
            return -1;
    }

    // Linear search within the block
    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == key)
            return i;
    }

    return -1;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result = jumpSearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}