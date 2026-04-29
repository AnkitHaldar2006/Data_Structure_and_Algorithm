#include <iostream>
using namespace std;


pair<int, int> binarySearch2D(int arr[][100], int n, int m, int key) {
    int left = 0;
    int right = n * m - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Convert 1D index to 2D index
        int row = mid / m;
        int col = mid % m;

        if (arr[row][col] == key) {
            return {row, col};
        }
        else if (arr[row][col] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return {-1, -1};
}

int main() {
    int n = 3, m = 3;

    int arr[3][100] = {
        {1, 3, 5},
        {7, 9, 11},
        {13, 15, 17}
    };

    int key = 9;

    pair<int, int> result = binarySearch2D(arr, n, m, key);

    if (result.first != -1)
        cout << "Element found at (" << result.first << ", " << result.second << ")\n";
    else
        cout << "Element not found\n";

    return 0;
}