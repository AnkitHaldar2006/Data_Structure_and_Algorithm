# 🔁 Palindrome Checker — C++

> Uses the Two Pointer technique to check if a string reads the same forwards and backwards — in O(n/2) comparisons with O(1) space.

---

## 📌 What is a Palindrome?

A **palindrome** is a word, phrase, or sequence that reads the same forwards and backwards.

```
"madam"   →  m a d a m  →  reversed: m a d a m  ✅ Palindrome
"hello"   →  h e l l o  →  reversed: o l l e h  ❌ Not Palindrome
"racecar" →  r a c e c a r  →  same both ways  ✅ Palindrome
```

- **Time Complexity:** O(n)
- **Space Complexity:** O(1) — no extra string or array created
- **Technique Used:** Two Pointer (inward comparison)

---

## 🧠 How It Works

Instead of reversing the string and comparing, this solution uses two pointers — one starting from the **left** and one from the **right** — moving inward simultaneously. If any pair mismatches, it's not a palindrome.

```
Input: "madam"   (indices 0 to 4)

  left=0  right=4 →  str[0]='m'  str[4]='m'  → match ✅  →  move inward
  left=1  right=3 →  str[1]='a'  str[3]='a'  → match ✅  →  move inward
  left=2  right=2 →  left >= right            → STOP

  Result: Palindrome ✅
```

```
Input: "hello"   (indices 0 to 4)

  left=0  right=4 →  str[0]='h'  str[4]='o'  → MISMATCH ❌ → return false

  Result: Not Palindrome ❌
```

---

## 📂 Code

```cpp
#include <iostream>
using namespace std;

bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right])
            return false;    // Mismatch found — not a palindrome
        left++;
        right--;
    }
    return true;             // All pairs matched — it's a palindrome
}

int main() {
    string str = "madam";

    if (isPalindrome(str))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}
```

---

## ▶️ Output

```
Palindrome
```

---

## ⚙️ Function Breakdown

| Component | Description |
|-----------|-------------|
| `left = 0` | Pointer starting at the first character |
| `right = str.length() - 1` | Pointer starting at the last character |
| `while (left < right)` | Loop runs until both pointers meet or cross |
| `str[left] != str[right]` | If outer characters don't match → immediately return false |
| `left++; right--` | Move both pointers inward for the next comparison |
| `return true` | All pairs matched — string is a palindrome |

---

## 📊 Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| Time | O(n) | At most n/2 comparisons — both pointers meet in the middle |
| Space | O(1) | No reversed copy created; only two integer pointers used |

> This is more efficient than the naive approach of reversing the string (`str == reverse(str)`), which uses O(n) extra space.

---

## 🗺️ Visual — Two Pointer Movement

```
  "m  a  d  a  m"
   ↑           ↑     → match → move inward
   0           4

  "m  a  d  a  m"
      ↑     ↑        → match → move inward
      1     3

  "m  a  d  a  m"
         ↑            → left == right → STOP → Palindrome ✅
         2
```

---

## 🧪 Test Cases

| Input | Output | Reason |
|-------|--------|--------|
| `"madam"` | Palindrome | Reads same forwards and backwards |
| `"racecar"` | Palindrome | Classic palindrome |
| `"hello"` | Not Palindrome | `h` ≠ `o` on first check |
| `"a"` | Palindrome | Single character is always a palindrome |
| `""` | Palindrome | Empty string — loop never runs, returns true |
| `"abba"` | Palindrome | Even-length palindrome |
| `"abcd"` | Not Palindrome | `a` ≠ `d` on first check |

---

## ⚠️ Limitations of This Implementation

| Limitation | Example | Fix |
|------------|---------|-----|
| Case-sensitive | `"Madam"` → ❌ Not Palindrome | Convert to lowercase first: `tolower(c)` |
| Spaces not ignored | `"race car"` → ❌ Not Palindrome | Filter non-alphanumeric characters before checking |
| Punctuation not ignored | `"A man, a plan, a canal: Panama"` → ❌ | Strip all non-alpha chars before checking |

To handle all these, preprocess the string first:

```cpp
// Preprocessing for a robust palindrome check
string clean = "";
for (char c : str)
    if (isalnum(c)) clean += tolower(c);
// Then run isPalindrome(clean)
```

---

## 🛠️ Possible Extensions

- **Case-insensitive check** — convert both characters with `tolower()` before comparing
- **Ignore spaces & punctuation** — filter the string before passing to the function
- **Count palindromic substrings** — extend to find all substrings that are palindromes
- **Longest palindromic substring** — a classic DP/Two Pointer problem built on this foundation

---

## 🏷️ Topic

String → Two Pointer → Palindrome Checker

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)