

# 🔎 Linear Search — C++

> The simplest searching algorithm — scans every element one by one until the target is found or the array ends.

---

## 📌 What is Linear Search?

Linear Search is the most straightforward searching algorithm. It iterates through every element in the array **from left to right**, comparing each one to the target key. It requires **no sorting** and works on any type of array.

- **Time Complexity:** O(n)
- **Space Complexity:** O(1)
- **Requirement:** None — works on both sorted and unsorted arrays

---

## 🧠 How It Works

```
Array:  [ 4, 2, 9, 7, 5 ]
Target:   7

Step 1 → i=0 → arr[0] = 4  ≠ 7 → continue
Step 2 → i=1 → arr[1] = 2  ≠ 7 → continue
Step 3 → i=2 → arr[2] = 9  ≠ 7 → continue
Step 4 → i=3 → arr[3] = 7  == 7 → ✅ FOUND at index 3
```

---

## 📂 Code

```cpp
#include <iostream>
using namespace std;

// Function to perform Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;    // Return index if found
    }
    return -1;           // Return -1 if not found
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result = linearSearch(arr, n, key);

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
Enter number of elements: 5
Enter elements:
10 33 7 54 2
Enter element to search: 54
Element found at index: 3
```

```
Enter number of elements: 4
Enter elements:
1 8 15 22
Enter element to search: 9
Element not found
```

---

## ⚙️ Function Breakdown

| Component | Description |
|-----------|-------------|
| `for (int i = 0; i < n; i++)` | Iterates through every element from index 0 to n-1 |
| `if (arr[i] == key)` | Compares current element with the target |
| `return i` | Target found — returns its index immediately |
| `return -1` | Loop exhausted — target not present in array |

---

## 📊 Complexity Analysis

| Case | Time Complexity | Scenario |
|------|----------------|----------|
| Best | O(1) | Target is the very first element |
| Average | O(n/2) ≈ O(n) | Target is somewhere in the middle |
| Worst | O(n) | Target is the last element or not present |
| Space | O(1) | No extra memory used |

---

## ⚖️ Algorithm Comparison

| | Linear Search | Binary Search | Jump Search |
|--|--------------|---------------|-------------|
| Time (worst) | O(n) | O(log n) | O(√n) |
| Sorted array needed? | No | Yes | Yes |
| Works on linked lists? | Yes | No | No |
| Best use case | Small / unsorted data | Large sorted arrays | Large sorted arrays |

---

## ✅ When to Use Linear Search

**Use it when:**
- The array is small (n < 100 or so)
- The array is unsorted and sorting would be costly
- You're searching only once (no repeated queries)
- Working with linked lists or sequential access data

**Avoid it when:**
- The array is large and sorted — use Binary Search instead
- Performance is critical for repeated searches

---

## ⚠️ Things to Note

- Uses **Variable Length Array (VLA)** `int arr[n]` — supported by GCC but not standard C++. For portable code, use `vector<int> arr(n)`.
- Returns the **first occurrence** index if duplicates exist — does not find all matches.
- Despite being slow for large inputs, Linear Search is often the go-to for small or unordered datasets.

---

## 🏷️ Topic

Array → Searching → Linear Search

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)
