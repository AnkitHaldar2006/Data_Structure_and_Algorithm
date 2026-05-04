# 🔎 Search in Linked List — C++

> Walks the list node by node comparing each value to the target key — returning its 1-based position on a match or reporting not found after exhausting every node.

---

## 📌 What Does This Program Do?

This program performs a **linear search** on a singly linked list. It traverses from the head, checks each node's data against the target `key`, and reports the **1-based position** of the first match. If no match is found after visiting every node, it reports not found.

```
List:    head → [ 10 ] → [ 20 ] → [ 30 ] → NULL
Search:  key = 20
Result:  Element found at position: 2
```

- **Time Complexity:** O(n) — checks every node in the worst case
- **Space Complexity:** O(1) — only a traversal pointer and two variables used

---

## 📂 Code

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

int main() {
    // Build list: 10 → 20 → 30 → NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    int key = 20;
    Node* temp = head;
    int position = 1;
    bool found = false;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Element found at position: " << position << endl;
            found = true;
            break;               // Stop as soon as first match is found
        }
        temp = temp->next;       // Move to next node
        position++;              // Increment position counter
    }

    if (!found)
        cout << "Element not found" << endl;

    return 0;
}
```

---

## ▶️ Output

```
Element found at position: 2
```

---

## 🧠 How It Works — Step by Step

```
List: 10 → 20 → 30 → NULL     key = 20

Initial:
  temp     = node(10)
  position = 1
  found    = false

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Iteration 1  (temp = node(10), position = 1)

  temp->data = 10  ≠  20   →  no match
  temp     = node(20)
  position = 2

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
Iteration 2  (temp = node(20), position = 2)

  temp->data = 20  ==  20  →  MATCH ✅
  Print: "Element found at position: 2"
  found = true
  break  →  loop exits immediately

Result: Position 2  ✅
```

---

## 🗺️ Visual — Traversal Pointer Movement

```
  ┌────────────┐    ┌────────────┐    ┌────────────┐
  │  10 | next │──→ │  20 | next │──→ │  30 | NULL │
  └────────────┘    └────────────┘    └────────────┘
   ↑ temp(pos=1)
        10 ≠ 20 → move

  ┌────────────┐    ┌────────────┐    ┌────────────┐
  │  10 | next │──→ │  20 | next │──→ │  30 | NULL │
  └────────────┘    └────────────┘    └────────────┘
                     ↑ temp(pos=2)
                          20 == 20 → FOUND ✅ break
```

---

## ⚙️ Code Breakdown

| Line | Description |
|------|-------------|
| `Node* temp = head` | Traversal pointer — starts at the head |
| `int position = 1` | 1-based counter tracking current node's position |
| `bool found = false` | Flag to distinguish "found + broke out" from "loop exhausted" |
| `while (temp != NULL)` | Continue as long as there are unvisited nodes |
| `if (temp->data == key)` | Compare current node's data with the target |
| `found = true; break` | Record match and exit immediately — no need to check remaining nodes |
| `temp = temp->next` | Advance to the next node |
| `position++` | Increment position for the next iteration |
| `if (!found)` | If loop finished without a break — key was never matched |

---

## 📊 Complexity Analysis

| Case | Time | Scenario |
|------|------|----------|
| Best | O(1) | Key is at the head (position 1) |
| Average | O(n/2) ≈ O(n) | Key is somewhere in the middle |
| Worst | O(n) | Key is at the tail or not present |
| Space | O(1) | No extra data structure — only a pointer and two variables |

---

## 🧪 Test Cases

| List | key | Output |
|------|-----|--------|
| `10 → 20 → 30` | `20` | `Element found at position: 2` |
| `10 → 20 → 30` | `10` | `Element found at position: 1` |
| `10 → 20 → 30` | `30` | `Element found at position: 3` |
| `10 → 20 → 30` | `99` | `Element not found` |
| `10` (single node) | `10` | `Element found at position: 1` |
| `NULL` (empty) | `10` | `Element not found` |
| `10 → 10 → 20` | `10` | `Element found at position: 1` (returns **first** occurrence) |

---

## 🚨 Edge Cases

| Scenario | Behaviour | Safe? |
|----------|-----------|-------|
| Empty list (`head = NULL`) | `temp = NULL` immediately — loop never runs — prints "not found" | ✅ Safe |
| Key at position 1 | Match on first iteration — `break` exits immediately | ✅ Safe |
| Key not present | Loop runs to the end — `found` stays `false` — "not found" printed | ✅ Safe |
| Duplicate values | Returns position of the **first occurrence** only | ✅ By design |

---

## 🔍 Role of the `found` Flag

```cpp
// Without the flag — cannot distinguish why the loop ended:
while (temp != NULL) { ... break; }
// Did we break because we found it, or did temp reach NULL naturally?
// We can't tell! ❌

// With the flag — clear intent after the loop:
if (!found) cout << "Element not found" << endl;  // ✅
```

The `bool found` flag is the clean way to communicate between the loop body and the code after it.

---

## 🛠️ Possible Extensions

- **Return the node pointer** instead of just the position — useful for delete-by-value or update operations
- **Count all occurrences** — remove `break` and increment a counter on every match
- **Search by condition** — replace `temp->data == key` with any custom predicate (e.g., find first even number)
- **Return -1 on not found** — convert to a function returning `int position` or `-1`

Function version:

```cpp
int searchList(Node* head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key) return pos;
        head = head->next;
        pos++;
    }
    return -1;   // not found
}
```

---

## 🔗 Related Linked List Operations

| Operation | Time Complexity |
|-----------|----------------|
| **Search by Value** ← you are here | O(n) |
| Traversal / Print | O(n) |
| Insert at Beginning | O(1) |
| Delete from Beginning | O(1) |
| Find Middle (Slow & Fast) | O(n) |
| Reverse (Iterative) | O(n) |

---

## 🏷️ Topic

Linked List → Searching → Linear Search by Value

**Part of:** [Data_Structure_and_Algorithm](https://github.com/AnkitHaldar2006/Data_Structure_and_Algorithm)