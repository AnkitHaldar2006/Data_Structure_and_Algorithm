# 🔲 2D Linear Search — C++

> Extends the classic Linear Search to a 2D matrix — scans row by row, column by column, until the target is found or the entire grid is exhausted.

---

## 📌 What is 2D Linear Search?

2D Linear Search is a brute-force search algorithm that traverses every cell of a matrix in row-major order (left to right, top to bottom) comparing each element to the target key. It requires **no sorting** and works on any matrix.

- **Time Complexity:** O(n × m)
- **Space Complexity:** O(1)
- **Return Type:** `pair<int, int>` — `(row, column)` of the found element, or `(-1, -1)` if not present
- **Requirement:** None — works on any unsorted or sorted matrix

---

## 🧠 How It Works

```
Matrix (3 × 4):
  Col →    0    1    2    3
Row 0 → [  1,   5,   9,  11 ]
Row 1 → [ 14,  20,  21,  26 ]
Row 2 → [ 30,  34,  43,  50 ]

Target: 21

Scan order (row-major):
  (0,0)=1  → ✗
  (0,1)=5  → ✗
  (0,2)=9  → ✗
  (0,3)=11 → ✗
  (1,0)=14 → ✗
  (1,1)=20 → ✗
  (1,2)=21 → ✅  FOUND at (1, 2)
```

---

## 📂 Code

```cpp
#include <iostream>
using namespace std;



pair<int, int> linearSearch2D(int arr[][100], int n, int m, int key) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == key)
                return {i, j};   // row, column
        }
    }
    return {-1, -1};             // not found
}

int main() {
    int n = 3, m = 4;

    int arr[3][100] = {
        { 1,  5,  9, 11},
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
```

---

## ▶️ Output

```
Element found at (1, 2)
```

---

## ⚙️ Function Breakdown

| Component | Description |
|-----------|-------------|
| `int arr[][100]` | 2D array parameter — column size must be fixed at compile time in C++ |
| `int n, int m` | Number of rows and columns |
| `for (i) for (j)` | Nested loops traverse every cell in row-major order |
| `if (arr[i][j] == key)` | Compares current cell value to target |
| `return {i, j}` | Returns position as a `pair<int,int>` on match |
| `return {-1, -1}` | Signals element was not found anywhere in the matrix |

---

## 📊 Complexity Analysis

| Case | Time Complexity | Scenario |
|------|----------------|----------|
| Best | O(1) | Target is at cell (0, 0) |
| Average | O(n × m / 2) ≈ O(n × m) | Target is somewhere in the middle |
| Worst | O(n × m) | Target is the last cell or not present |
| Space | O(1) | No extra memory allocated |

---

## 🗺️ Visual Traversal

```
 ┌──────┬──────┬──────┬──────┐
 │   1  │   5  │   9  │  11  │  ← Row 0 scanned fully
 ├──────┼──────┼──────┼──────┤
 │  14  │  20  │ [21] │  26  │  ← Row 1: stops at col 2 ✅
 ├──────┼──────┼──────┼──────┤
 │  30  │  34  │  43  │  50  │  ← Row 2: never reached
 └──────┴──────┴──────┴──────┘

  Cells visited: 7 out of 12
```

---

## ⚖️ Comparison with Other 2D Search Approaches

| | 2D Linear Search | Row-wise Binary Search | Staircase Search |
|--|-----------------|----------------------|-----------------|
| Time (worst) | O(n × m) | O(n log m) | O(n + m) |
| Sorted matrix needed? | No | Yes (row-wise) | Yes (row + col sorted) |
| Complexity to implement | Simple | Medium | Medium |
| Best use case | Small / unsorted matrix | Row-sorted matrix | Fully sorted matrix |

---

## ✅ When to Use 2D Linear Search

**Use it when:**
- The matrix is small or unsorted
- A one-time search is needed (no repeated queries)
- Simplicity and correctness matter more than speed

**Avoid it when:**
- The matrix is large — consider Staircase Search O(n + m) for sorted matrices
- Repeated searches are needed — pre-processing or a hash map would be faster

---

## ⚠️ Things to Note

- The column size `arr[][100]` is **hardcoded** as required by C++ for 2D array parameters. For flexible sizes, use `vector<vector<int>>`.
- Returns only the **first occurrence** if duplicates exist in the matrix.
- The function uses `pair<int, int>` — a clean C++ way to return two values (row and column) together.

---

## 🏷️ Topic

Array → 2D Array → Searching → 2D Linear Search

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)