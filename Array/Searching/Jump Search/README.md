![Jump Search Banner](banner.svg)

# 🦘 Jump Search — C++

> An efficient searching algorithm that jumps ahead in fixed steps, then performs a linear scan — combining speed with simplicity.

---

## 📌 What is Jump Search?

Jump Search is a searching algorithm designed for **sorted arrays**. It works by jumping ahead by a fixed number of steps (√n) to find the block where the target might exist, then performing a **linear search** within that block.

It sits between Linear Search (O(n)) and Binary Search (O(log n)) in terms of speed, but unlike Binary Search, it moves in only **one direction** — making it useful in systems where backwards traversal is costly (e.g., magnetic tapes).

- **Time Complexity:** O(√n)
- **Space Complexity:** O(1)
- **Requirement:** Array must be **sorted** in ascending order

---

## 🧠 How It Works

```
Array:  [ 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 ]  →  n = 10
Target:   23
Step:     √10 ≈ 3

Step 1 → Jump to index 2  → arr[2]  = 8   → 8  < 23 → jump again
Step 2 → Jump to index 5  → arr[5]  = 23  → 23 ≥ 23 → STOP, search block [3..5]

Linear scan:
  i=3 → arr[3] = 12  ✗
  i=4 → arr[4] = 16  ✗
  i=5 → arr[5] = 23  ✅  FOUND at index 5
```

---

## 📂 Code

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int arr[], int n, int key) {
    int step = sqrt(n);   // Block size = √n
    int prev = 0;

    // Jump forward to find the right block
    while (arr[min(step, n) - 1] < key) {
        prev = step;
        step += sqrt(n);

        if (prev >= n)
            return -1;    // Element not in array
    }

    // Linear search within the identified block
    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == key)
            return i;
    }

    return -1; // Not found
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

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
```

---

## ▶️ Sample Run

```
Enter number of elements: 6
Enter sorted elements:
3 9 15 27 38 55
Enter element to search: 27
Element found at index: 3
```

```
Enter number of elements: 5
Enter sorted elements:
1 4 8 12 20
Enter element to search: 6
Element not found
```

---

## ⚙️ Function Breakdown

| Component | Description |
|-----------|-------------|
| `step = sqrt(n)` | Block size — optimal jump step is √n |
| `prev` | Tracks the start of the current block |
| `arr[min(step, n) - 1] < key` | Jump forward while the block's last element is less than key |
| `prev = step; step += sqrt(n)` | Advance to the next block |
| `if (prev >= n) return -1` | Guard clause — target is beyond the array |
| Linear `for` loop | Searches within the identified block `[prev, step)` |

---

## 📊 Complexity Analysis

| Case | Time Complexity | Explanation |
|------|----------------|-------------|
| Best | O(1) | Target is in the very first block |
| Average | O(√n) | Jumps √n blocks, then scans up to √n elements |
| Worst | O(√n) | Last block — maximum jumps + full block scan |
| Space | O(1) | No extra memory needed |

---

## ⚖️ Algorithm Comparison

| | Linear Search | Jump Search | Binary Search |
|--|--------------|-------------|---------------|
| Time (worst) | O(n) | O(√n) | O(log n) |
| Sorted needed? | No | Yes | Yes |
| Direction | Forward | Forward only | Both |
| Best use case | Small arrays | Large sorted arrays, tapes | Large sorted arrays |

---

## 🔑 Why √n as the Step Size?

The optimal block size is **√n** because:

- Number of jumps to reach the right block = **n / step**
- Elements scanned in the block = **step**
- Total operations = **n/step + step**

Minimizing this expression using calculus gives **step = √n**, which balances jumping and scanning perfectly.

---

## ⚠️ Things to Note

- The array **must be sorted** — Jump Search gives incorrect results on unsorted data.
- Uses **Variable Length Array (VLA)** `int arr[n]` — supported by GCC but not standard in C++. For portable code, prefer `vector<int>`.
- Jump Search is preferred over Binary Search when **backward jumps are expensive** (e.g., sequential access media).

---

## 🏷️ Topic

Array → Searching → Jump Search

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)