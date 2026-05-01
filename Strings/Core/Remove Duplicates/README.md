# 🧹 Remove Duplicate Characters — C++

> Uses an `unordered_set` as a lookup table to filter out repeated characters from a string in a single O(n) pass — preserving the original order of first appearances.

---

## 📌 What Does This Program Do?

This program removes all **duplicate characters** from a string, keeping only the **first occurrence** of each character while maintaining the original order.

```
Input:  "programming"
Output: "progamin"
```

- **Time Complexity:** O(n) — single pass through the string
- **Space Complexity:** O(k) — where `k` is the number of unique characters (at most 26 for lowercase English letters)
- **Data Structure Used:** `unordered_set<char>` for O(1) average-time lookup

---

## 🧠 How It Works

```
Input: "programming"

  Char │ In set? │ Action          │ result       │ seen
  ─────┼─────────┼─────────────────┼──────────────┼──────────────
   p   │   No    │ Add → keep      │ "p"          │ {p}
   r   │   No    │ Add → keep      │ "pr"         │ {p,r}
   o   │   No    │ Add → keep      │ "pro"        │ {p,r,o}
   g   │   No    │ Add → keep      │ "prog"       │ {p,r,o,g}
   r   │   Yes   │ Skip            │ "prog"       │ {p,r,o,g}
   a   │   No    │ Add → keep      │ "proga"      │ {p,r,o,g,a}
   m   │   No    │ Add → keep      │ "progam"     │ {p,r,o,g,a,m}
   m   │   Yes   │ Skip            │ "progam"     │ {p,r,o,g,a,m}
   i   │   No    │ Add → keep      │ "progami"    │ {p,r,o,g,a,m,i}
   n   │   No    │ Add → keep      │ "progamin"   │ {p,r,o,g,a,m,i,n}
   g   │   Yes   │ Skip            │ "progamin"   │ {p,r,o,g,a,m,i,n}

Output: "progamin"
```

---

## 📂 Code

```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

string removeDuplicates(string str) {
    unordered_set<char> seen;   // Tracks characters already encountered
    string result = "";

    for (char c : str) {
        if (seen.find(c) == seen.end()) {  // Character seen for the first time
            result += c;                   // Keep it
            seen.insert(c);                // Mark as seen
        }
        // Duplicate → silently skip
    }
    return result;
}

int main() {
    string str = "programming";

    cout << "After removing duplicates: "
         << removeDuplicates(str) << endl;

    return 0;
}
```

---

## ▶️ Output

```
After removing duplicates: progamin
```

---

## ⚙️ Function Breakdown

| Component | Description |
|-----------|-------------|
| `unordered_set<char> seen` | Hash set storing characters already encountered — O(1) average lookup |
| `string result = ""` | Builds the output string with only first occurrences |
| `for (char c : str)` | Range-based loop iterating through every character |
| `seen.find(c) == seen.end()` | Returns true if `c` is NOT yet in the set (first occurrence) |
| `result += c` | Appends the character to the output string |
| `seen.insert(c)` | Marks the character as seen so future duplicates are skipped |

---

## 📊 Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| Time | O(n) | Each character is looked up and inserted into the set at most once |
| Space | O(k) | Set holds at most `k` unique characters — O(26) = O(1) for lowercase letters |

> `unordered_set` operations (`find`, `insert`) run in **O(1) average time** due to hashing, making the overall solution linear.

---

## 🔍 Why `unordered_set` over `set`?

| | `unordered_set` | `set` |
|--|----------------|-------|
| Lookup time | O(1) average | O(log k) |
| Insert time | O(1) average | O(log k) |
| Ordered? | No (irrelevant here) | Yes |
| Best for this task? | ✅ Yes | Works but slower |

Since we only care about **membership** (seen or not seen), `unordered_set` is the right tool — ordering doesn't matter.

---

## 🧪 Test Cases

| Input | Output | Notes |
|-------|--------|-------|
| `"programming"` | `"progamin"` | 3 duplicates removed (`r`, `m`, `g`) |
| `"aabbcc"` | `"abc"` | All chars duplicated |
| `"abcdef"` | `"abcdef"` | No duplicates — output = input |
| `"aaaa"` | `"a"` | All same character |
| `"aAbBcC"` | `"aAbBcC"` | Case-sensitive — `'a'` ≠ `'A'` |
| `""` | `""` | Empty string — loop never runs |
| `"Hello World"` | `"Helo Wrd"` | Space treated as a character too |

---

## ⚠️ Things to Note

- **Case-sensitive** — `'a'` and `'A'` are treated as different characters. Add `tolower(c)` if case-insensitive deduplication is needed.
- **Order preserved** — the first occurrence of each character always appears in its original position in the result.
- **Space is a character** — whitespace is subject to deduplication just like any letter.
- **`seen.find(c) == seen.end()`** can also be written as **`!seen.count(c)`** — both are equivalent and commonly used.

---

## 🛠️ Possible Extensions

- **Case-insensitive deduplication** — normalize with `tolower(c)` before the set check
- **Count removed duplicates** — track a `removed` counter to report how many chars were dropped
- **Preserve last occurrence instead of first** — iterate the string in reverse, then reverse the result
- **Apply to words in a sentence** — split by spaces and deduplicate each word separately
- **Boolean array alternative** — replace `unordered_set` with `bool seen[256] = {}` for slightly faster constant-time access with no hashing overhead

---

## 🏷️ Topic

String → Hashing → Remove Duplicate Characters

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)