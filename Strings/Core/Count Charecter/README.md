# 🔤 Character Counter — C++

> Scans a string character by character and classifies every character into one of four categories — vowels, consonants, digits, or spaces.

---

## 📌 What Does This Program Do?

This program takes a string and counts the number of:

- **Vowels** — `a, e, i, o, u` (case-insensitive)
- **Consonants** — all other alphabetic characters
- **Digits** — `0` through `9`
- **Spaces** — whitespace characters

It uses C++ standard library functions (`isalpha`, `isdigit`, `isspace`, `tolower`) to classify each character cleanly in a single pass.

- **Time Complexity:** O(n) — one pass through the string
- **Space Complexity:** O(1) — only four counter variables used

---

## 🧠 How It Works

```
Input: "Hello World 123"

Character-by-character breakdown:

  Char │ Type        │ Category
  ─────┼─────────────┼──────────────
   H   │ alpha       │ Consonant    ✦
   e   │ alpha+vowel │ Vowel        ✦
   l   │ alpha       │ Consonant    ✦
   l   │ alpha       │ Consonant    ✦
   o   │ alpha+vowel │ Vowel        ✦
   ' ' │ space       │ Space        ✦
   W   │ alpha       │ Consonant    ✦
   o   │ alpha+vowel │ Vowel        ✦
   r   │ alpha       │ Consonant    ✦
   l   │ alpha       │ Consonant    ✦
   d   │ alpha       │ Consonant    ✦
   ' ' │ space       │ Space        ✦
   1   │ digit       │ Digit        ✦
   2   │ digit       │ Digit        ✦
   3   │ digit       │ Digit        ✦

Result → Vowels: 3 | Consonants: 7 | Digits: 3 | Spaces: 2
```

---

## 📂 Code

```cpp
#include <iostream>
using namespace std;

void countCharacters(string str) {
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;

    for (char c : str) {
        if (isalpha(c)) {
            char lower = tolower(c);              // Normalize to lowercase
            if (lower == 'a' || lower == 'e' ||
                lower == 'i' || lower == 'o' || lower == 'u')
                vowels++;
            else
                consonants++;
        }
        else if (isdigit(c))  digits++;
        else if (isspace(c))  spaces++;
        // All other characters (!, @, # etc.) are silently ignored
    }

    cout << "Vowels:     " << vowels     << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Digits:     " << digits     << endl;
    cout << "Spaces:     " << spaces     << endl;
}

int main() {
    string str = "Hello World 123";
    countCharacters(str);
    return 0;
}
```

---

## ▶️ Output

```
Vowels:     3
Consonants: 7
Digits:     3
Spaces:     2
```

---

## ⚙️ Function Breakdown

| Component | Description |
|-----------|-------------|
| `for (char c : str)` | Range-based for loop — iterates over every character in the string |
| `isalpha(c)` | Returns true if `c` is a letter (A–Z or a–z) |
| `tolower(c)` | Converts character to lowercase for case-insensitive vowel check |
| `isdigit(c)` | Returns true if `c` is a numeric digit (0–9) |
| `isspace(c)` | Returns true if `c` is a whitespace character (space, tab, newline) |
| Special chars (`!, @, #`) | Fall through all conditions silently — not counted anywhere |

---

## 📊 Complexity Analysis

| Metric | Value | Reason |
|--------|-------|--------|
| Time | O(n) | Single pass through every character |
| Space | O(1) | Only 4 integer counters regardless of input size |

---

## 🔍 Vowel Check Logic

```
tolower(c) converts 'H' → 'h', 'E' → 'e', etc.

Then checks against exactly 5 vowels:
  'a'  'e'  'i'  'o'  'u'

Any alpha character that is NOT one of these 5 → Consonant
```

This approach is case-insensitive — `'A'` and `'a'` are both counted as vowels.

---

## 🧪 Test Cases

| Input | Vowels | Consonants | Digits | Spaces |
|-------|--------|------------|--------|--------|
| `"Hello World 123"` | 3 | 7 | 3 | 2 |
| `"AEIOUaeiou"` | 10 | 0 | 0 | 0 |
| `"C++ 3.14"` | 0 | 1 | 3 | 1 |
| `"1234567890"` | 0 | 0 | 10 | 0 |
| `"   "` | 0 | 0 | 0 | 3 |
| `""` (empty) | 0 | 0 | 0 | 0 |

---

## 🛠️ Possible Extensions

- **Count special characters** — add an `else` branch to count `!`, `@`, `#`, etc.
- **Accept user input** — replace the hardcoded string with `getline(cin, str)`
- **Count total characters** — add a `total` counter or use `str.length()`
- **Most frequent character** — extend with a frequency array `int freq[256] = {}`
- **Return as struct** — instead of printing inside the function, return a struct with all four counts for reusability

---

## ⚠️ Things to Note

- `isalpha()`, `isdigit()`, and `isspace()` are from `<cctype>` — included implicitly via `<iostream>` on most compilers but for portability, add `#include <cctype>` explicitly.
- Special characters like `!`, `.`, `@`, `#` are **not counted** in any category — they are silently skipped.
- The function prints directly — for cleaner design in larger projects, consider returning results instead of printing inside the function.

---

## 🏷️ Topic

String → Character Classification → Character Counter

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)