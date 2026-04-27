# 🔍 Binary Search — C++

> A clean, iterative implementation of the Binary Search algorithm in C++.

---

## 📌 What is Binary Search?

Binary Search is a fast searching algorithm that works on **sorted arrays**. Instead of checking every element one by one, it repeatedly divides the search range in half — making it significantly faster than Linear Search for large datasets.

- **Time Complexity:** O(log n)
- **Space Complexity:** O(1) — iterative approach, no extra memory used
- **Requirement:** Array must be **sorted** in ascending order

---

## 🧠 How It Works

```
Array:  [ 1, 3, 5, 7, 9, 11 ]
Target:   7

Step 1 → left=0, right=5 → mid=2 → arr[2]=5  → 5 < 7  → search RIGHT half
Step 2 → left=3, right=5 → mid=4 → arr[4]=9  → 9 > 7  → search LEFT half
Step 3 → left=3, right=3 → mid=3 → arr[3]=7  → FOUND at index 3 ✅
```

---

## 📂 Code

```cpp
#include <iostream>
using namespace std;

int binarySearch(const int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids integer overflow

        if (arr[mid] == key)       return mid;      // Found
        else if (arr[mid] < key)   left = mid + 1;  // Search right half
        else                       right = mid - 1; // Search left half
    }

    return -1; // Not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int index = binarySearch(arr, n, key);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
```

---

## ▶️ Output

```
Element found at index: 3
```

---

## ⚙️ Function Breakdown

| Component | Description |
|-----------|-------------|
| `left`, `right` | Pointers that define the current search range |
| `mid = left + (right - left) / 2` | Safe midpoint — prevents integer overflow vs `(left + right) / 2` |
| `arr[mid] == key` | Target found, return index |
| `arr[mid] < key` | Target is in the right half, move `left` up |
| `arr[mid] > key` | Target is in the left half, move `right` down |
| `return -1` | Target not found in array |

---

## 📊 Complexity Analysis

| Case | Time Complexity | Explanation |
|------|----------------|-------------|
| Best | O(1) | Target is at the midpoint on first check |
| Average | O(log n) | Halves the search space each step |
| Worst | O(log n) | Target is at the edge or not present |
| Space | O(1) | Iterative — no recursion stack used |

---

## ⚖️ Binary Search vs Linear Search

| | Linear Search | Binary Search |
|--|--------------|---------------|
| Time (worst) | O(n) | O(log n) |
| Sorted array needed? | No | Yes |
| Works on linked lists? | Yes | No |
| Best for | Small / unsorted data | Large sorted arrays |

---

## 🔑 Key Insight — Why `left + (right - left) / 2`?

Using `(left + right) / 2` can cause **integer overflow** when both values are large. The safer formula `left + (right - left) / 2` gives the same result without the risk.

---

## 🏷️ Topic

Array → Searching → Binary Search

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)