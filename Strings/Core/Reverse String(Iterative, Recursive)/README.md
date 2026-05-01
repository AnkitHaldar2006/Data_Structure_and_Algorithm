# 🔄 String Reversal — C++

> Two approaches to reversing a string — an **iterative** two-pointer swap and a **recursive** divide-and-conquer — both running in O(n) time with O(1) and O(n) space respectively.

---

## 📌 What Does This Program Do?

This program reverses a string using two classic techniques side by side:

- **Iterative** — uses two pointers moving inward, swapping characters until they meet in the middle
- **Recursive** — achieves the same result via recursive calls, each swapping the outermost pair before moving inward

```
Input:  "hello"
Output: "olleh"
```

---

## 📂 Code

```cpp
#include <iostream>
#include <string>
using namespace std;

// ── Method 1: Iterative ──────────────────────────────────────────
string reverseIterative(string str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
        swap(str[left], str[right]);
        left++;
        right--;
    }
    return str;
}

// ── Method 2: Recursive ──────────────────────────────────────────
void reverseRecursive(string &str, int left, int right) {
    if (left >= right) return;           // Base case — pointers met
    swap(str[left], str[right]);
    reverseRecursive(str, left + 1, right - 1);
}

int main() {
    string str = "hello";

    cout << "Original:          " << str << endl;
    cout << "Iterative Reverse: " << reverseIterative(str) << endl;

    reverseRecursive(str, 0, str.length() - 1);
    cout << "Recursive Reverse: " << str << endl;

    return 0;
}
```

---

## ▶️ Output

```
Original:          hello
Iterative Reverse: olleh
Recursive Reverse: olleh
```

---

## 🧠 How Each Method Works

### Method 1 — Iterative (Two Pointer)

```
str = "hello"   indices: 0='h'  1='e'  2='l'  3='l'  4='o'

  Step 1 → left=0, right=4 → swap('h','o') → "oellh" → left=1, right=3
  Step 2 → left=1, right=3 → swap('e','l') → "olleh" → left=2, right=2
  Step 3 → left=2 >= right=2 → STOP

  Result: "olleh" ✅
```

### Method 2 — Recursive

```
reverseRecursive("hello", 0, 4)
  swap(str[0], str[4]) → "oellh"
  reverseRecursive("oellh", 1, 3)
    swap(str[1], str[3]) → "olleh"
    reverseRecursive("olleh", 2, 2)
      left >= right → BASE CASE → return ✅

  Result: "olleh" ✅
```

---

## ⚙️ Function Breakdown

### `reverseIterative`

| Component | Description |
|-----------|-------------|
| `left = 0, right = str.length() - 1` | Two pointers — one at each end |
| `while (left < right)` | Loop runs until pointers meet or cross |
| `swap(str[left], str[right])` | Swaps the outermost unprocessed characters |
| `left++; right--` | Moves both pointers inward |
| `return str` | Returns a new reversed copy (original unchanged) |

### `reverseRecursive`

| Component | Description |
|-----------|-------------|
| `string &str` | Passed by reference — modifies the original string in-place |
| `if (left >= right) return` | Base case — pointers have met, string is fully reversed |
| `swap(str[left], str[right])` | Swaps the current outermost pair |
| `reverseRecursive(str, left+1, right-1)` | Recurses inward on the remaining substring |

---

## 📊 Complexity Analysis

| Method | Time | Space | Notes |
|--------|------|-------|-------|
| Iterative | O(n) | O(n) | O(n) for the returned copy; O(1) if done in-place |
| Recursive | O(n) | O(n) | O(n) call stack — one frame per recursive call |

> The iterative approach is generally preferred in production — it avoids stack overflow risk on very long strings and uses no call stack memory.

---

## 🗺️ Visual — Iterative Swap Steps

```
Initial:  [ h ] [ e ] [ l ] [ l ] [ o ]
           ↑                       ↑
          left                   right

Step 1:   [ o ] [ e ] [ l ] [ l ] [ h ]
                 ↑           ↑
                left        right

Step 2:   [ o ] [ l ] [ l ] [ e ] [ h ]
                       ↑
                  left=right → STOP

Final:    [ o ] [ l ] [ l ] [ e ] [ h ]   →  "olleh" ✅
```

---

## 🔍 Key Difference — Pass by Value vs Reference

```cpp
// Iterative — pass by VALUE → returns a new reversed string, original unchanged
string reverseIterative(string str)  { ... return str; }

// Recursive — pass by REFERENCE → modifies the original string directly
void reverseRecursive(string &str, int left, int right) { ... }
```

This is why in `main()`, after calling `reverseIterative(str)`, the variable `str` is still `"hello"` — and the recursive call then correctly reverses it to `"olleh"`.

---

## 🧪 Test Cases

| Input | Iterative Output | Recursive Output |
|-------|-----------------|-----------------|
| `"hello"` | `"olleh"` | `"olleh"` |
| `"madam"` | `"madam"` | `"madam"` (palindrome!) |
| `"a"` | `"a"` | `"a"` (single char) |
| `""` | `""` | `""` (empty — base case fires instantly) |
| `"ab"` | `"ba"` | `"ba"` (even length) |
| `"C++ rocks"` | `"skcor ++C"` | `"skcor ++C"` |

---

## ⚖️ Iterative vs Recursive — Which to Use?

| | Iterative | Recursive |
|--|-----------|-----------|
| Speed | Slightly faster | Slightly slower (function call overhead) |
| Stack usage | O(1) | O(n) — risk of stack overflow on huge strings |
| Readability | Clear and direct | Elegant, mirrors the problem definition |
| Interview preference | ✅ Usually preferred | Good for demonstrating recursion understanding |
| In-place? | Yes (if modified) | Yes (via reference) |

---

## 🛠️ Possible Extensions

- **Reverse words in a sentence** — split by spaces, reverse each word, then reverse the whole string
- **Reverse only alphabetic characters** — skip non-alpha chars while moving pointers
- **Check palindrome using reversal** — compare `str == reverseIterative(str)`
- **Using `std::reverse`** — the STL built-in: `reverse(str.begin(), str.end())`

---

## ⚠️ Things to Note

- The iterative function takes `str` by **value** — so it works on a copy and the original `str` in `main` remains `"hello"` until the recursive call modifies it.
- The recursive function has a **call stack depth of n/2** — for very long strings (millions of characters), this could cause a stack overflow. Always prefer iterative for production use.
- `swap()` is from `<algorithm>` but is also available via `<string>` and `<iostream>` on most compilers.

---

## 🏷️ Topic

String → Two Pointer → Reversal (Iterative & Recursive)

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)



