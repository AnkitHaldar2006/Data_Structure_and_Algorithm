# 🔲 2D Binary Search — C++

> Treats a fully sorted 2D matrix as a flattened 1D array and applies classic Binary Search — achieving O(log(n × m)) with a clever index mapping trick.

---

## 📌 What is 2D Binary Search?

2D Binary Search is an optimized search algorithm for matrices where **every row is sorted** and the **first element of each row is greater than the last element of the previous row** — making the entire matrix equivalent to one sorted 1D array.

Instead of scanning every cell, it maps the 2D matrix to a virtual 1D array using index arithmetic, runs Binary Search on it, and converts the result back to `(row, col)`.

- **Time Complexity:** O(log(n × m))
- **Space Complexity:** O(1)
- **Requirement:** Matrix must be **fully sorted** row by row (row-continuous sorted order)

---

## 💡 The Core Trick — Index Mapping

The key insight is converting between 1D and 2D indices:

```
Matrix (n=3, m=3) treated as a 1D array of size n*m = 9:

  2D Matrix:              Virtual 1D array:
  [ 1,  3,  5 ]  →  idx: [ 0,  1,  2,  3,  4,  5,  6,  7,  8 ]
  [ 7,  9, 11 ]  →  val: [ 1,  3,  5,  7,  9, 11, 13, 15, 17 ]
  [13, 15, 17 ]

  1D index  →  2D index:
  mid = 4  →  row = 4 / 3 = 1,  col = 4 % 3 = 1  →  arr[1][1] = 9
```

---

## 🧠 How It Works

```
Matrix:           Target: 9
  [ 1,  3,  5 ]   n=3, m=3  →  virtual size = 9
  [ 7,  9, 11 ]   left=0, right=8
  [13, 15, 17 ]

Step 1 → left=0, right=8 → mid=4 → (4/3, 4%3) = (1,1) → arr[1][1]=9 == 9 → ✅ FOUND at (1, 1)
```

Another example — Target: 15

```
Step 1 → left=0, right=8 → mid=4 → arr[1][1]=9  < 15 → search right → left=5
Step 2 → left=5, right=8 → mid=6 → arr[2][0]=13 < 15 → search right → left=7
Step 3 → left=7, right=8 → mid=7 → arr[2][1]=15 == 15 → ✅ FOUND at (2, 1)
```

---

## 📂 Code

```cpp
#include <iostream>
using namespace std;

pair<int, int> binarySearch2D(int arr[][100], int n, int m, int key) {
    int left = 0;
    int right = n * m - 1;         // Treat matrix as 1D array

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Safe midpoint

        int row = mid / m;         // Convert 1D index → row
        int col = mid % m;         // Convert 1D index → column

        if (arr[row][col] == key)       return {row, col};   // Found
        else if (arr[row][col] < key)   left  = mid + 1;     // Search right half
        else                            right = mid - 1;     // Search left half
    }

    return {-1, -1};               // Not found
}

int main() {
    int n = 3, m = 3;

    int arr[3][100] = {
        { 1,  3,  5},
        { 7,  9, 11},
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
```

---

## ▶️ Output

```
Element found at (1, 1)
```

---

## ⚙️ Function Breakdown

| Component | Description |
|-----------|-------------|
| `left = 0, right = n*m - 1` | Treat the entire matrix as a virtual 1D array |
| `mid = left + (right - left) / 2` | Safe midpoint to avoid integer overflow |
| `row = mid / m` | Integer division gives the row index |
| `col = mid % m` | Modulo gives the column index |
| `arr[row][col] == key` | Target found — return `(row, col)` |
| `arr[row][col] < key` | Target is in the right half — move `left` up |
| `arr[row][col] > key` | Target is in the left half — move `right` down |
| `return {-1, -1}` | Target not found anywhere in the matrix |

---

## 📊 Complexity Analysis

| Case | Time Complexity | Scenario |
|------|----------------|----------|
| Best | O(1) | Target is at the midpoint on first check |
| Average | O(log(n × m)) | Target found after several halvings |
| Worst | O(log(n × m)) | Target at edge or not present |
| Space | O(1) | No extra memory used |

> For a 3×3 matrix: log(9) ≈ 3 steps maximum.
> For a 1000×1000 matrix: log(1,000,000) ≈ 20 steps — vs 1,000,000 for brute force.

---

## 🗺️ Visual — Index Mapping

```
Virtual 1D indices:
  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │  0  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │
  │  1  │  3  │  5  │  7  │  9  │ 11  │ 13  │ 15  │ 17  │
  └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘

Mapped back to 2D (m=3):
  idx 0 → (0,0)   idx 1 → (0,1)   idx 2 → (0,2)
  idx 3 → (1,0)   idx 4 → (1,1)   idx 5 → (1,2)
  idx 6 → (2,0)   idx 7 → (2,1)   idx 8 → (2,2)
```

---

## ⚖️ Comparison of 2D Search Approaches

| | 2D Linear Search | 2D Binary Search | Staircase Search |
|--|-----------------|-----------------|-----------------|
| Time (worst) | O(n × m) | O(log(n × m)) | O(n + m) |
| Sorted matrix needed? | No | Yes (row-continuous) | Yes (row + col sorted) |
| Index mapping trick? | No | Yes | No |
| Best use case | Small / unsorted matrix | Fully sorted matrix | Row & col sorted matrix |

---

## ✅ When to Use 2D Binary Search

**Use it when:**
- The matrix is sorted in row-continuous order (each row follows the last)
- Fast lookup is needed on a large matrix
- You want O(log(n × m)) performance with minimal code

**Avoid it when:**
- The matrix is unsorted — use 2D Linear Search instead
- Rows are sorted independently but the first element of row `i+1` is NOT greater than the last of row `i` — use Staircase Search instead

---

## ⚠️ Things to Note

- **Sorting requirement is strict** — this only works when the matrix behaves like a flattened sorted array. If `arr[i][m-1] > arr[i+1][0]` for any row, this algorithm will give wrong results.
- The column size `arr[][100]` is hardcoded — a C++ constraint for 2D array parameters. Use `vector<vector<int>>` for flexible sizing.
- Returns only the **first match** — but since the matrix is sorted, duplicates at different positions are still handled correctly.

---

## 🏷️ Topic

Array → 2D Array → Searching → 2D Binary Search

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)