#include <iostream>
using namespace std;

pair<int, int> linearSearch2D(int arr[][100], int n, int m, int key) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == key) {
                return {i, j}; // row, column
            }
        }
    }
    return {-1, -1}; // not found
}

int main() {
    int n = 3, m = 4;

    int arr[3][100] = {
        {1, 5, 9, 11},
        {14, 20, 21, 26},
        {30, 34, 43, 50}
    };

    int key = 21;

    pair<int, int> result = linearSearch2D(arr, n, m, key);

    if (result.first != -1)
        cout << "Element found at (" << result.first << ", " << result.second << ")\n";
    else
        cout << "Element not found\n";

    return 0;
}